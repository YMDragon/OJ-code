#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define Ls(n)  (n<<1)
#define Rs(n)  (Ls(n)|1)
using namespace std;

int n,a[200010],p[200010],t[800010],tag[800010];

void build(int n,int l,int r)
{
	tag[n]=0;
	if (l==r)  t[n]=l-a[l];
	else
		{
			int mid=(l+r)>>1;
			build(Ls(n),l,mid),build(Rs(n),mid+1,r);
			t[n]=min(t[Ls(n)],t[Rs(n)]);
		}
}

void push_down(int n)
{
	t[Ls(n)]+=tag[n],tag[Ls(n)]+=tag[n];
	t[Rs(n)]+=tag[n],tag[Rs(n)]+=tag[n];
	tag[n]=0;
}

void modify(int n,int l,int r,int L,int R,int k)
{
	if (L>R)  return;
	if ((L<=l)&&(r<=R))  t[n]+=k,tag[n]+=k;
	else
		{
			int mid=(l+r)>>1;
			push_down(n);
			if (L<=mid)  modify(Ls(n),l,mid,L,R,k);
			if (mid<R)  modify(Rs(n),mid+1,r,L,R,k);
			t[n]=min(t[Ls(n)],t[Rs(n)]);
		}
}

int ask(int n,int l,int r)
{
	if (l==r)  {t[n]=::n+1;  return l;}
	else
		{
			int mid=(l+r)>>1,_;
			push_down(n);
			_=t[n]==t[Rs(n)]?ask(Rs(n),mid+1,r):ask(Ls(n),l,mid);
			t[n]=min(t[Ls(n)],t[Rs(n)]);
			return _;
		}
}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	build(1,1,n);
	for (int i=1,x; i<=n; i++)
		x=ask(1,1,n),p[x]=i,modify(1,1,n,1,x-1,1);
	for (int i=1; i<=n; i++)  printf("%d ",p[i]);  puts("");
}

int main()
{
	freopen("ORDERS.in","r",stdin);
	freopen("ORDERS.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
