#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int n,q,a[100010],b[100010],f[100010][20],Log[100010];

int maxb(int x,int y){return b[x]>b[y]?x:y;}

LL solve(int l,int r)
{
	if (l>r)  return 0;
	int mid=maxb(f[l][Log[r-l+1]],f[r+1-(1<<Log[r-l+1])][Log[r-l+1]]);
	return solve(l,mid-1)+solve(mid+1,r)+1LL*b[mid]*(mid-l+1)*(r-mid+1);
}

void work()
{
	scanf("%d %d",&n,&q),Log[0]=-1;;
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	for (int i=1; i<n; i++)  b[i]=fabs(a[i]-a[i+1]),f[i][0]=i,Log[i]=Log[i/2]+1;
	n--;
	for (int j=1; j<20; j++)
		for (int i=1; i+(1<<(j-1))<=n; i++)
			f[i][j]=maxb(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	for (int i=1,l,r; i<=q; i++)
		{
			scanf("%d %d",&l,&r),r--;
			printf("%lld\n",solve(l,r));
		}
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
