#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxn=55000,maxm=155000,oo=(1<<30);
struct edge{int s,t,cap,next;}gra[2*maxm+10];

int n,m,head[maxn+10],vis[maxn+10],dl[maxn+10],lab[maxn+10],dll,dlr,S,T,tim,tot=1,sum;

void addedge(int s,int t,int cap)
{
	gra[++tot]=(edge){s,t,cap,head[s]},head[s]=tot;
	gra[++tot]=(edge){t,s,0,head[t]},head[t]=tot;
}

int bfs()
{
	dll=0,dlr=0,dl[++dlr]=T,vis[T]=++tim;
	while (dlr>dll)
	{
		int x=dl[++dll];
		for (int i=head[x]; i; i=gra[i].next)
			if ((gra[i^1].cap)&&(vis[gra[i].t]!=tim))
			{
				dl[++dlr]=gra[i].t,vis[gra[i].t]=tim,lab[gra[i].t]=lab[x]+1;
				if (gra[i].t==S)  return 1;
			}
	}
	return 0;
}

int dfs(int x,int a)
{
	int flow=0;
	if ((x==T)||(a==0))  return a;
	for (int i=head[x]; i; i=gra[i].next)
		if ((gra[i].cap)&&(vis[gra[i].t]==tim)&&(lab[gra[i].t]+1==lab[x]))
		{
			int t=dfs(gra[i].t,min(a,gra[i].cap));
			gra[i].cap-=t,gra[i^1].cap+=t,a-=t,flow+=t;
			if (a==0)  return flow;
		}
	lab[x]=oo;
	return flow;
}

void work()
{
	scanf("%d %d",&n,&m);
	S=0,T=n+m+1;
	int p,a,b,c;
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&p);
		addedge(S,i,p);
	}
	for (int i=1; i<=m; i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		addedge(i+n,T,c);
		addedge(a,i+n,oo);
		addedge(b,i+n,oo);
		sum+=c;
	}
	int flow=0;
	while (bfs())  flow+=dfs(S,oo);
	printf("%d",sum-flow);
}

int main()
{
	freopen("1497.in","r",stdin);
	freopen("1497.out","w",stdout);
	work();
	return 0;
} 
