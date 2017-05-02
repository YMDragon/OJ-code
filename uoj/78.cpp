#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

struct edge{int s,t,c,n;}e[502010];
int nl,nr,m,tot=1,flow,S,T,h[1010],dis[1010],vis[1010];

void addedge(int s,int t,int c)
{
	e[++tot]=(edge){s,t,c,h[s]},h[s]=tot;
	e[++tot]=(edge){t,s,0,h[t]},h[t]=tot;
}

bool bfs(int s,int t)
{
	queue <int> Q;  int x,y,i;
	Q.push(t),vis[t]=++tot,dis[t]=0;
	while (!Q.empty())
		for (i=h[x=Q.front()],Q.pop(); y=e[i].t,i; i=e[i].n)
			if ((e[i^1].c)&&(vis[y]!=tot))
				{
					vis[y]=tot,dis[y]=dis[x]+1,Q.push(y);
					if (y==s)  return 1;
				}
	return 0;
}

int dfs(int x,int a)
{
	if ((x==T)||(a==0))  return a;
	int flow=0;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if ((e[i].c)&&(vis[y]==tot)&&(dis[y]+1==dis[x]))
			{
				int t=dfs(y,min(a,e[i].c));
				e[i].c-=t,e[i^1].c+=t,flow+=t,a-=t;
				if (!a)  return flow;
			}
	dis[x]=1<<30;
	return flow;
}

void work()
{
	scanf("%d %d %d",&nl,&nr,&m);
	for (int i=1,x,y; i<=m; i++)
		scanf("%d %d",&x,&y),addedge(x,y+nl,1);
	S=nl+nr+1,T=S+1;
	for (int i=1; i<=nl; i++)  addedge(S,i,1);
	for (int i=1; i<=nr; i++)  addedge(i+nl,T,1);
	while (bfs(S,T))  flow+=dfs(S,1<<30);
	printf("%d\n",flow);
	for (int i=1; i<=nl; i++)
		{
			int t=1;
			for (int j=h[i]; j; j=e[j].n)
				if ((e[j].c==0)&&(e[j].t!=S))  printf("%d ",e[j].t-nl),t=0;
			if (t)  printf("0 ");
		}
}

int main()
{
	freopen("78.in","r",stdin);
	freopen("78.out","w",stdout);
	work();
	return 0;
}
