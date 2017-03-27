#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
 
typedef long long  LL;
const int mo=1000000007;
map <LL,LL> M;
int n;
 
bool cmp(int x,int y){return x>y;}
 
LL hash(int n,int a[])
{
	LL res=n;  int b[11];
	memcpy(b,a,sizeof(b));
	sort(b+1,b+n+1,cmp);
	for (int i=1; i<=n; i++)
		res=res*28+b[i];
	return res;
}
 
LL dfs(int step,int n,int a[])
{
	if (a[n]>3*(n-step))  return -1;
	if (step==n)
		{
			if (n==1)  return 1;
			else
				{
					LL h=hash(n-1,a);
					if (M[h])  return M[h];
					return M[h]=dfs(1,n-1,a);
				}
		}
	LL res=0,tmp;
	if (a[n]>=3)
		{
			a[n]-=3;
			tmp=dfs(step+1,n,a);
			if (tmp!=-1)  res=(res+tmp)%mo;
			a[n]+=3;
		}
	if ((a[n])&&(a[step]))
		{
			a[n]--,a[step]--;
			tmp=dfs(step+1,n,a);
			if (tmp!=-1)  res=(res+tmp)%mo;
			a[n]++,a[step]++;
		}
	if (a[step]>=3)
		{
			a[step]-=3;
			tmp=dfs(step+1,n,a);
			if (tmp!=-1)  res=(res+tmp)%mo;
			a[step]+=3;
		}
	return res?res:-1;
}
 
void work()
{
	int a[11];
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	printf("%lld",dfs(1,n,a));
}
 
int main()
{
	freopen("3139.in","r",stdin);
	freopen("3139.out","w",stdout);
	work();
	return 0;
} 
