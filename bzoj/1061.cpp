#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

const int oo=(1<<30);
struct edge{int s,t,cost,cap,n;}e[25000];
int n,m,h[1010],S,T,tot=1,a[1010],vis[1010],dis[1010],f[1010];
queue <int> Q;

void addedge(int s,int t,int cost,int cap)
{
	e[++tot]=(edge){s,t,cost,cap,h[s]},h[s]=tot;
	e[++tot]=(edge){t,s,-cost,0,h[t]},h[t]=tot;
}

int spfa()
{
	int x,y;
	for (int i=1; i<=n+3; i++)  vis[i]=0,dis[i]=oo,f[i]=0;
	Q.push(T),vis[T]=1,dis[T]=0,f[T]=1;
	while (!Q.empty())
		{
			x=Q.front(),Q.pop(),vis[x]=0;
			for (int i=h[x]; y=e[i].t,i; i=e[i].n)
				if ((e[i^1].cap>0)&&(dis[y]>dis[x]+e[i^1].cost))
					{
						dis[y]=dis[x]+e[i^1].cost,f[y]=i^1;
						if (!vis[y])  Q.push(y),vis[y]=1;
					}
		}
	return dis[S]!=oo;
}

int MCMF()
{
	int minflow,maxflow=0,mincost=0;
	while (spfa())
		{
			minflow=oo;
			for (int x=S; x!=T; x=e[f[x]].t)
				minflow=min(minflow,e[f[x]].cap);
			for (int x=S; x!=T; x=e[f[x]].t)
				{
					e[f[x]].cap-=minflow,e[f[x]^1].cap+=minflow;
					mincost+=minflow*e[f[x]].cost;
				}
			maxflow+=minflow;
		}
	return mincost;
}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for (int i=1,s,t,cost; i<=m; i++)
		{
			scanf("%d %d %d",&s,&t,&cost);
			addedge(s,t+1,cost,oo);
		}
	S=n+2,T=n+3;
	for (int i=1,t; i<=n+1; i++)
		{
			t=a[i]-a[i-1];
			if (t>0)  addedge(S,i,0,t);
			else  addedge(i,T,0,-t);
			if (i>1)  addedge(i,i-1,0,oo);
		}
	printf("%d",MCMF());
}

int main()
{
	freopen("1061.in","r",stdin);
	freopen("1061.out","w",stdout);
	work();
	return 0;
}
