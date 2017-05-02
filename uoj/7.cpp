#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const int N=200010;
struct edge{int s,t,n;  LL d;}e[2*N];
int n,t,m,h[N],f[N],siz[N],b[N],a[N],Q[N],tot;
LL p[N],q[N],lim[N],dis[N],ans[N];

bool cmp(int x,int y){return lim[x]<lim[y];}
double pos(int x,int y){return double(ans[x]-ans[y])/(dis[x]-dis[y]);}

void dfs(int x)
{
	lim[x]=dis[x]-lim[x],q[x]+=dis[x]*p[x];
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=f[x])  dis[y]=dis[x]+e[i].d,dfs(y);
}

void upd(int x,int y)
{
	ans[x]=min(ans[x],ans[y]-dis[y]*p[x]+q[x]);
}

void dfs_size(int x)
{
	siz[x]=1;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if ((y!=f[x])&&(!b[y]))
			dfs_size(y),siz[x]+=siz[y];
}

int getroot(int x,int size)
{
	int res=0;
	for (int i=h[x],y,t; y=e[i].t,i; i=e[i].n)
		if ((y!=f[x])&&(!b[y]))
			{
				t=getroot(y,size);
				if (max(size-siz[t],siz[t])<max(size-siz[res],siz[res]))  res=t;
			}
	if (max(size-siz[x],siz[x])<=max(size-siz[res],siz[res]))  res=x;
	return res;
}

void dfs_upd(int x,int j)
{
	if (dis[j]>=lim[x])  upd(x,j);
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if ((y!=f[x])&&(!b[y]))  dfs_upd(y,j);
}

void dfs_(int x)
{
	a[++m]=x;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if ((y!=f[x])&&(!b[y]))  dfs_(y);
}

void calc(int x)
{
	if (tot==0)  return;
	if ((tot==1)||(p[x]>=pos(Q[1],Q[2])))  return upd(x,Q[1]);
	int l=1,r=tot,mid;
	for (; r-l>1; mid=(l+r)>>1,p[x]<pos(Q[mid],Q[mid+1])?l=mid:r=mid);
	upd(x,Q[r]);
}

void solve(int x)
{
	dfs_size(x);
	int rt=getroot(x,siz[x]);
	b[rt]=1;
	if (rt!=x)
		{
			solve(x),m=tot=0;
			for (int i=f[rt]; i!=f[x]; i=f[i])  if (dis[i]>=lim[rt])  upd(rt,i);
			for (int i=h[rt]; i; i=e[i].n)  if (e[i].t!=f[rt])  dfs_(e[i].t);
			sort(a+1,a+m+1,cmp);
			for (int i=rt; m; calc(a[m--]))
				for (; i!=f[x]; i=f[i])
					if (dis[i]>=lim[a[m]])
						{
							while ((tot>1)&&(pos(i,Q[tot])>=pos(Q[tot],Q[tot-1])))  tot--;
							Q[++tot]=i;
						}else  break;
			for (int i=h[rt],y; y=e[i].t,i; i=e[i].n)
				if ((y!=f[rt])&&(!b[y]))  solve(y);
		}else
		for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
			if ((y!=f[x])&&(!b[y]))  dfs_upd(y,x),solve(y);
}

void work()
{
	scanf("%d %d",&n,&t);
	for (int i=2,tot=0; i<=n; i++)
		{
			scanf("%d %lld %lld %lld %lld",&f[i],&e[0].d,&p[i],&q[i],&lim[i]);
			e[++tot]=(edge){f[i],i,h[f[i]],e[0].d},h[f[i]]=tot;
			e[++tot]=(edge){i,f[i],h[i],e[0].d},h[i]=tot;
			ans[i]=1LL<<60;
		}
	dfs(1);
	siz[1]=n,solve(1);
	for (int i=2; i<=n; i++)  printf("%lld\n",ans[i]);
}

int main()
{
	freopen("7.in","r",stdin);
	freopen("7.out","w",stdout);
	work();
	return 0;
}
