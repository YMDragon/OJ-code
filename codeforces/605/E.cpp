#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,vis[1010];
double p[1010][1010],ans[1010],t[1010];

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			scanf("%lf",&p[i][j]),p[i][j]/=100;
	for (int i=1; i<n; i++)  ans[i]=1e20;
	for (;;)
		{
			int x=1;
			for (int i=1; i<=n; i++)  if ((!vis[i])&&(ans[i]<ans[x]))  x=i;
			if (x==1)  break;
			vis[x]=1;
			for (int i=1; i<=n; i++)
				if ((!vis[i])&&(p[i][x]>0))
					{
						if (ans[i]>=1e20)
							ans[i]=ans[x]+1/p[i][x],t[i]=1-p[i][x];
						else
							ans[i]=((1-t[i])*ans[i]+t[i]*p[i][x]*ans[x])/(1-t[i]*(1-p[i][x])),t[i]*=1-p[i][x];
					}
		}
	printf("%.10lf",ans[1]);
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
