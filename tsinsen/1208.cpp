#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

struct edge{int s,t,c,n;}e[10010000];
int n,tot=1,S,T,a[1010],E[1010][1010],h[1010],ne[1010],vis[1010],dis[1010],ans;
queue <int> Q;

int getint()
{
	int w=0;  char ch=getchar();
	while ((ch<'0')||('9'<ch))  ch=getchar();
	while (('0'<=ch)&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return w;
}

void addedge(int s,int t,int c,int ty=0)
{
	e[++tot]=(edge){s,t,c,h[s]},h[s]=tot;
	if (!ty)  e[++tot]=(edge){t,s,0,h[t]},h[t]=tot;
	else  e[++tot]=(edge){t,s,c,h[t]},h[t]=tot;
}

bool BFS()
{
	while (!Q.empty())  Q.pop();
	int x,y,i;
	for (i=1; i<=T; i++)  ne[i]=h[i];
	Q.push(T),vis[T]=++tot,dis[T]=0;
	while (!Q.empty())
		for (i=h[x=Q.front()],Q.pop();  y=e[i].t,i; i=e[i].n)
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
	for (int &i=ne[x],y,t; y=e[i].t,i; i=e[i].n)
		if ((e[i].c)&&(vis[y]==tot)&&(dis[x]==dis[y]+1))
			if (t=DFS(y,min(a,e[i].c)),e[i].c-=t,e[i^1].c+=t,flow+=t,!(a-=t))
				return flow;
	dis[x]=1<<30;
	return flow;
}

void work()
{
	n=getint(),S=n+1,T=n+2;
	for (int i=1; i<=n; i++)  a[i]=getint();
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			E[i][j]=getint();
	for (int i=1,sum; i<=n; i++)
		{
			addedge(S,i,a[i]),sum=0;
			for (int j=1; j<=n; j++)  sum+=E[i][j];
			addedge(i,T,sum),ans+=sum;
			for (int j=i+1; j<=n; j++)  addedge(i,j,2*E[i][j],1);
		}
	while (BFS())  ans-=DFS(S,1<<30);
	printf("%d",ans);
}

int main()
{
	freopen("1208.in","r",stdin);
	freopen("1208.out","w",stdout);
	work();
	return 0;
}
