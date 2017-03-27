#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define Ls(n)  (n<<1)
#define Rs(n)  (Ls(n)|1)
#define RG  register
using namespace std;

typedef int arr[50010];
struct edge{int s,t,n;}e[100010];
int n,m,tot,t1[200010],t2[200010];
arr a,h,siz,hs,f,g,dep,dfn,dfnn;

inline int gcd(RG int x,RG int y){return y?gcd(y,x%y):x;}

inline void dfs(RG int x,RG int fa)
{
	f[x]=fa,siz[x]=1;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=fa)
			{
				dfs(y,x),siz[x]+=siz[y];
				if (siz[y]>siz[hs[x]])  hs[x]=y;
			}
}

inline void dfs(RG int x,RG int gf,RG int Dep)
{
	g[x]=gf,dfn[x]=++tot,dfnn[tot]=x,dep[x]=Dep;
	if (hs[x])  dfs(hs[x],gf,Dep);
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if ((y!=f[x])&&(y!=hs[x]))  dfs(y,y,Dep+1);
}

inline void build(RG int n,RG int l,RG int r)
{
	if (l==r)  t1[n]=a[dfnn[l]]-a[f[dfnn[l]]],t2[n]=a[dfnn[l]];
	else
		{
			int mid=(l+r)>>1;
			if (l<=mid)  build(Ls(n),l,mid);
			if (mid<r)  build(Rs(n),mid+1,r);
			t1[n]=gcd(t1[Ls(n)],t1[Rs(n)]);
		}
}

inline int ask1(RG int n,RG int l,RG int r,RG int L,RG int R)
{
	if ((L<=l)&&(r<=R))  return t1[n];
	else
		{
			int mid=(l+r)>>1,res=0;
			if (L<=mid)  res=gcd(res,ask1(Ls(n),l,mid,L,R));
			if (mid<R)  res=gcd(res,ask1(Rs(n),mid+1,r,L,R));
			return res;
		}
}

inline int ask2(RG int n,RG int l,RG int r,RG int x)
{
	if (l==r)  return t2[n];
	else
		{
			int mid=(l+r)>>1;
			if (x<=mid)  return ask2(Ls(n),l,mid,x)+t2[n];
			else  return ask2(Rs(n),mid+1,r,x)+t2[n];
		}
}

inline void modify1(RG int n,RG int l,RG int r,RG int x,RG int k)
{
	if (l==r)  t1[n]+=k;
	else
		{
			int mid=(l+r)>>1;
			if (x<=mid)  modify1(Ls(n),l,mid,x,k);
			else  modify1(Rs(n),mid+1,r,x,k);
			t1[n]=gcd(t1[Ls(n)],t1[Rs(n)]);
		}
}

inline void modify2(RG int n,RG int l,RG int r,RG int L,RG int R,RG int k)
{
	if ((L<=l)&&(r<=R))  t2[n]+=k;
	else
		{
			int mid=(l+r)>>1;
			if (L<=mid)  modify2(Ls(n),l,mid,L,R,k);
			if (mid<R)  modify2(Rs(n),mid+1,r,L,R,k);
		}
}

inline int jump1(RG int &x)
{
	int res=0;
	if (g[x]!=x)  res=ask1(1,1,n,dfn[g[x]]+1,dfn[x]),x=g[x];
	res=gcd(res,fabs(ask2(1,1,n,dfn[x])-ask2(1,1,n,dfn[f[x]]))),x=f[x];
	return res;
}

inline int query(RG int u,RG int v)
{
	int res=0;
	while (g[u]!=g[v])
		if (dep[u]>dep[v])  res=gcd(res,jump1(u));
		else  res=gcd(res,jump1(v));
	if (dfn[u]>dfn[v])  swap(u,v);
	if (u!=v)  res=gcd(res,ask1(1,1,n,dfn[u]+1,dfn[v]));
	return res;
}

inline void jump2(RG int &x,RG int d)
{
	modify2(1,1,n,dfn[g[x]],dfn[x],d);
	if (hs[x])  modify1(1,1,n,dfn[x]+1,-d);
	x=f[g[x]];
}

inline void modify(RG int u,RG int v,RG int d)
{
	while (g[u]!=g[v])
		if (dep[u]>dep[v])  jump2(u,d);  else  jump2(v,d);
	if (dfn[u]>dfn[v])  swap(u,v);
	modify2(1,1,n,dfn[u],dfn[v],d);
	modify1(1,1,n,dfn[u],d);
	if (hs[v])  modify1(1,1,n,dfn[v]+1,-d);
}

inline int abs(RG int x){return x>0?x:-x;}

void work()
{
	scanf("%d",&n);
	for (int i=1,u,v; i<n; i++)
		{
			scanf("%d %d",&u,&v),u++,v++;
			e[++tot]=(edge){u,v,h[u]},h[u]=tot;
			e[++tot]=(edge){v,u,h[v]},h[v]=tot;
		}
	tot=0,dfs(1,0),dfs(1,1,1);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&m);
	for (int i=1,u,v,d; i<=m; i++)
		{
			char ch;
			do  ch=getchar();  while ((ch!='F')&&(ch!='C'));
			if (ch=='F')
				{
					scanf("%d %d",&u,&v),u++,v++;
					printf("%d\n",abs(gcd(query(u,v),ask2(1,1,n,dfn[u]))));
				}else
				{
					scanf("%d %d %d",&u,&v,&d),u++,v++;
					modify(u,v,d);
				}
		}
}

int main()
{
	freopen("DGCD.in","r",stdin);
	freopen("DGCD.out","w",stdout);
	work();
	return 0;
}
