#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct edge{int s,t;}e[200010];
int n,m,q,ntr[200010];

namespace LCT{
	struct node{int x,min,f,tag,ch[2];}t[400010];
	int tot;

	bool isroot(int x){return (t[t[x].f].ch[0]!=x)&&(t[t[x].f].ch[1]!=x);}

	void push_down(int x)
	{
		if (t[x].tag)
			{
				swap(t[x].ch[0],t[x].ch[1]);
				if (t[x].ch[0])  t[t[x].ch[0]].tag^=1;
				if (t[x].ch[1])  t[t[x].ch[1]].tag^=1;
				t[x].tag^=1;
			}
	}

	void up(int x){if (!isroot(x))  up(t[x].f);  push_down(x);}
	void update(int x){t[x].min=min(t[x].x,min(t[t[x].ch[0]].min,t[t[x].ch[1]].min));}

	void rotate(int x)
	{
		int f=t[x].f,ff=t[f].f,q=(t[f].ch[1]==x),ch=t[x].ch[q^1];
		if (!isroot(f))  t[ff].ch[t[ff].ch[1]==f]=x;  t[x].f=ff;
		t[f].ch[q]=ch;  if (ch)  t[ch].f=f;
		t[x].ch[q^1]=f,t[f].f=x;
		t[x].min=t[f].min,update(f);
	}

	void splay(int x){for (up(x); !isroot(x); )  rotate(x);}
	void access(int x){for (int y=0; x; y=x,x=t[x].f)  splay(x),t[x].ch[1]=y,update(x);}
	void event(int x){access(x),splay(x),t[x].tag^=1;}
	bool same_tree(int x,int y){event(x),access(y),splay(y);  return (x==y)||(t[x].f);}
	void link(int x,int y,int d){if (!same_tree(x,y))  t[x].f=++tot,t[tot].f=y,t[tot].x=t[tot].min=d;}
	void cut(int x,int y){if (same_tree(x,y))  t[x].f=t[y].ch[0]=0,update(y);}
	void init(int n){for (int i=0; i<=n; i++)  t[i].x=t[i].min=1<<30;  tot=n;}
	void clear(){for (int i=0; i<=tot; i++)  t[i]=(node){0,0,0,0,{0,0}};}
};

namespace ChairTree{
	struct node{int x,ls,rs;}t[4000000];
	int tot,rt[200010];

	void modify(int &n,int l,int r,int x)
	{
		tot++,t[tot]=t[n],n=tot,t[n].x++;
		if (l!=r)
			{
				int mid=(l+r)>>1;
				if (x<=mid)  modify(t[n].ls,l,mid,x);
				else  modify(t[n].rs,mid+1,r,x);
			}
	}

	int ask(int n,int l,int r,int x)
	{
		if (r<=x)  return t[n].x;
		else
			{
				int mid=(l+r)>>1,res;
				res=ask(t[n].ls,l,mid,x);
				if (mid<x)  res+=ask(t[n].rs,mid+1,r,x);
				return res;
			}
	}
};

void work()
{
	scanf("%d %d %d",&n,&m,&q);
	LCT::init(n);
	for (int i=1,x,y,p; i<=m; i++)
		{
			scanf("%d %d",&x,&y),e[i]=(edge){x,y};
			if (x==y)  {ntr[i]=i,LCT::tot++;  continue;}
			if (LCT::same_tree(x,y))
				{
					p=LCT::t[LCT::t[y].ch[0]].min,ntr[i]=p;
					LCT::cut(e[p].s,p+n),LCT::cut(e[p].t,p+n);
					LCT::link(x,y,i);
				}else  LCT::link(x,y,i),ntr[i]=0;
		}
	for (int i=1; i<=m; i++)
		{
			ChairTree::rt[i]=ChairTree::rt[i-1];
			ChairTree::modify(ChairTree::rt[i],0,m,ntr[i]);
		}
	for (int i=1,l,r; i<=q; i++)
		{
			scanf("%d %d",&l,&r);
			printf("%d\n",n-(ChairTree::ask(ChairTree::rt[r],0,m,l-1)-ChairTree::ask(ChairTree::rt[l-1],0,m,l-1)));
		}
	LCT::clear();
}

int main()
{
	freopen("GERALD07.in","r",stdin);
	freopen("GERALD07.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
