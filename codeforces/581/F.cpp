#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct edge{int s,t,n;}e[10010];
int n,h[5010],r[5010],siz[5010],f[5010][2][5010],nf[2][5010];

void upd(int &x,int y){if (x>y)  x=y;}

void dfs(int x,int fa)
{
	if (!e[h[x]].n)
		{
			siz[x]=1,f[x][0][1]=0,f[x][1][0]=0;
			return;
		}
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (e[i].t!=fa)
			{
				dfs(y,x);
				for (int j=0; j<=siz[x]+siz[y]; j++)  nf[0][j]=nf[1][j]=int(1e8);
				if (!siz[x])
					for (int q=0; q<=1; q++)
						for (int p=0; p<=1; p++)
							for (int j=0; j<=siz[y]; j++)
								upd(nf[q][j],f[y][p][j]+(q^p));
				else
					for (int q=0; q<=1; q++)
						for (int j=siz[x]; j>=0; j--)
							for (int p=0; p<=1; p++)
								for (int k=siz[y]; k>=0; k--)
									upd(nf[q][j+k],f[x][q][j]+f[y][p][k]+(q^p));
				siz[x]+=siz[y];
				for (int j=0; j<=siz[x]; j++)
					f[x][0][j]=nf[0][j],f[x][1][j]=nf[1][j];
			}
}

void work()
{
	scanf("%d",&n);
	for (int i=1,u,v,tot=0; i<n; i++)
		{
			scanf("%d %d",&u,&v),r[u]++,r[v]++;
			e[++tot]=(edge){u,v,h[u]},h[u]=tot;
			e[++tot]=(edge){v,u,h[v]},h[v]=tot;
		}
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			f[i][0][j]=f[i][1][j]=int(1e8);
	for (int i=1; i<=n; i++)
		if (r[i]!=1)  {dfs(i,0);  printf("%d",min(f[i][0][siz[i]/2],f[i][1][siz[i]/2]));  break;}
}

int main()
{
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
	work();
	return 0;
}
