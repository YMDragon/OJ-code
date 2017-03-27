#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#define oo  (1<<30)
using namespace std;

struct edge{int s,t,d,n,r;}e[700010];
int n,m,k,tot,h[100010],dis[100010],vis[100010],f[100010],ans;

int spfa(int s)
{
	int x,y,i,res=0;
	deque <int> Q;
	for (int i=1; i<=n; i++)  dis[i]=oo,vis[i]=0;
	Q.push_back(s),dis[s]=0,vis[s]=1;
	while (!Q.empty())
		for (i=h[x=Q.front()],Q.pop_front(),vis[x]=0;  y=e[i].t,i; i=e[i].n)
			if (dis[y]>dis[x]+e[i].d)
				{
					dis[y]=dis[x]+e[i].d,f[y]=i;
					if (!vis[y])
						{
							vis[y]=1;
							if ((!Q.empty())&&(dis[y]<dis[Q.front()]))  Q.push_front(y);
							else  Q.push_back(y);
						}
				}else
				if ((dis[y]==dis[x]+e[i].d)&&(e[f[y]].r))  f[y]=i;
	for (int i=2; i<=n; i++)  res+=e[f[i]].r;
	return res;
}

void work()
{
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1,u,v,x; i<=m; i++)
		{
			scanf("%d %d %d",&u,&v,&x);
			e[++tot]=(edge){u,v,x,h[u],0},h[u]=tot;
			e[++tot]=(edge){v,u,x,h[v],0},h[v]=tot;
		}
	for (int i=1,s,y; i<=k; i++)
		{
			scanf("%d %d",&s,&y);
			e[++tot]=(edge){1,s,y,h[1],1},h[1]=tot;
		}
	printf("%d",k-spfa(1));
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
