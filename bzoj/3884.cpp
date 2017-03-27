#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int n=int(1e7);
int m,prime[700010],b[10000010],phi[10000010],t;

int ksm(int a,int b,int mo)
{
	int x=a;a=1;
	while (b)
		{
			if (b&1)  a=1LL*a*x%mo;
			x=1LL*x*x%mo,b>>=1;
		}
	return a;
}

int solve(int x)
{
	if (b[x]>=0)  return b[x];
	return b[x]=ksm(2,solve(phi[x])+phi[x],x);
}

void work()
{
	b[1]=1;
	for (int i=2; i<=n; i++)
		{
			if (!b[i])  prime[++m]=i,phi[i]=i-1;
			for (int j=1; j<=m; j++)
				{
					if (i*prime[j]>n)  break;
					b[i*prime[j]]=1;
					if (i%prime[j]==0)
						{
							phi[i*prime[j]]=phi[i]*prime[j];
							break;
						}else  phi[i*prime[j]]=phi[i]*phi[prime[j]];
				}
		}
	for (int i=1; i<=n; i++)  b[i]=-1;
	b[1]=0;
	scanf("%d",&t);
	for (int i=1,q; i<=t; i++)
		{
			scanf("%d",&q);
			printf("%d\n",solve(q));
		}
}

int main()
{
	freopen("3884.in","r",stdin);
	freopen("3884.out","w",stdout);
	work();
	return 0;
}
