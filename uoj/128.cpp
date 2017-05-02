#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define Ls(x)  (x<<1)
#define Rs(x)  (Ls(x)+1)
using namespace std;

struct edge{int s,t,n;}e[100010];
struct node{int s,tag;}t[400010];
int n,q,tot,h[100010],fa[100010],gf[100010],dep[100010],siz[100010],hs[100010],mar[100010],r[100010];
char ch[20];

void dfs1(int x)
{
	siz[x]=1,dep[x]=dep[fa[x]]+1;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		{
			dfs1(y),siz[x]+=siz[y];
			if (siz[hs[x]]<siz[y])  hs[x]=y;
		}
}

void dfs2(int x,int Gf)
{
	gf[x]=Gf,mar[x]=++tot;
	if (hs[x])  dfs2(hs[x],Gf);
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=hs[x])  dfs2(y,y);
	r[x]=tot;
}

void build(int n,int l,int r)
{
	t[n]=(node){0,-1};
	if (l!=r)
		{
			int mid=(l+r)>>1;
			build(Ls(n),l,mid),build(Rs(n),mid+1,r);
		}
}

void pushdown(int n,int l,int r)
{
	if (t[n].tag>=0)
		{
			int mid=(l+r)>>1;
			t[Ls(n)].tag=t[Rs(n)].tag=t[n].tag;
			t[Ls(n)].s=(mid-l+1)*t[n].tag,t[Rs(n)].s=(r-mid)*t[n].tag;
			t[n].tag=-1;
		}
}

int query(int n,int l,int r,int L,int R)
{
	if ((L<=l)&&(r<=R))  return t[n].s;
	else
		{
			int mid=(l+r)>>1,res=0;
			pushdown(n,l,r);
			if (L<=mid)  res+=query(Ls(n),l,mid,L,R);
			if (mid<R)  res+=query(Rs(n),mid+1,r,L,R);
			t[n].s=t[Ls(n)].s+t[Rs(n)].s;
			return res;
		}
}

void update(int n,int l,int r,int L,int R,int k)
{
	if ((L<=l)&&(r<=R))
		t[n].tag=k,t[n].s=(r-l+1)*k;
	else
		{
			int mid=(l+r)>>1;
			pushdown(n,l,r);
			if (L<=mid)  update(Ls(n),l,mid,L,R,k);
			if (mid<R)  update(Rs(n),mid+1,r,L,R,k);
			t[n].s=t[Ls(n)].s+t[Rs(n)].s;
		}
}

void work()
{
	scanf("%d",&n);
	for (int i=2; i<=n; i++)
		scanf("%d",&fa[i]),fa[i]++,e[i]=(edge){fa[i],i,h[fa[i]]},h[fa[i]]=i;
	dfs1(1),dfs2(1,1);
	build(1,1,n);
	scanf("%d\n",&q);
	for (int i=1,x,ans; i<=q; i++)
		{
			scanf("%s %d\n",ch,&x),x++;
			if (ch[0]=='i')
				{
					ans=dep[x];
					while (x)
						{
							ans-=query(1,1,n,mar[gf[x]],mar[x]);
							update(1,1,n,mar[gf[x]],mar[x],1);
							x=fa[gf[x]];
						}
				}else
				{
					ans=query(1,1,n,mar[x],r[x]);
					update(1,1,n,mar[x],r[x],0);
				}
			printf("%d\n",ans);
		}
}

int main()
{
	freopen("128.in","r",stdin);
	freopen("128.out","w",stdout);
	work();
	return 0;
}
