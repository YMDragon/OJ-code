#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
 
struct edge{int s,t,c,co,n,l;}e[30010];
int n,m,S,T,tot,h[10010],d[10010],vis[10010],f[10010],Q[2][10010];
 
void addedge(int s,int t,int c,int co)
{
	e[++tot]=(edge){s,t,c,co,h[s]},h[s]=tot,e[e[tot].n].l=tot;
}
 
bool spfa()
{
	int l[2]={1,1},r[2]={0,0},cnt=1,x,y,i;
	Q[cnt][++r[cnt]]=S,vis[S]=++tot;
	while (1)
		{
			while (l[cnt]<=r[cnt])
				for (i=h[x=Q[cnt][l[cnt]++]]; y=e[i].t,i; i=e[i].n)
					if ((e[i].c)&&(vis[y]!=tot))
						{
							if (e[i].co)  Q[cnt^1][++r[cnt^1]]=y;  else  Q[cnt][++r[cnt]]=y;
							vis[y]=tot,f[y]=i;
						}
					else  if (!e[i].c)
						{
							if (i==h[x])  h[x]=e[i].n;  else  e[e[i].l].n=e[i].n;
							if (e[i].n)  e[e[i].n].l=e[i].l;
						}
			if (vis[T]==tot)
				{
					for (i=l[cnt^1]; i<=r[cnt^1]; i++)  f[Q[cnt^1][i]]=0;
					return 1;
				}
			cnt^=1;
			if (l[cnt]>r[cnt])  return 0;
		}
	return 0;
}
 
int dfs(int x,int a)
{
	if ((x==T)||(a==0))  return a;
	int flow=0,t;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if ((e[i].c)&&((f[y]==i)||(y==T)))
			t=dfs(y,min(a,e[i].c)),flow+=t,a-=t,e[i].c-=t;
	return flow;
}
 
void work()
{
	scanf("%d %d",&n,&m),S=0,T=n+1,tot=1;
	for (int i=1,s,t,a,b; i<=n; i++)
		{
			scanf("%d %d %d %d",&s,&t,&a,&b),d[s]=-1;
			addedge(s,t,b-a,1),addedge(s,t,a,0);
		}
	for (int i=1; i<=n; i++)
		if (!d[i])  addedge(i,T,1<<30,0),d[i]=tot;
	tot=0;
	int maxflow=0,mincost=0;
	while (spfa())
		{
			int x=T,costsum=0,flow;
			for (; x!=S; x=e[f[x]].s)  costsum+=e[f[x]].co;
			if (costsum)  flow=(m-mincost)/costsum;  else  flow=1<<30;
			if (flow==0)  break;
			flow=dfs(S,flow),maxflow+=flow,mincost+=costsum*flow;
		}
	printf("%d",maxflow);
}
 
int main()
{
	freopen("2040.in","r",stdin);
	freopen("2040.out","w",stdout);
	work();
	return 0;
}
