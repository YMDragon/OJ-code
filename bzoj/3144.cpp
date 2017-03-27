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
int p,q,r,d,S,T,tot=1,h[100000],tim,vis[100000],lab[100000],tra[100000];

int node(int x,int y,int z){return (x-1)*p*q+(y-1)*q+z;}
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
	scanf("%d %d %d %d",&p,&q,&r,&d);
	for (int i=1,x; i<=r; i++)
		for (int j=1; j<=p; j++)
			for (int k=1; k<=q; k++)
				{
					scanf("%d",&x);
					addedge(node(i,j,k),node(i+1,j,k),x);
					if (i>d)
						{
							if (j>1)  addedge(node(i,j,k),node(i-d,j-1,k),oo);
							if (j<p)  addedge(node(i,j,k),node(i-d,j+1,k),oo);
							if (k>1)  addedge(node(i,j,k),node(i-d,j,k-1),oo);
							if (k<q)  addedge(node(i,j,k),node(i-d,j,k+1),oo);
						}
				}
	S=node(r+2,1,1),T=node(r+2,1,2);
	for (int i=1; i<=p; i++)
		for (int j=1; j<=q; j++)
			addedge(S,node(1,i,j),oo),addedge(node(r+1,i,j),T,oo);
	int maxflow=0;
	while (BFS())  maxflow+=DFS(S,oo);
	printf("%d",maxflow);
}

int main()
{
	freopen("3144.in","r",stdin);
	freopen("3144.out","w",stdout);
	work();
	return 0;
}
