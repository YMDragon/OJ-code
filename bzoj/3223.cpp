#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct node{int k,s,tag,ch[2],f;}t[100010];

int n,m,tot,root,b[100010];

void push(int x)
{
	if (t[x].tag)
		{
			swap(t[x].ch[0],t[x].ch[1]),t[x].tag=0;
			t[t[x].ch[0]].tag^=1,t[t[x].ch[1]].tag^=1;
		}
}

void rotate(int x)
{
	int f=t[x].f,ff=t[f].f,q=(x==t[f].ch[1]),ch=t[x].ch[q^1];
	if (ff)  t[x].f=t[f].f,t[ff].ch[f==t[ff].ch[1]]=x;  else  t[x].f=0;
	t[f].ch[q]=ch;  if (ch)  t[ch].f=f;
	t[x].ch[q^1]=f,t[f].f=x;
	t[x].s=t[f].s,t[f].s=t[t[f].ch[0]].s+t[t[f].ch[1]].s+1;
}

void splay(int x)
{
	if (x==0)  return;
	int w=0;
	for (int i=x; i; i=t[i].f)  b[++w]=i;
	for (int i=w; i; i--)  push(b[i]);
	while (t[x].f)  rotate(x);
	root=x;
}

int select(int k)
{
	int n=root;
	while (n)
		{
			push(n);
			if (k<=t[t[n].ch[0]].s)  n=t[n].ch[0];
			else  if (k==t[t[n].ch[0]].s+1)  return n;
			else  k-=t[t[n].ch[0]].s+1,n=t[n].ch[1];
		}
	return 0;
}

void reverse(int l,int r)
{
	int ll=select(l-1),rr=select(r+1);
	splay(ll),splay(rr);
	if (l==1)
		if (r==n)  t[root].tag^=1;
		else  t[t[root].ch[0]].tag^=1;
	else
		if (r==n)  t[t[root].ch[1]].tag^=1;
		else  t[t[t[root].ch[0]].ch[1]].tag^=1;
}

int build(int l,int r)
{
	int mid=(l+r)>>1,n=mid;
	t[n]=(node){mid,1,0,{0,0},0};
	if (l<mid)
		{
			t[n].ch[0]=build(l,mid-1);
			t[t[n].ch[0]].f=n;
			t[n].s+=t[t[n].ch[0]].s;
		}
	if (mid<r)
		{
			t[n].ch[1]=build(mid+1,r);
			t[t[n].ch[1]].f=n;
			t[n].s+=t[t[n].ch[1]].s;
		}
	return n;
}

void print(int n)
{
	push(n);
	if (t[n].ch[0])  print(t[n].ch[0]);
	printf("%d ",t[n].k);
	if (t[n].ch[1])  print(t[n].ch[1]);
}

void work()
{
	scanf("%d %d",&n,&m);
	root=build(1,n);
	for (int i=1,l,r; i<=m; i++)
		{
			scanf("%d %d",&l,&r);
			reverse(l,r);
		}
	print(root);
}

int main()
{
	freopen("3223.in","r",stdin);
	freopen("3223.out","w",stdout);
	work();
	return 0;
}
