#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
struct edge{int s,t,n;}e[40];
int n,m,h[20],E[20][20],b[20];
LL f[20][20],ans;

void dfs(int x,int fa)
{
	for (int i=1; i<=n; i++)  if (b[i])  f[x][i]=1;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=fa)
			{
				dfs(y,x);
				for (int j=1; j<=n; j++)
					if (b[j])
						{
							LL s=0;
							for (int k=1; k<=n; k++)
								if ((b[k])&&(E[j][k]))
									s+=f[y][k];
							f[x][j]*=s;
						}
			}
}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1,x,y; i<=m; i++)
		{
			scanf("%d %d",&x,&y);
			E[x][y]=E[y][x]=1;
		}
	for (int i=1; i<=n; i++)  E[i][i]=1;
	for (int i=1,x,y,tot=0; i<n; i++)
		{
			scanf("%d %d",&x,&y);
			e[++tot]=(edge){x,y,h[x]},h[x]=tot;
			e[++tot]=(edge){y,x,h[y]},h[y]=tot;
		}
	for (int i=1; i<(1<<n); i++)
		{
			int _=n;
			for (int j=1; j<=n; j++)
				if (i&(1<<(j-1)))  _--,b[j]=1;
				else  b[j]=0;
			dfs(1,0);
			for (int j=1; j<=n; j++)
				if (b[j])  ans+=f[1][j]*(_&1?-1:1);
		}
	printf("%lld",ans);
}

int main()
{
	freopen("185.in","r",stdin);
	freopen("185.out","w",stdout);
	work();
	return 0;
}
