#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct node{int s,ls,rs,tag;}t[3000010];
struct edge{int s,t,n;}e[200010];
int n,m,N,tot,h[100010],sg[100010],vis[100010],rt[100010],ans;

void clear()
{
	ans=tot=0;
	memset(vis,0,sizeof(vis));
	memset(h,0,sizeof(h));
}

void push_down(int x,int len)
{
	if (t[x].tag&len)  swap(t[x].ls,t[x].rs),t[x].tag-=len;
	t[t[x].ls].tag^=t[x].tag,t[t[x].rs].tag^=t[x].tag;
	t[x].tag=0;
}

void merge(int &x,int y,int l,int r)
{
	if (!x)  swap(x,y);
	if (!y)  return;
	int len=(r-l+1)/2,mid=l+len;
	push_down(x,len),push_down(y,len);
	merge(t[x].ls,t[y].ls,l,mid-1);
	merge(t[x].rs,t[y].rs,mid,r);
}

void insert(int &x,int l,int r,int k)
{
	if (!x)  x=++tot,t[x]=(node){0,0,0,0};
	if (l==r)  t[x].s=1;
	else
		{
			int len=(r-l+1)/2,mid=l+len;
			push_down(x,len);
			k&len?insert(t[x].rs,mid,r,k-len):insert(t[x].ls,l,mid-1,k);
			t[x].s=t[t[x].ls].s+t[t[x].rs].s;
		}
}

int ask(int x,int l,int r)
{
	if (l==r)  return 0;
	else
		{
			int len=(r-l+1)/2,mid=l+len;
			push_down(x,len);
			return t[t[x].ls].s==len?(ask(t[x].rs,mid,r)+len):ask(t[x].ls,l,mid-1);
		}
}

void dfs(int x,int f)
{
	int Sum=0,hs=0;
	vis[x]=1;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=f)
			{
				dfs(y,x),Sum^=sg[y];
				if (t[rt[y]].s>t[rt[hs]].s)  hs=y;
			}
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=f)  t[rt[y]].tag^=Sum^sg[y];
	rt[x]=rt[hs];
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if ((y!=f)&&(y!=hs))
			merge(rt[x],rt[y],0,N-1);
	insert(rt[x],0,N-1,Sum);
	sg[x]=ask(rt[x],0,N-1);
}

void work()
{
	scanf("%d %d",&n,&m),clear();
	for (N=1; N<=n; N<<=1);
	for (int i=1,u,v,etot=0; i<=m; i++)
		{
			scanf("%d %d",&u,&v);
			e[++etot]=(edge){u,v,h[u]},h[u]=etot;
			e[++etot]=(edge){v,u,h[v]},h[v]=etot;
		}
	for (int i=1; i<=n; i++)
		if (!vis[i])
			dfs(i,0),ans^=sg[i];
	puts(ans?"Alice":"Bob");
}

int main()
{
	freopen("266.in","r",stdin);
	freopen("266.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
