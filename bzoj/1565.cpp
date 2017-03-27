#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

const int oo=(1<<30);
struct edge{int s,t,n;}e[400000];
struct edge1{int s,t,cap,n;}tra[800000];
struct node{int s,h,z,r,lab,vis,cur;}a[610];
int n,m,tot,tot1=1,S,T,ans;

void topsort()
{
	int y,i;queue <int> Q;
	for (int i=1; i<=n*m; i++)  if (!a[i].r)  Q.push(i),a[i].z=1;
	while (!Q.empty())
		for (i=a[Q.front()].h,Q.pop(); y=e[i].t,i; i=e[i].n)
			{
				a[y].r--;
				if (!a[y].r)  a[y].z=1,Q.push(y);
			}
}

void addedge(int s,int t,int cap)
{
	tra[++tot1]=(edge1){s,t,cap,a[s].h},a[s].h=tot1;
	tra[++tot1]=(edge1){t,s,0,a[t].h},a[t].h=tot1;
}

int BFS()
{
	int x,y,i;  queue <int> Q;
	for (int i=1; i<=n*m+2; i++)  a[i].lab=oo,a[i].cur=a[i].h;
	Q.push(T),a[T].vis=++tot,a[T].lab=0;
	while (!Q.empty())
		for (i=a[x=Q.front()].h,Q.pop(); y=tra[i].t,i; i=tra[i].n)
			if ((tra[i^1].cap>0)&&(a[y].vis!=tot))
				{
					a[y].vis=tot,a[y].lab=a[x].lab+1,Q.push(y);
					if (y==S)  return 1;
				}
	return 0;
}

int DFS(int x,int m)
{
	if (x==T)  return m;
	int flow=0;
	for (int &i=a[x].cur,y; y=tra[i].t,i; i=tra[i].n)
		if ((tra[i].cap>0)&&(a[y].vis==tot)&&(a[y].lab+1==a[x].lab))
			{
				int t=DFS(y,min(m,tra[i].cap));
				flow+=t,m-=t,tra[i].cap-=t,tra[i^1].cap+=t;
				if (m==0)  return flow;
			}
	return flow;
}

int P(int x,int y){return (x-1)*m+y;}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1,x,y,w; i<=n; i++)
		for (int j=1; x=P(i,j),j<=m; j++)
			{
				scanf("%d %d",&a[x].s,&w);
				for (int k=1,q,p; k<=w; k++)
					{
						scanf("%d %d",&q,&p),y=P(++q,++p);
						e[++tot]=(edge){x,y,a[x].h},a[x].h=tot,a[y].r++;
					}
				if (j!=1)  y=P(i,j-1),e[++tot]=(edge){x,y,a[x].h},a[x].h=tot,a[y].r++;
			}
	topsort();
	for (int i=1; i<=n*m; i++)  a[i].h=0;
	for (int i=1; i<=tot; i++)
		if ((a[e[i].s].z)&&(a[e[i].t].z))
			addedge(e[i].t,e[i].s,oo);
	S=n*m+1,T=n*m+2;
	for (int i=1; i<=n*m; i++)
		if (a[i].z)
			{if (a[i].s>0)  addedge(S,i,a[i].s),ans+=a[i].s;  else  addedge(i,T,-a[i].s);}
	tot=0;
	while (BFS())
		ans-=DFS(S,oo);
	printf("%d",ans);
}

int main()
{
	freopen("1565.in","r",stdin);
	freopen("1565.out","w",stdout);
	work();
	return 0;
}
