#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const int N=150010;
struct edge{int s,t,d,n;}e[2*N];
struct node{LL bac;  int add,ls,rs;}t[100*N];
struct year{int oy,ny,id;}a[N];
int n,q,A,m,tot,h[N],rt[N],s[N],id[N],hs[N],fa[N],pa[N],dep[N],sum[N],sg[N];
LL ans,sd[N];

bool cmp(year x,year y){return x.oy<y.oy;}

void dfs1(int x,int f)
{
	fa[x]=f,s[x]=1;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=f)
			dfs1(y,x),s[x]+=s[y],hs[x]=(s[hs[x]]<s[y])?y:hs[x];
}

void dfs2(int x,int p,int dis)
{
	pa[x]=p,id[x]=++tot,dep[x]=dis;
	for (int i=h[x]; i; i=e[i].n)
		if (e[i].t==hs[x])  dfs2(hs[x],p,dis+e[i].d);
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if ((y!=fa[x])&&(y!=hs[x]))  dfs2(y,y,dis+e[i].d);
		else  if (y==fa[x])  sum[id[x]]=e[i].d;
}

int modify(int old,int l,int r,int L,int R,LL &bac)
{
	int n=++tot,mid=(l+r)>>1;  LL Bac=0;
	t[n]=t[old];
	if ((L<=l)&&(r<=R))  {t[n].add++;  bac+=sum[r]-sum[l-1];  return n;}
	if (L<=mid)  t[n].ls=modify(t[n].ls,l,mid,L,R,Bac),bac+=Bac,t[n].bac+=Bac,Bac=0;
	if (mid<R)  t[n].rs=modify(t[n].rs,mid+1,r,L,R,Bac),bac+=Bac,t[n].bac+=Bac,Bac=0;
	return n;
}

LL ask(int n,int l,int r,int L,int R,int sa)
{
	if (!n)  return 1LL*sa*(sum[min(r,R)]-sum[max(L,l)-1]);
	sa+=t[n].add;
	if ((L<=l)&&(r<=R))
		return t[n].bac+1LL*sa*(sum[r]-sum[l-1]);
	else
		{
			LL res=0,mid=(l+r)>>1;
			if (L<=mid)  res+=ask(t[n].ls,l,mid,L,R,sa);
			if (mid<R)  res+=ask(t[n].rs,mid+1,r,L,R,sa);
			return res;
		}
}

int upper(int x)
{;
	int l=0,r=n,mid;
	while (r-l>1)
		{
			mid=(l+r)>>1;
			if (a[mid].oy>=x)  r=mid;  else  l=mid;
		}
	return a[r].ny;
}

int lower(int x)
{
	int l=1,r=n+1,mid;
	while (r-l>1)
		{
			mid=(l+r)>>1;
			if (a[mid].oy<=x)  l=mid;  else  r=mid;
		}
	return a[l].ny;
}

void work()
{
	scanf("%d %d %d",&n,&q,&A);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i].oy),a[i].id=i;
	sort(a+1,a+n+1,cmp),tot=0;
	for (int i=1,x,y,w; i<n; i++)
		{
			scanf("%d %d %d",&x,&y,&w);
			e[++tot]=(edge){x,y,w,h[x]},h[x]=tot;
			e[++tot]=(edge){y,x,w,h[y]},h[y]=tot;
		}
	dfs1(1,0);
	tot=0,dfs2(1,1,0);
	tot=0,a[0].oy=-1,a[n+1].oy=(1<<30);
	for (int i=1; i<=n; i++)  sum[i]+=sum[i-1];
	for (int i=1; i<=n; i++)
		{
			if (a[i].oy!=a[i-1].oy)  m++,rt[m]=rt[m-1];
			a[i].ny=m;
			int x=a[i].id;  LL bac;
			while (x)
				rt[m]=modify(rt[m],1,n,id[pa[x]],id[x],bac),x=fa[pa[x]];
			sg[m]++,sd[m]+=dep[a[i].id];
		}
	a[n+1].ny=m+1;
	for (int i=1; i<=m; i++)  sg[i]+=sg[i-1],sd[i]+=sd[i-1];
	for (int i=1,u,a,b; i<=q; i++)
		{
			scanf("%d %d %d",&u,&a,&b),a=(a+ans)%A,b=(b+ans)%A;
			if (a>b)  swap(a,b);
			ans=0,a=upper(a),b=lower(b);
			ans=1LL*dep[u]*(sg[b]-sg[a-1])+sd[b]-sd[a-1];
			while (u)
				ans-=2*ask(rt[b],1,n,id[pa[u]],id[u],0)-2*ask(rt[a-1],1,n,id[pa[u]],id[u],0),u=fa[pa[u]];
			printf("%lld\n",ans);
		}
}

int main()
{
	freopen("4012.in","r",stdin);
	freopen("4012.out","w",stdout);
	work();
	return 0;
}
