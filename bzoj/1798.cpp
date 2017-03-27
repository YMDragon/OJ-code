#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define L(x)  (x<<1)
#define R(x)  ((x<<1)+1)
#define mid(x)  ((t[x].l+t[x].r)>>1)
using namespace std;

typedef long long  LL;
struct node{LL sum,t1,t2,l,r;}t[400010];
int n,p,m,a[100010],tot,l,r,k;

void build(int n,int l,int r)
{
	t[n].l=l,t[n].r=r,t[n].t1=1,t[n].t2=0;
	if (l==r)
		t[n].sum=a[l];
	else
		{
			build(L(n),l,mid(n)),build(R(n),mid(n)+1,r);
			t[n].sum=(t[L(n)].sum+t[R(n)].sum)%p;
		}
}

void pluss1(int n,int k)
{
	t[n].sum=t[n].sum*k%p,t[n].t1=t[n].t1*k%p,t[n].t2=t[n].t2*k%p;
}

void pluss2(int n,int k)
{
	t[n].sum=(t[n].sum+(t[n].r-t[n].l+1)*k%p)%p,t[n].t2=(t[n].t2+k)%p;
}

void push(int n)
{
	if (t[n].t1!=1)  pluss1(L(n),t[n].t1),pluss1(R(n),t[n].t1);
	if (t[n].t2)  pluss2(L(n),t[n].t2),pluss2(R(n),t[n].t2);
	t[n].t1=1,t[n].t2=0;
}

void updata1(int n)
{
	if ((l<=t[n].l)&&(t[n].r<=r))  pluss1(n,k);
	else
		{
			push(n);
			if (l<=mid(n))  updata1(L(n));
			if (r>mid(n))  updata1(R(n));
			t[n].sum=(t[L(n)].sum+t[R(n)].sum)%p;
		}
}

void updata2(int n)
{
	if ((l<=t[n].l)&&(t[n].r<=r))  pluss2(n,k);
	else
		{
			push(n);
			if (l<=mid(n))  updata2(L(n));
			if (r>mid(n))  updata2(R(n));
			t[n].sum=(t[L(n)].sum+t[R(n)].sum)%p;
		}
}

LL ask(int n)
{
	if ((l<=t[n].l)&&(t[n].r<=r))  return t[n].sum;
	push(n);
	LL res=0;
	if (l<=mid(n))  res=(res+ask(L(n)))%p;
	if (r>mid(n))  res=(res+ask(R(n)))%p;
	t[n].sum=(t[L(n)].sum+t[R(n)].sum)%p;
	return res%p;
}

void work()
{
	scanf("%d %d",&n,&p);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&m);
	int c;
	for (int i=1; i<=m; i++)
		{
			scanf("%d %d %d",&c,&l,&r);
			if (c==1)  {scanf("%d",&k);  updata1(1);}
			if (c==2)  {scanf("%d",&k);  updata2(1);}
			if (c==3)  printf("%d\n",int(ask(1)));
		}
}

int main()
{
	freopen("1798.in","r",stdin);
	freopen("1798.out","w",stdout);
	work();
	return 0;
}
