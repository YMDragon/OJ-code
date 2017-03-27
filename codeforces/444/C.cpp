#include <cstdlib>
#include <cstdio>
#include <cmath>
#define LL  long long
#define Ls(x)  (x<<1)
#define Rs(x)  ((x<<1)|1)
using namespace std;

struct node{int l,r;LL t,c,x;}t[800010];
int n,m;

void build(int l,int r,int n)
{
	if (l==r)  t[n]=(node){l,l,0,l,0};
	else
		{
			int mid=(l+r)>>1;
			t[n]=(node){l,r,0,0,0};
			build(l,mid,Ls(n)),build(mid+1,r,Rs(n));
		}
}

void pluss(int n,LL k)
{
	t[n].x+=k*(t[n].r-t[n].l+1),t[n].t+=k;
}

void push(int n)
{
	if (t[n].t)  pluss(Ls(n),t[n].t),pluss(Rs(n),t[n].t),t[n].t=0;
	if (t[n].c)  t[Ls(n)].c=t[Rs(n)].c=t[n].c;
}

void updata(int l,int r,LL c,int n)
{
	if ((l<=t[n].l)&&(t[n].r<=r)&&(t[n].c))
		{
			pluss(n,fabs(t[n].c-c));
			t[n].c=c;
		}else
		{
			push(n);
			int mid=(t[n].l+t[n].r)>>1;
			if (l<=mid)  updata(l,r,c,Ls(n));
			if (mid<r)  updata(l,r,c,Rs(n));
			t[n].x=t[Ls(n)].x+t[Rs(n)].x;
			t[n].c=(t[Ls(n)].c==t[Rs(n)].c)?(t[Ls(n)].c):0;
		}
}

LL query(int l,int r,int n)
{
	if ((l<=t[n].l)&&(t[n].r<=r))  return t[n].x;
	else
		{
			push(n);
			int mid=(t[n].l+t[n].r)>>1;LL res=0;
			if (l<=mid)  res+=query(l,r,Ls(n));
			if (mid<r)  res+=query(l,r,Rs(n));
			t[n].x=t[Ls(n)].x+t[Rs(n)].x;
			t[n].c=(t[Ls(n)].c==t[Rs(n)].c)?(t[Ls(n)].c):0;
			return res;
		}
}

void work()
{
	scanf("%d %d",&n,&m);
	build(1,n,1);
	for (int i=1,t,l,r,x; i<=m; i++)
		{
			scanf("%d",&t);
			if (t==1)  scanf("%d %d %d",&l,&r,&x),updata(l,r,x,1);
			else  scanf("%d %d",&l,&r),printf("%lld\n",query(l,r,1));
		}
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
