#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

typedef int arr2[405][405];
const int oo=1<<25;
int n,val[405],a[405],b[405],f[405];
arr2 s,wu,wd,s2,vs,vwu,vwd,vs2;

int solve(int l,int r);

int solve2(int l,int r)
{
	if (vs2[l][r])  return s2[l][r];
	if (l>r)  return 0;
	vs2[l][r]=1,s2[l][r]=solve(l,r);
	for (int i=l; i<r; i++)
		s2[l][r]=max(s2[l][r],solve2(l,i)+solve2(i+1,r));
	return s2[l][r];
}

int worku(int l,int r)
{
	if (vwu[l][r])  return wu[l][r];
	if (l==r)  return 0;
	vwu[l][r]=1,wu[l][r]=-oo;
	for (int i=l; i<=r; i++)
		if (a[i]==a[l]+1)
			wu[l][r]=max(wu[l][r],worku(i,r)+solve2(l+1,i-1));
	return wu[l][r];
}

int workd(int l,int r)
{
	if (vwd[l][r])  return wd[l][r];
	if (l==r)  return 0;
	vwd[l][r]=1,wd[l][r]=-oo;
	for (int i=l; i<=r; i++)
		if (a[i]==a[r]+1)
			wd[l][r]=max(wd[l][r],workd(l,i)+solve2(i+1,r-1));
	return wd[l][r];
}

int solve(int l,int r)
{
	if (vs[l][r])  return s[l][r];
	vs[l][r]=1,s[l][r]=-oo;
	for (int i=l; i<=r; i++)
		if ((a[i]>=a[l])&&(a[i]>=a[r])&&(1+2*a[i]-a[l]-a[r]<=r-l+1))
			s[l][r]=max(s[l][r],b[1+2*a[i]-a[l]-a[r]]+worku(l,i)+workd(i,r));
	return s[l][r];
}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&val[i]);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	for (int i=1; i<=n; i++)
		{
			b[i]=val[i];
			for (int j=1; j<i; j++)
				b[i]=max(b[i],b[j]+b[i-j]);
		}
	for (int i=1; i<=n; i++)
		{
			f[i]=f[i-1];
			for (int j=1; j<=i; j++)
				f[i]=max(f[i],f[j-1]+solve(j,i));
		}
	printf("%d",f[n]);
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
