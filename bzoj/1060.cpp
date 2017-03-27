#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
struct edge{int s,t,d,n;}e[1000010];
int n,s,h[500010];
LL d[500010],ans;

void dfs(int x,int f)
{
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=f)  dfs(y,x),d[x]=max(d[x],e[i].d+d[y]);
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=f)  ans+=d[x]-d[y]-e[i].d;
}

void work()
{
	scanf("%d %d",&n,&s);
	for (int i=1,u,v,w,tot=0; i<n; i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			e[++tot]=(edge){u,v,w,h[u]},h[u]=tot;
			e[++tot]=(edge){v,u,w,h[v]},h[v]=tot;
		}
	dfs(s,0);
	printf("%lld",ans);
}

int main()
{
	freopen("1060.in","r",stdin);
	freopen("1060.out","w",stdout);
	work();
	return 0;
}
