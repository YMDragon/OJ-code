#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define Ls(n)  (n<<1)
#define Rs(n)  (Ls(n)|1)
using namespace std;

typedef long long  LL;
const LL oo=1LL<<60;
struct node{LL f,mf,g,mg;}t[2000010],tag;//max(x+f,g)
int n,m,a[500010];

void build(int n,int l,int r)
{
	if (l==r)  t[n]=(node){0,0,a[l],a[l]};
	else
		{
			int mid=(l+r)>>1;
			build(Ls(n),l,mid),build(Rs(n),mid+1,r);
			t[n]=(node){0,0,-oo,-oo};
		}
}

void merge(node &x,node y)
{
	x=(node){max(x.f+y.f,-oo),max(x.mf,x.f+y.mf),max(x.g+y.f,y.g),max(max(x.mg,y.mg),x.g+y.mf)};
}

void push_down(int n)
{
	merge(t[Ls(n)],t[n]),merge(t[Rs(n)],t[n]);
	t[n]=(node){0,0,-oo,-oo};
}

void modify(int n,int l,int r,int L,int R)
{
	if ((L<=l)&&(r<=R))  merge(t[n],tag);
	else
		{
			int mid=(l+r)>>1;
			push_down(n);
			if (L<=mid)  modify(Ls(n),l,mid,L,R);
			if (mid<R)  modify(Rs(n),mid+1,r,L,R);
		}
}

LL ask(int n,int l,int r,int x)
{
	if (l==r)  return max(t[n].f,t[n].g);
	else
		{
			int mid=(l+r)>>1;
			push_down(n);
			return x<=mid?ask(Ls(n),l,mid,x):ask(Rs(n),mid+1,r,x);
		}
}

LL ask_(int n,int l,int r,int x)
{
	if (l==r)  return max(t[n].mf,t[n].mg);
	else
		{
			int mid=(l+r)>>1;
			push_down(n);
			return x<=mid?ask_(Ls(n),l,mid,x):ask_(Rs(n),mid+1,r,x);
		}
}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	build(1,1,n);
	for (int i=1,ty,l,r,x; i<=m; i++)
		{
			scanf("%d",&ty);
			if (ty<=3)  scanf("%d %d %d",&l,&r,&x);  else  scanf("%d",&x);
			if (ty==1)  tag=(node){x,x,-oo,-oo},modify(1,1,n,l,r);
			if (ty==2)  tag=(node){-x,-x,0,0},modify(1,1,n,l,r);
			if (ty==3)  tag=(node){-oo,-oo,x,x},modify(1,1,n,l,r);
			if (ty==4)  printf("%lld\n",ask(1,1,n,x));
			if (ty==5)  printf("%lld\n",ask_(1,1,n,x));
		}
}

int main()
{
	freopen("164.in","r",stdin);
	freopen("164.out","w",stdout);
	work();
	return 0;
}
