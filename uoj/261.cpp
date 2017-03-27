#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int N=100010;
struct edge{int s,t,n;}e[2*N],a[2*N],p[N];
int n,m,q,tot,h[N],w[N],dep[N],f[N][20],ans[N],H[N],val[N],s[2*N];

void dfs(int x,int fa)
{
	f[x][0]=fa,dep[x]=dep[fa]+1;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=fa)  dfs(y,x);
}

int LCA(int x,int y)
{
	if (dep[x]>dep[y])  swap(x,y);
	for (int i=19; i>=0; i--)
		if (dep[x]<=dep[f[y][i]])
			y=f[y][i];
	if (x==y)  return x;
	for (int i=19; i>=0; i--)
		if (f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}

void dfs2(int x)
{
	int p=s[val[x]];
	for (int i=H[x]; i; i=a[i].n)  s[a[i].t]+=a[i].s;
	for (int i=h[x]; i; i=e[i].n)  if (e[i].t!=f[x][0])  dfs2(e[i].t);
	ans[x]+=s[val[x]]-p;
}

void work()
{
	scanf("%d %d %d",&n,&m,&q);
	if (m!=n-1)  return;
	for (int i=1,u,v,tot=0; i<=m; i++)
		{
			scanf("%d %d",&u,&v);
			e[++tot]=(edge){u,v,h[u]},h[u]=tot;
			e[++tot]=(edge){v,u,h[v]},h[v]=tot;
		}
	for (int i=1; i<=n; i++)  scanf("%d",&w[i]);
	dfs(1,0);
	for (int j=1; j<20; j++)
		for (int i=1; i<=n; i++)
			f[i][j]=f[f[i][j-1]][j-1];
	for (int i=1,tot=0; i<=q; i++)
		{
			scanf("%d %d",&p[i].s,&p[i].t),p[i].n=LCA(p[i].s,p[i].t);
			a[++tot]=(edge){1,dep[p[i].s],H[p[i].s]},H[p[i].s]=tot;
			a[++tot]=(edge){-1,dep[p[i].s],H[f[p[i].n][0]]},H[f[p[i].n][0]]=tot;
		}
	for (int i=1; i<=n; i++)  val[i]=w[i]+dep[i];
	dfs2(1),dfs2(0);
	for (int i=0; i<=n; i++)  H[i]=0;
	for (int i=1,tot=0,v; i<=q; i++)
		{
			v=dep[p[i].s]-2*dep[p[i].n]+n;
			a[++tot]=(edge){1,v,H[p[i].t]},H[p[i].t]=tot;
			a[++tot]=(edge){-1,v,H[p[i].n]},H[p[i].n]=tot;
		}
	for (int i=1; i<=n; i++)  val[i]=w[i]-dep[i]+n;
	dfs2(1);
	for (int i=1; i<=n; i++)  printf("%d ",ans[i]);
}

int main()
{
	freopen("261.in","r",stdin);
	freopen("261.out","w",stdout);
	work();
	return 0;
}
