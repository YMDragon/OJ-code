#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

const int oo=1<<30;
struct edge{int s,t,n;}e[200010];
struct node{int x,y,j,lca;}a[705],b[705];
int n,m1,m2,h[100010],f[100010][20],dep[100010],ans;

namespace maxflow{
	struct edge{int s,t,c,n;}e[1000000];
	int S,T,h[1410],vis[1410],dis[1410],tot;
	queue <int> Q;

	void addedge(int s,int t,int c)
	{
		e[++tot]=(edge){s,t,c,h[s]},h[s]=tot;
		e[++tot]=(edge){t,s,0,h[t]},h[t]=tot;
	}

	void ready()
	{
		S=m1+m2+1,T=m1+m2+2,tot=1;
	}

	bool BFS()
	{
		int x,y,i;
		while (!Q.empty())  Q.pop();
		Q.push(T),vis[T]=++tot,dis[T]=0;
		while (!Q.empty())
			for (i=h[x=Q.front()],Q.pop(); y=e[i].t,i; i=e[i].n)
				if ((e[i^1].c)&&(vis[y]!=tot))
					{
						vis[y]=tot,dis[y]=dis[x]+1,Q.push(y);
						if (y==S)  return 1;
					}
		return 0;
	}

	int DFS(int x,int a)
	{
		if ((x==T)||(!a))  return a;
		int flow=0;
		for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
			if ((e[i].c)&&(vis[y]==tot)&&(dis[x]==dis[y]+1))
				{
					int t=DFS(y,min(a,e[i].c));
					flow+=t,a-=t,e[i].c-=t,e[i^1].c+=t;
					if (!a)  return flow;
				}
		dis[x]=oo;
		return flow;
	}

	int maxflow()
	{
		int flow=0;  tot=0;
		while (BFS())  flow+=DFS(S,oo);
		return flow;
	}
};

void dfs(int x,int fa)
{
	f[x][0]=fa,dep[x]=dep[fa]+1;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=fa)  dfs(y,x);
}

int LCA(int x,int y)
{
	if (dep[x]>dep[y])  swap(x,y);
	for (int i=19; i>=0; i--)
		if (dep[f[y][i]]>=dep[x])  y=f[y][i];
	if (x==y)  return x;
	for (int i=19; i>=0; i--)
		if (f[x][i]!=f[y][i])  x=f[x][i],y=f[y][i];
	return f[x][0];
}

void work()
{
	scanf("%d %d %d",&n,&m1,&m2);
	for (int i=1,x,y,tot=0; i<n; i++)
		{
			scanf("%d %d",&x,&y);
			e[++tot]=(edge){x,y,h[x]},h[x]=tot;
			e[++tot]=(edge){y,x,h[y]},h[y]=tot;
		}
	dfs(1,0);
	for (int j=1; j<20; j++)
		for (int i=1; i<=n; i++)
			f[i][j]=f[f[i][j-1]][j-1];
	for (int i=1; i<=m1; i++)
		scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].j),a[i].lca=LCA(a[i].x,a[i].y);
	for (int i=1; i<=m2; i++)
		scanf("%d %d %d",&b[i].x,&b[i].y,&b[i].j),b[i].lca=LCA(b[i].x,b[i].y);
	maxflow::ready();
	for (int i=1; i<=m1; i++)  maxflow::addedge(maxflow::S,i,a[i].j),ans+=a[i].j;
	for (int i=1; i<=m2; i++)  maxflow::addedge(i+m1,maxflow::T,b[i].j),ans+=b[i].j;
	for (int i=1; i<=m1; i++)
		for (int j=1; j<=m2; j++)
			{
				int lca,tag=0;
				lca=LCA(a[i].x,b[j].x);
				if ((dep[lca]>=dep[a[i].lca])&&(dep[lca]>=dep[b[j].lca]))  tag=1;
				lca=LCA(a[i].x,b[j].y);
				if ((dep[lca]>=dep[a[i].lca])&&(dep[lca]>=dep[b[j].lca]))  tag=1;
				lca=LCA(a[i].y,b[j].x);
				if ((dep[lca]>=dep[a[i].lca])&&(dep[lca]>=dep[b[j].lca]))  tag=1;
				lca=LCA(a[i].y,b[j].y);
				if ((dep[lca]>=dep[a[i].lca])&&(dep[lca]>=dep[b[j].lca]))  tag=1;
				if (tag)  maxflow::addedge(i,j+m1,oo);
			}
	ans-=maxflow::maxflow();
	printf("%d",ans);
}

int main()
{
	freopen("TWOCOMP.in","r",stdin);
	freopen("TWOCOMP.out","w",stdout);
	work();
	return 0;
}
