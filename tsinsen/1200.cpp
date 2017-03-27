#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define ls(n)  t[n].ch[0]
#define rs(n)  t[n].ch[1]
using namespace std;
typedef long long  LL;
struct node{int x,sum,s,f,ch[2],t1,t2;  LL ssum;}t[200010];
int n,m,tot,root,d[200010];
double sqr(double x){return x*x;}
void updata(int x)
{
	t[x].s=t[ls(x)].s+t[rs(x)].s+1;
	t[x].sum=t[ls(x)].sum+t[rs(x)].sum+t[x].x;
	t[x].ssum=t[ls(x)].ssum+t[rs(x)].ssum+t[x].x*t[x].x;
}
void push_add(int x,int k)
{
	t[x].x+=k,t[x].sum+=1LL*k*t[x].s,t[x].ssum+=2LL*t[x].sum*k-1LL*t[x].s*k*k,t[x].t1+=k;
}
void push_mul(int x,int k)
{
	t[x].x*=k,t[x].sum*=k,t[x].ssum*=k*k,t[x].t1*=k,t[x].t2*=k;
}
void pushdown(int x)
{
	if (t[x].t2!=1)  push_mul(ls(x),t[x].t2),push_mul(rs(x),t[x].t2),t[x].t2=1;
	if (t[x].t1!=0)  push_add(ls(x),t[x].t1),push_add(rs(x),t[x].t1),t[x].t1=0;
}
int build(int l,int r)
{
	if (l>r)  return 0;
	int x=++tot;
	if (l==r)
		{
			scanf("%d",&t[x].x);
		}else
		{
			int mid=(l+r)>>1;
			ls(x)=build(l,mid-1),t[ls(x)].f=x;
			scanf("%d",&t[x].x);
			rs(x)=build(mid+1,r),t[rs(x)].f=x;
		}
	updata(x),t[x].t2=1;
	return x;
}
void rotate(int x)
{
	int f=t[x].f,ff=t[f].f,q=(t[f].ch[1]==x),ch=t[x].ch[q^1];
	if (ff)  t[ff].ch[t[ff].ch[1]==f]=x;  else  root=x;  t[x].f=ff;
	t[f].ch[q]=ch;  if (ch)  t[ch].f=f;
	t[x].ch[q^1]=f,t[f].f=x;
	updata(f),updata(x);
}
void splay(int x)
{
	if (!x)  return;
	int y=x,m=0;
	while (y)  d[++m]=y,y=t[y].f;
	while (m)  pushdown(d[m--]);
	while (t[x].f)  rotate(x);
}
int rank(int k)
{
	int x=root;
	while (x)
		{
			if (t[ls(x)].s+1==k)  return x;
			if (t[ls(x)].s>=k)  x=ls(x);
			else  k-=t[ls(x)].s+1,x=rs(x);
		}
	return x;
}
double query(int l,int r)
{
	int x,L=rank(l-1),R=rank(r+1);
	splay(L),splay(R);
	if (L)  x=rs(L);  else  if (R)  x=ls(R);  else  x=root;
	return (t[x].ssum*t[x].s-1LL*t[x].sum*t[x].sum)/(1.0*t[x].s*t[x].s);
}
void add(int l,int r,int k)
{
	int x,L=rank(l-1),R=rank(r+1);
	splay(L),splay(R);
	if (L)  x=rs(L);  else  if (R)  x=ls(R);  else  x=root;
	push_add(x,k);
	if (L)  updata(L);  if (R)  updata(R);
}
void mul(int l,int r,int k)
{
	int x,L=rank(l-1),R=rank(r+1);
	splay(L),splay(R);
	if (L)  x=rs(L);  else  if (R)  x=ls(R);  else  x=root;
	push_mul(x,k);
	if (L)  updata(L);  if (R)  updata(R);
}
void move(int l,int r)
{
	int L=rank(l-1),R=rank(r+1),rr=rank(r);
	splay(rr),splay(L),splay(R);
	swap(ls(rr),rs(rr));
}
void work()
{
	scanf("%d %d",&n,&m);
	root=build(1,n);
	for (int i=1,l,r,k; i<=m; i++)
		{
			char ch;
			do  ch=getchar();  while ((ch!='Q')&&(ch!='A')&&(ch!='M')&&(ch!='C'));
			scanf("%d %d",&l,&r);
			if ((ch=='A')||(ch=='M'))  scanf("%d",&k);
			if (ch=='Q')  printf("%.3lf\n",query(l,r));
			if (ch=='A')  add(l,r,k);
			if (ch=='M')  mul(l,r,k);
			if (ch=='C')  move(l,r);
		}
}
int main()
{
	freopen("1200.in","r",stdin);
	freopen("1200.out","w",stdout);
	work();
	return 0;
}
