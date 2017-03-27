#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

const int oo=(1<<30);
struct edge{int s,t,ns,nt;}e[200010];
int n,m,S,T,h[10010],h2[10010],ok[10010],vis[10010],dis[10010];

void bfs1(int s)
{
	queue <int> Q;  int x,y,i;
	Q.push(s),vis[s]=1;
	while (!Q.empty())
		for (i=h2[x=Q.front()],Q.pop(); y=e[i].s,i; i=e[i].nt)
			if (!vis[y])  Q.push(y),vis[y]=1;
}

int bfs2(int s,int t)
{
	if (!ok[s])  return -1;
	queue <int> Q;  int x,y,i;
	Q.push(s),vis[s]=1,dis[s]=0;
	while (!Q.empty())
		for (i=h[x=Q.front()],Q.pop(); y=e[i].t,i; i=e[i].ns)
			if ((ok[y])&&(!vis[y]))
				{
					Q.push(y),vis[y]=1,dis[y]=dis[x]+1;
					if (y==t)  return dis[t];
				}
	return -1;
}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1,u,v; i<=m; i++)
		scanf("%d %d",&u,&v),e[i]=(edge){u,v,h[u],h2[v]},h[u]=i,h2[v]=i;
	scanf("%d %d",&S,&T);
	bfs1(T);
	for (int i=1,t; t=1,i<=n; i++)
		{
			for (int j=h[i]; j&&t; j=e[j].ns)
				if (!vis[e[j].t])  t=0;
			if (t)  ok[i]=1;
			dis[i]=oo;
		}
	memset(vis,0,sizeof(vis));
	printf("%d",bfs2(S,T));
}

int main()
{
	freopen("19.in","r",stdin);
	freopen("19.out","w",stdout);
	work();
	return 0;
}
