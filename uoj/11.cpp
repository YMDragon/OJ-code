#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int N=100010;
struct edge{int s,t,d,n;}e[2*N];
int n,m,rt,ans,ansg,a[N],h[N],fa[N],s[N],mdep[N],g[N],pa[N],dis[N][2];

void dfs(int x,int f,int DIS,int op)
{
	dis[x][op]=DIS;
	for (int i=h[x]; i; i=e[i].n)
		if (e[i].t!=f)  dfs(e[i].t,x,DIS+e[i].d,op);
}

void dfs2(int x,int f,int DIS)
{
	fa[x]=f,mdep[x]=0,g[x]=1,s[x]=a[x];
	if (f==rt)  pa[x]=x;  else  pa[x]=pa[f];
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=f)
			dfs2(y,x,DIS+e[i].d),s[x]+=s[y];
	if (s[x])
		{
			mdep[x]=DIS;
			for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
				if (y!=f)
					{
						if (mdep[y]>mdep[x])  mdep[x]=mdep[y],g[x]=0;
						if (mdep[x]==mdep[y])  g[x]+=g[y];
					}
		}
			
}

void work()
{
	int u,v,Max,Max2;
	scanf("%d %d",&n,&m);
	for (int i=1,x; i<=m; i++)
		scanf("%d",&x),a[x]=1;
	for (int i=1,x,y,w,tot=0; i<n; i++)
		{
			scanf("%d %d %d",&x,&y,&w);
			e[++tot]=(edge){x,y,w,h[x]},h[x]=tot;
			e[++tot]=(edge){y,x,w,h[y]},h[y]=tot;
		}
	dfs(1,0,0,0),u=1;
	for (int i=2; i<=n; i++)  if (a[i])  u=(dis[u][0]<dis[i][0])?i:u;
	dfs(u,0,0,0),v=u-1;
	for (int i=1; i<=n; i++)  if (a[i])  v=(dis[v][0]<dis[i][0])?i:v;
	dfs(v,0,0,1),rt=-1;
	for (int i=1; i<=n; i++)
		if (dis[i][0]+dis[i][1]==dis[v][0])
			{
				if ((rt==-1)||(fabs(dis[i][0]-dis[i][1])<fabs(dis[rt][0]-dis[rt][1])))
					rt=i;
			}
	dfs2(rt,0,0),u=0,v=0,Max=Max2=0;
	for (int i=1; i<=n; i++)
		if ((fa[i]==rt)&&(s[i]))
			{
				if (mdep[i]>Max)  Max2=Max,v=u,Max=mdep[i],u=i;
				else  if (mdep[i]==Max)
					{if (Max2==Max)  {u=v=-1;  break;}  else  Max2=Max,v=u,Max=mdep[i],u=i;}
				else  if (mdep[i]>Max2)  Max2=mdep[i],v=i;
			}
	if (!a[rt])  ans=m,ansg=1;
	for (int i=1; i<=n; i++)
		if ((!a[i])&&(i!=rt))
			{
				int res=s[i];
				if ((s[i])&&(mdep[i]==mdep[pa[i]])&&(g[i]==g[pa[i]]))
					{
						if (pa[i]==u)
							{if (mdep[u]>mdep[v])  res+=m-s[u];  else  res+=s[v];}
						else  if (pa[i]==v)  res+=s[u];
					}
				if (res>ans)  ans=res,ansg=0;
				if (res==ans)  ansg++;
			}
	printf("%d %d",ans,ansg);
}

int main()
{
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);
	work();
	return 0;
}
