#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define clear(x)  memset(x,0,sizeof(x))
#define Ls(n)  (n<<1)
#define Rs(n)  (Ls(n)|1)
using namespace std;

typedef long long  LL;
struct node{int f,tag,ch[2];}t[100010];
struct edge{int s,t,n;}e[200010];
int n,q,tot,h[100010],segtag[400010],dfn[100010],dfnn[100010];
LL segtree[400010];

void pushdown(int n,int l,int r)
{
	int mid=(l+r)>>1,x=segtag[n];
	segtag[Ls(n)]+=x,segtag[Rs(n)]+=x;
	segtree[Ls(n)]+=1LL*(mid-l+1)*x,segtree[Rs(n)]+=1LL*(r-mid)*x;
	segtag[n]=0;
}

void modify(int n,int l,int r,int L,int R,int k)
{
	if ((L<=l)&&(r<=R))  segtag[n]+=k,segtree[n]+=1LL*k*(r-l+1);
	else
		{
			int mid=(l+r)>>1;
			pushdown(n,l,r);
			if (L<=mid)  modify(Ls(n),l,mid,L,R,k);
			if (mid<R)  modify(Rs(n),mid+1,r,L,R,k);
			segtree[n]=segtree[Ls(n)]+segtree[Rs(n)];
		}
}

LL ask(int n,int l,int r,int L,int R)
{
	if ((L<=l)&&(r<=R))  return segtree[n];
	else
		{
			int mid=(l+r)>>1;  LL res=0;
			pushdown(n,l,r);
			if (L<=mid)  res+=ask(Ls(n),l,mid,L,R);
			if (mid<R)  res+=ask(Rs(n),mid+1,r,L,R);
			return res;
		}
}

void dfs(int x,int f,int dep)
{
	t[x].f=f,dfn[x]=++tot,modify(1,1,n,tot,tot,dep);
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=f)  dfs(y,x,dep+1);
	dfnn[x]=tot;
}

bool isroot(int x)
{
	return (!t[x].f)||((t[t[x].f].ch[0]!=x)&&(t[t[x].f].ch[1]!=x));
}

void push_down(int x)
{
	if (t[x].tag)
		{
			swap(t[x].ch[0],t[x].ch[1]);
			if (t[x].ch[0])  t[t[x].ch[0]].tag^=1;
			if (t[x].ch[1])  t[t[x].ch[1]].tag^=1;
			t[x].tag=0;
		}
}

void up(int x)
{
	if (!isroot(x))  up(t[x].f);
	push_down(x);
}

void rotate(int x)
{
	int f=t[x].f,ff=isroot(f)?0:t[f].f,q=(t[f].ch[1]==x),ch=t[x].ch[q^1];
	if (ff)  t[ff].ch[t[ff].ch[1]==f]=x;  t[x].f=t[f].f;
	t[f].ch[q]=ch;  if (ch)  t[ch].f=f;
	t[x].ch[q^1]=f,t[f].f=x;
}

void splay(int x)
{
	up(x);
	while (!isroot(x))
		if (isroot(t[x].f))  rotate(x);
		else  if ((t[t[x].f].ch[1]==x)==(t[t[t[x].f].f].ch[1]==t[x].f))
			rotate(t[x].f),rotate(x);
		else  rotate(x),rotate(x);
}

int findmin(int x)
{
	while (t[x].ch[0])  x=t[x].ch[0];
	return x;
}

void change(int x)
{
	for (int y=0,z; x; y=x,x=t[x].f)
		{
			splay(x);
			if (t[x].f)  z=findmin(x),modify(1,1,n,dfn[z],dfnn[z],-1);
			if (t[x].ch[1])  z=findmin(t[x].ch[1]),modify(1,1,n,dfn[z],dfnn[z],1);
			t[x].ch[1]=y;
		}
}

void work()
{
	clear(t),clear(segtree),clear(segtag),clear(h);
	scanf("%d",&n),tot=0;
	for (int i=1,x,y,tot=0; i<n; i++)
		{
			scanf("%d %d",&x,&y),x++,y++;
			e[++tot]=(edge){x,y,h[x]},h[x]=tot;
			e[++tot]=(edge){y,x,h[y]},h[y]=tot;
		}
	dfs(1,0,0);
	scanf("%d\n",&q);
	for (int i=1,x; i<=q; i++)
		{
			char ch;
			scanf("%c %d\n",&ch,&x),x++;
			if (ch=='O')  change(x);
			else
				printf("%.10lf\n",1.0*ask(1,1,n,dfn[x],dfnn[x])/(dfnn[x]-dfn[x]+1));
		}
}

int main()
{
	freopen("MONOPLOY.in","r",stdin);
	freopen("MONOPLOY.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
