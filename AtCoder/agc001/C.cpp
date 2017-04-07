#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct edge{int s,t,n;}e[4010];
int n,k,h[2010],siz[2010],dep[2010],f[2010][2010],ans;

void upd(int &x,int y){if (x<y)  x=y;}

void dfs(int x,int fa)
{
	siz[x]=1,dep[x]=0,f[x][0]=1;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=fa)
			{
				dfs(y,x);
				for (int j=dep[x]; j>=0; j--)
					{
						int _=f[x][j];
						for (int l=dep[y]; l>=0; l--)
							if (j+l<k)  upd(f[x][max(j,l+1)],_+f[y][l]);
					}
				siz[x]+=siz[y],dep[x]=max(dep[x],dep[y]+1);
			}
	for (int i=0; i<=dep[x]; i++)  upd(ans,f[x][i]);
}

void work()
{
	scanf("%d %d",&n,&k);
	for (int i=1,u,v,tot=0; i<n; i++)
		{
			scanf("%d %d",&u,&v);
			e[++tot]=(edge){u,v,h[u]},h[u]=tot;
			e[++tot]=(edge){v,u,h[v]},h[v]=tot;
		}
	dfs(1,0);
	printf("%d",n-ans);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
