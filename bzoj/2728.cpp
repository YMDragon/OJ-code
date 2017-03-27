#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
LL n,k,l,r,a[1010][65],b[65],f[65][2];

LL dfs(LL i,LL j,LL n)
{
	if (i<0)  return 1;
	if (f[i][j]!=-1)  return f[i][j];
	if (j==0)
		{
			if (b[i]==-1)  return f[i][j]=2*dfs(i-1,0,n);
			else  return f[i][j]=dfs(i-1,0,n);
		}else
		{
			if (n&(1LL<<i))
				{
					if (b[i]==-1)  return f[i][j]=dfs(i-1,0,n)+dfs(i-1,1,n);
					else  return f[i][j]=dfs(i-1,((n&(1LL<<b[i]))>0),n);
				}else
				{
					if (b[i]==-1)  return f[i][j]=dfs(i-1,1,n);
					else  return f[i][j]=(n&(1LL<<b[i]))?0:dfs(i-1,1,n);
				}
		}
}

LL solve(LL n)
{
	if (n<0)  return 0;
	for (int i=0; i<k; i++)
		f[i][0]=f[i][1]=-1;
	n=min(n,(1LL<<k)-1);
	return dfs(k-1,1,n);
}

void work()
{
	scanf("%lld %lld %lld %lld",&n,&k,&l,&r);
	for (int i=1; i<=n; i++)
		{
			scanf("%lld",&a[i][0]);
			for (int j=1; j<k; j++)
				a[i][j]=a[i][j-1]/2,a[i][j-1]&=1;
		}
	for (int i=0; i<k; i++)
		b[i]=-1;
	for (int i=k-1; i>=0; i--)
		for (int j=i-1; j>=0; j--)
			{
				int flag=1;
				for (int k=1; k<=n; k++)
					if (a[k][i]!=a[k][j])  {flag=0;  break;}
				if (flag)
					{if (b[j]==-1)  b[j]=i;  else  b[i]=b[j];}
			}
	printf("%lld",solve(r)-solve(l-1));
}

int main()
{
	freopen("2728.in","r",stdin);
	freopen("2728.out","w",stdout);
	work();
	return 0;
}
