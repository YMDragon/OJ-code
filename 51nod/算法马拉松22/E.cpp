#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#define pb  push_back
using namespace std;

typedef long long  LL;
const int N=100010;
struct Pair{int x,y;};
struct node{LL a;int b,f,ch[2],siz,sum;}t[3*N];
struct edge{int s,t,n;}e[2*N],Add[2*N],Del[2*N],Ask[2*N];
int n,m,q,tot,Mtot,top,root;
int h[N],dep[N],f[N][20],rt[N],Mid[N],St[3*N],hAdd[N],hDel[N],hAsk[N];
LL ans[N];
map <int,int> M[N];

int Count=0;

int gi()
{
	int w=0;  char ch=getchar();
	while ((ch<'0')||('9'<ch))  ch=getchar();
	while (('0'<=ch)&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return w;
}

void pL(LL x){if (x>9)  pL(x/10);  putchar(x%10+'0');}

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

void clear(int x)
{
	t[x]=(node){0,0,0,{0,0},0,0},St[++top]=x;
}

void update(int x)
{
	t[x].siz=1+t[t[x].ch[0]].siz+t[t[x].ch[1]].siz;
	t[x].sum=t[x].b^t[t[x].ch[0]].sum^t[t[x].ch[1]].sum;
}

void rotate(int x)
{
	int f=t[x].f,ff=t[f].f,q=(t[f].ch[1]==x),ch=t[x].ch[q^1];
	if (ff)  t[ff].ch[t[ff].ch[1]==f]=x;  else  root=x;  t[x].f=ff;
	t[f].ch[q]=ch;  if (ch)  t[ch].f=f;
	t[x].ch[q^1]=f,t[f].f=x;
	update(f),update(x);
}

void splay(int x)
{
	while (t[x].f)
		if (!t[t[x].f].f)  rotate(x);
		else  if ((t[t[x].f].ch[1]==x)==(t[t[t[x].f].f].ch[1]==t[x].f))
			rotate(t[x].f),rotate(x);
		else  rotate(x),rotate(x);
}

int ask(int k)
{
	if (k>=t[root].siz)  return t[root].sum;
	k++;
	int x=root;
	while (x)
		{
			if (t[t[x].ch[0]].siz+1==k)  break;
			if (k<=t[t[x].ch[0]].siz)  x=t[x].ch[0];
			else  k-=t[t[x].ch[0]].siz+1,x=t[x].ch[1];
		}
	splay(x);
	return t[t[x].ch[0]].sum;
}

void modify(LL a,int b,int id)
{
	int x,y,q,tot=0;
	if (x=M[id][b])
		{
			while (t[x].siz!=1)
				if (t[t[x].ch[0]].siz>t[t[x].ch[1]].siz)  rotate(t[x].ch[0]);
				else  rotate(t[x].ch[1]);
			if (root==x)  root=0;
			else  t[t[x].f].ch[t[t[x].f].ch[1]==x]=0;
			for (y=t[x].f; y; y=t[y].f)  update(y);
			t[x].f=0;
		}else
		M[id][b]=x=St[top--],t[x].b=b,t[x].siz=1,t[x].sum=b;
	if ((t[x].a+=a)==0)  return;
	if (!root)  {root=x;  return;}
	y=root;
	while (y)
		{
			q=(t[x].a>t[y].a)||((t[x].a==t[y].a)&&(t[x].b>t[y].b)),tot++;
			if (t[y].ch[q])  y=t[y].ch[q];
			else  {t[y].ch[q]=x;  break;}
		}
	for (t[x].f=y; y; y=t[y].f)  update(y);
	if (tot>30)  splay(x);
}

void move(int x,int id)
{
	if (!x)  return;
	int ls=t[x].ch[0],rs=t[x].ch[1],b=t[x].b;
	LL a=t[x].a;
	clear(x),modify(a,b,id);
	move(ls,id),move(rs,id);
}

void solve(int x,int f)
{
	int is=0;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=f)
			{
				solve(y,x);
				if (t[rt[y]].siz>t[rt[is]].siz)  is=y;
			}
	if (!is)  Mid[x]=++Mtot;  else  Mid[x]=Mid[is];
	root=rt[is];
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if ((y!=f)&&(y!=is))  move(rt[y],Mid[x]);
	for (int i=hAdd[x]; i; i=Add[i].n)
		modify(Add[i].s,Add[i].t,Mid[x]);
	for (int i=hDel[x]; i; i=Del[i].n)
		modify(-Del[i].s,Del[i].t,Mid[x]);
	for (int i=hAsk[x]; i; i=Ask[i].n)
		ans[Ask[i].s]=ask(Ask[i].t);
	for (int i=hDel[x]; i; i=Del[i].n)
		modify(-Del[i].s,Del[i].t,Mid[x]);
	rt[x]=root;
}

void work()
{
	n=gi();
	for (int i=1,u,v,tot=0; i<n; i++)
		{
			u=gi(),v=gi();
			e[++tot]=(edge){u,v,h[u]},h[u]=tot;
			e[++tot]=(edge){v,u,h[v]},h[v]=tot;
		}
	dfs(1,0);
  for (int j=1; j<20; j++)
    for (int i=1; i<=n; i++)
      f[i][j]=f[f[i][j-1]][j-1];
	m=gi();
	for (int i=1,u,v,a,b,l; i<=m; i++)
		{
			u=gi(),v=gi(),a=gi(),b=gi(),l=LCA(u,v);
			Add[++hAdd[0]]=(edge){a,b,hAdd[u]},hAdd[u]=hAdd[0];
			Add[++hAdd[0]]=(edge){a,b,hAdd[v]},hAdd[v]=hAdd[0];
			Del[++hDel[0]]=(edge){a,b,hDel[l]},hDel[l]=hDel[0];
		}
	q=gi();
	for (int i=1,w,k; i<=q; i++)
		{
			w=gi(),k=gi();
			Ask[++hAsk[0]]=(edge){i,k,hAsk[w]},hAsk[w]=hAsk[0];
		}
	for (int i=300000; i; i--)  St[++top]=i;
	solve(1,0);
	for (int i=1; i<=q; i++)  pL(ans[i]),puts("");
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
