#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <deque>
using namespace std;

struct node{int k,sum,t,s,ch[2],f;}t[100010];
int n,q,root;
deque <int> DQ;

void updata(int x)
{
	t[x].s=t[t[x].ch[0]].s+t[t[x].ch[1]].s+1;
	t[x].sum=t[t[x].ch[0]].sum+t[t[x].ch[1]].sum+t[x].k;
}

void push(int x)
{
	if (t[x].t)
		swap(t[x].ch[0],t[x].ch[1]),t[t[x].ch[0]].t^=1,t[t[x].ch[1]].t^=1,t[x].t=0;
}

void rotate(int x)
{
	int f=t[x].f,ff=t[f].f,q=(t[f].ch[1]==x),ch=t[x].ch[q^1];
	if (ff)  t[ff].ch[t[ff].ch[1]==f]=x;  else  root=x;  t[x].f=ff;
	t[f].ch[q]=ch,t[ch].f=f;
	t[x].ch[q^1]=f,t[f].f=x;
	updata(f);
}

void splay(int x)
{
	if (x==0)  return;
	int y=x;
	while (y)  DQ.push_back(y),y=t[y].f;
	while (!DQ.empty())  push(DQ.back()),DQ.pop_back();
	while (t[x].f)  rotate(x);
	updata(x);
}

int build(int l,int r,int f)
{
	int mid=(l+r)>>1;
	if (l<mid)  t[mid].ch[0]=build(l,mid-1,mid);
	t[mid].k=1,t[mid].f=f;
	if (mid<r)  t[mid].ch[1]=build(mid+1,r,mid);
	updata(mid);
	return mid;
}

int rank(int k)
{
	int n=root;
	while (n)
		{
			push(n);
			if (t[t[n].ch[0]].s+1==k)  return n;
			if (t[t[n].ch[0]].s>=k)  n=t[n].ch[0];
			else  k-=t[t[n].ch[0]].s+1,n=t[n].ch[1];
		}
	return n;
}

void dfs1(int n)
{
	push(n);
	if (t[n].ch[0])  dfs1(t[n].ch[0]);
	DQ.push_back(t[n].k);
	if (t[n].ch[1])  dfs1(t[n].ch[1]);
}

void dfs2(int n)
{
	if (DQ.empty())  return;
	push(n);
	if (t[n].ch[0])  dfs2(t[n].ch[0]);
	if (DQ.empty())  return updata(n);
	t[n].k+=DQ.back(),DQ.pop_back();
	if (t[n].ch[1])  dfs2(t[n].ch[1]);
	updata(n);
}

void reverse(int p)
{
	if (p>t[root].s-p)  t[root].t^=1,p=t[root].s-p;
	p=rank(p+1),splay(p);
	dfs1(t[p].ch[0]),t[p].ch[0]=0,dfs2(p);
}

int query(int l,int r)
{
	l=rank(l),r=rank(r+1),splay(l),splay(r);
	if (l)  return t[t[l].ch[1]].sum;
	if (r)  return t[t[r].ch[0]].sum;
	return t[root].sum;
}

void work()
{
	scanf("%d %d",&n,&q);
	root=build(1,n,0);
	for (int i=1,o,p,l,r; i<=q; i++)
		{
			scanf("%d",&o);
			if (o==1)
				{
					scanf("%d",&p);
					reverse(p);
				}else
				{
					scanf("%d %d",&l,&r);
					printf("%d\n",query(l,r));
				}
		}
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
