#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

const int oo=(1<<30);
struct edge{int s,t,c,n;}e[1000000];
int n,m,k,S,T,tot=1,h[100000],tim,vis[100000],lab[100000],tra[100000];

int node(int x,int y){return x+(y-1)*n;}

void addedge(int s,int t,int c)
{
	e[++tot]=(edge){s,t,c,h[s]},h[s]=tot;
	e[++tot]=(edge){t,s,0,h[t]},h[t]=tot;
}

int BFS()
{
	queue <int> Q;  int x,y,i;
	for (int i=1; i<=T; i++)  tra[i]=h[i];
	Q.push(T),vis[T]=++tim,lab[T]=0;
	while (!Q.empty())
		for (i=h[x=Q.front()],Q.pop(); y=e[i].t,i; i=e[i].n)
			if ((e[i^1].c)&&(vis[y]!=tim))
				{
					vis[y]=tim,lab[y]=lab[x]+1,Q.push(y);
					if (y==S)  return 1;
				}
	return 0;
}

int DFS(int x,int a)
{
	int flow=0,t,y;
	if (x==T)  return a;
	for (int &i=tra[x]; y=e[i].t,i; i=e[i].n)
		if ((e[i].c)&&(vis[y]==tim)&&(lab[y]+1==lab[x]))
			if ((t=DFS(y,min(a,e[i].c))))
				if (e[i].c-=t,e[i^1].c+=t,flow+=t,(a-=t)==0)  return flow;
	return flow;
}

void work()
{
	scanf("%d %d%d",&n,&m,&k);
	for (int i=1,x; i<=n; i++)
		for (int j=1; j<=m; j++)
			{
				scanf("%d",&x);
				addedge(node(i,j),node(i,j+1),x==-1?oo:100-x);
			}
	for (int i=1,x,y; i<=k; i++)
		{
			scanf("%d %d",&x,&y);
			for (int j=1; j<=m; j++)  addedge(node(x,j),node(y,j+1),oo);
		}
	S=node(1,m+2),T=node(2,m+2);
	for (int i=1; i<=n; i++)
		addedge(S,node(i,1),oo),addedge(node(i,m+1),T,oo);
	int maxflow=0;
	while (BFS())  maxflow+=DFS(S,oo);
	printf("%.2lf",100-1.0*maxflow/n);
}

int main()
{
	freopen("RIN.in","r",stdin);
	freopen("RIN.out","w",stdout);
	work();
	return 0;
}
