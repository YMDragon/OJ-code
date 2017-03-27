#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct edge{int s,t,n;}e[1010];
int n,m,tot,h[505],dfn[505],low[505],cut[505],s[505],c[505],f[505],g[505],ans;
unsigned long long p;

void clean()
{
	memset(h,0,sizeof(h));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(cut,0,sizeof(cut));
	memset(s,0,sizeof(s));
	memset(c,0,sizeof(c));
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	n=0,tot=0,ans=0,p=1;
}

void tarjan(int x,bool root)
{
	int p=0;
	dfn[x]=low[x]=++tot;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (!dfn[y])
			{
				tarjan(y,0);
				low[x]=min(low[x],low[y]);
				if (dfn[x]<=low[y])  p++;
			}else  low[x]=min(low[x],dfn[y]);
	if (((root)&&(p>1))||((!root)&&(p)))  cut[x]=1;
}

void dfs(int x)
{
	c[x]=tot,s[tot]++;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if ((!cut[y])&&(!c[y]))  dfs(y);
}

void work()
{
	clean();
	for (int i=1,x,y; i<=m; i++)
		{
			scanf("%d %d",&x,&y);
			e[++tot]=(edge){x,y,h[x]},h[x]=tot;
			e[++tot]=(edge){y,x,h[y]},h[y]=tot;
			n=max(n,max(x,y));
		}
	tot=0;
	for (int i=1; i<=n; i++)
		if (!dfn[i])  tarjan(i,1);
	tot=0;
	for (int i=1; i<=n; i++)
		if ((!cut[i])&&(!c[i]))  tot++,dfs(i);
	for (int i=1; i<=n; i++)
		if (cut[i])
			for (int j=h[i],y; y=e[j].t,j; j=e[j].n)
				if (g[c[y]]!=i)  f[c[y]]++,g[c[y]]=i;
	for (int i=1; i<=tot; i++)
		if (f[i]==1)  ans++,p*=s[i];
	if (ans==0)  printf("2 %d\n",n*(n-1)/2);
	else  printf("%d %lld\n",ans,p);
}

int main()
{
	freopen("2730.in","r",stdin);
	freopen("2730.out","w",stdout);
	int t=0;
	while (scanf("%d",&m),m)  printf("Case %d: ",++t),work();
	return 0;
} 
