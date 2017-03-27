#include <algorithm>
#include <cstdio>
#define Ls(n)  (n<<1)
#define Rs(n)  (Ls(n)|1)
#define upd(x,y)  (Tmp=y,x=(x<Tmp)?Tmp:x)
using namespace std;

typedef long long  LL;
typedef pair<int,int>  PII;
typedef long double  LDB;
typedef int  arr[100010];

struct node{int max,tim;}t[400010];
struct query{int ty,a,b,v,dt;}q[200010];
struct edge{int s,t,n;}e[200010];
struct node2{int l,r;}tmp[1000];
int n,m,tot,Tmp,N,tim;
arr h,dfn,siz,hs,dep,f,g;

int gi()
{
	int w=0,q=1;  char ch=getchar();
	while (((ch<'0')||('9'<ch))&&(ch!='-'))  ch=getchar();
	if (ch=='-')  q=0,ch=getchar();
	while (('0'<=ch)&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return q?w:-w;
}

void pi(int x)
{
	if (x<0)  putchar('-'),x=-x;
	if (x>9)  pi(x/10);
	putchar(x%10+'0');
}

bool cmp(node2 x,node2 y){return (x.l<y.l);}

void dfs(int x,int fa)
{
	f[x]=fa,siz[x]=1;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=fa)
			{
				dfs(y,x),siz[x]+=siz[y];
				if (siz[y]>siz[hs[x]])  hs[x]=y;
			}
}

void dfs2(int x,int gf)
{
	g[x]=gf,dfn[x]=++tot,dep[x]=dep[f[gf]]+1;
	if (hs[x])  dfs2(hs[x],gf);
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if ((y!=f[x])&&(y!=hs[x]))
			dfs2(y,y);
}

int ask(int x)
{
	int res=-1;
	x+=N;
	while (x!=1)
		{
			if (t[x].tim==tim)  upd(res,t[x].max);
			x>>=1;
		}
	return res;
}

void modify(int l,int r,int k)
{
	l+=N-1,r+=N-1,r+=2;
	while ((l!=r)&&((l^1)!=r))
		{
			if (!(l&1))
				if (t[l^1].tim==tim)  upd(t[l^1].max,k);
				else  t[l^1].tim=tim,t[l^1].max=k;
			if (r&1)
				if (t[r^1].tim==tim)  upd(t[r^1].max,k);
				else  t[r^1].tim=tim,t[r^1].max=k;
			l>>=1,r>>=1;
		}
}

void modify(int i)
{
	int x=q[i].a,y=q[i].b,tot=0;
	while (g[x]!=g[y])
		{
			if (dep[x]<dep[y])  swap(x,y);
			tmp[++tot]=(node2){dfn[g[x]],dfn[x]};
			x=f[g[x]];
		}
	if (dfn[x]>dfn[y])  swap(x,y);
	tmp[++tot]=(node2){dfn[x],dfn[y]};
	sort(tmp+1,tmp+tot+1,cmp);
	tmp[++tot]=(node2){n+1,n+1};
	for (int j=1,r=0; j<=tot; j++)
		{
			if (tmp[j].l-r>1)  modify(r+1,tmp[j].l-1,q[i].v);
			r=tmp[j].r;
		}
}

void solve(int l,int r)
{
	if (l==r)  return;
	int mid=(l+r)>>1,ok=0;
	solve(l,mid),solve(mid+1,r);
	for (int i=l; i<=mid; i++)  if (q[i].ty==0)  {ok++;  break;}
	for (int i=r; i>mid; i--)  if (q[i].ty==2)  {ok++;  break;}
	if (ok<2)  return;
	tim++;
	for (int i=l; i<=mid; i++)
		if ((q[i].ty==0)&&(q[i].dt>r))
			modify(i);
	for (int i=r; i>mid; i--)
		if (q[i].ty==2)  upd(q[i].v,ask(dfn[q[i].a]));
		else  if ((q[i].ty==1)&&(l<=q[i].a)&&(q[i].a<=mid))
			modify(q[i].a);
}

void work()
{
	n=gi(),m=gi();
	for (int i=1,u,v,etot=0; i<n; i++)
		{
			u=gi(),v=gi();
			e[++etot]=(edge){u,v,h[u]},h[u]=etot;
			e[++etot]=(edge){v,u,h[v]},h[v]=etot;
		}
	dfs(1,0),dfs2(1,1);
	for (int i=1; i<=m; i++)
		{
			q[i].ty=gi(),q[i].a=gi();
			if (q[i].ty==0)  q[i].b=gi(),q[i].v=gi();
			if (q[i].ty==1)  q[q[i].a].dt=i;
			if (q[i].ty==2)  q[i].v=-1;
		}
	for (int i=1; i<=m; i++)
		if ((q[i].ty==0)&&(q[i].dt==0))  q[i].dt=m+1;
	for (N=1; N<=(n+2); N<<=1);
	solve(1,m);
	for (int i=1; i<=m; i++)
		if (q[i].ty==2)  pi(q[i].v),putchar('\n');
}

int main()
{
	freopen("4538.in","r",stdin);
	freopen("4538.out","w",stdout);
	work();
	return 0;
}
