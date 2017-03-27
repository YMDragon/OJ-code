#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

const int oo=(1<<30);
struct node{int k,s,ch[2],f,sum,t1,t2,l,r,m;}t[500010];
int n,m,root,a[500010];
queue <int> Q;

int getint()
{
	int w=0,q=1;
	char ch=getchar();
	while (((ch<'0')||(ch>'9'))&&(ch!='-'))  ch=getchar();
	if (ch=='-')  q=0,ch=getchar();
	while ((ch>='0')&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return q?w:(-w);
}

int max0(int x){return x>0?x:0;}

void plus1(int n,int k)
{
	if (!n)  return;
	t[n].k=k,t[n].t1=1,t[n].sum=t[n].k*t[n].s;
	if (t[n].k>0)  t[n].l=t[n].r=t[n].m=t[n].sum;  else  t[n].l=t[n].r=t[n].m=t[n].k;
}

void plus2(int n)
{
	if (!n)  return;
	swap(t[n].ch[0],t[n].ch[1]),t[n].t2^=1;
	swap(t[n].l,t[n].r);
}

void push(int n)
{
	if (!n)  return;
	if (t[n].t1)	plus1(t[n].ch[0],t[n].k),plus1(t[n].ch[1],t[n].k),t[n].t1=0;
	if (t[n].t2)  plus2(t[n].ch[0]),plus2(t[n].ch[1]),t[n].t2=0;
}

void updata(int n)
{
	if (!n)  return;
	push(n);
	int ls=t[n].ch[0],rs=t[n].ch[1];
	t[n].s=t[ls].s+t[rs].s+1;
	t[n].sum=t[ls].sum+t[rs].sum+t[n].k;
	t[n].l=max(t[ls].l,t[ls].sum+t[n].k+max0(t[rs].l));
	t[n].r=max(t[rs].r,t[rs].sum+t[n].k+max0(t[ls].r));
	t[n].m=max(max(t[ls].m,t[rs].m),t[n].k+max0(t[ls].r)+max0(t[rs].l));
}

void build(int n,int l,int r)
{
	int mid=(l+r)>>1;
	if (l<mid)  t[n].ch[0]=Q.front(),Q.pop(),build(t[n].ch[0],l,mid-1),t[t[n].ch[0]].f=n;
	t[n].k=getint();
	if (mid<r)  t[n].ch[1]=Q.front(),Q.pop(),build(t[n].ch[1],mid+1,r),t[t[n].ch[1]].f=n;
	updata(n);
}

void rotate(int x)
{
	int f=t[x].f,ff=t[f].f,q=(t[f].ch[1]==x),ch=t[x].ch[q^1];
	if (ff)  t[x].f=ff,t[ff].ch[t[ff].ch[1]==f]=x;
	else  t[x].f=0,root=x;
	t[f].ch[q]=ch;if (ch)  t[ch].f=f;
	t[f].f=x,t[x].ch[q^1]=f;
	updata(f),updata(x);
}

void splay(int x)
{
	int k=0;
	for (int y=x; y; y=t[y].f)  a[++k]=y;
	for (int i=k; i>=1; i--)  push(a[i]);
	for (; t[x].f; )  rotate(x);
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
	return 0;
}

void insert()
{
	int posi=getint(),tot=getint(),l,r,root;
	l=rank(posi),r=rank(posi+1);
	splay(l),splay(r);
	root=Q.front(),Q.pop(),build(root,1,tot);
	if (l)  t[l].ch[1]=root,t[root].f=l;  else  t[r].ch[0]=root,t[root].f=r;
	updata(l),updata(r);
}

void dfs_del(int n)
{
	if (t[n].ch[0])  dfs_del(t[n].ch[0]);
	if (t[n].ch[1])  dfs_del(t[n].ch[1]);
	Q.push(n),memset(t+n,0,sizeof(t[n]));
}

void del()
{
	int posi=getint(),tot=getint(),l,r;
	l=rank(posi-1),r=rank(posi+tot);
	splay(l),splay(r);
	if (l)  dfs_del(t[l].ch[1]),t[l].ch[1]=0;
	else  dfs_del(t[r].ch[0]),t[r].ch[0]=0;
	updata(l),updata(r);
}

void make_same()
{
	int posi=getint(),tot=getint(),c=getint(),l,r;
	l=rank(posi-1),r=rank(posi+tot);
	splay(l),splay(r);
	if (l)  plus1(t[l].ch[1],c);  else  plus1(t[r].ch[0],c);
	updata(l),updata(r);
}

void reverse()
{
	int posi=getint(),tot=getint(),l,r;
	l=rank(posi-1),r=rank(posi+tot);
	splay(l),splay(r);
	if (l)  plus2(t[l].ch[1]);  else  if (r)  plus2(t[r].ch[0]);  else  plus2(root);
	updata(l),updata(r);
}

int get_sum()
{
	int posi=getint(),tot=getint(),l,r;
	l=rank(posi-1),r=rank(posi+tot);
	splay(l),splay(r);
	if (l)  return t[t[l].ch[1]].sum;
	else  return t[t[r].ch[0]].sum;
}

int max_sum(){return t[root].m;}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=500000; i++)  Q.push(i);
	t[0].l=t[0].r=t[0].m=-oo;
	root=Q.front(),Q.pop(),build(root,1,n);
	char ch[9];
	for (int i=1; i<=m; i++)
		{
			scanf("\n%s",ch);
			if (ch[0]=='I')  insert();
			if (ch[0]=='D')  del();
			if (ch[0]=='M')
				{
					if (ch[2]=='K')  make_same();
					else  printf("%d\n",max_sum());
				}
			if (ch[0]=='R')  reverse();
			if (ch[0]=='G')  printf("%d\n",get_sum());
		}
}

int main()
{
	freopen("1500.in","r",stdin);
	freopen("1500.out","w",stdout);
	work();
	return 0;
}
