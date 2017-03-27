#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define LL  long long
#define oo  (1<<30)
#define mo  1000000009
#define Ls  (n<<1)
#define Rs  ((n<<1)+1)
#define mid ((l+r)>>1)
using namespace std;

struct node{int s,f1,f2;}t[1200010];
int n,m,fib[300010];

void build(int l,int r,int n)
{
	t[n].f1=t[n].f2=0;
	if (l!=r)
		build(l,mid,Ls),build(mid+1,r,Rs),t[n].s=(t[Ls].s+t[Rs].s)%mo;
	else
		scanf("%d",&t[n].s);
}

int getf(int a,int b,int n)
{
	if (n==1)  return a;
	if (n==2)  return b;
	return (1LL*a*fib[n-2]%mo+1LL*b*fib[n-1]%mo)%mo;
}
int getsum(int a,int b,int n){return (getf(a,b,n+2)-b+mo)%mo;}

void push(int l,int r,int n)
{
	if (t[n].f1)
		{
			int x=t[n].f1,y=t[n].f2,ox=x,oy=y,ll=mid-l+1,rl=r-mid;
			t[Ls].f1=(t[Ls].f1+x)%mo,t[Ls].f2=(t[Ls].f2+y)%mo;
			t[Ls].s=(t[Ls].s+getsum(x,y,ll))%mo;
			x=getf(ox,oy,ll+1),y=getf(ox,oy,ll+2);
			t[Rs].f1=(t[Rs].f1+x)%mo,t[Rs].f2=(t[Rs].f2+y)%mo;
			t[Rs].s=(t[Rs].s+getsum(x,y,rl))%mo;
			t[n].f1=t[n].f2=0;
		}
}

void updata(int ll,int rr,int l,int r,int n)
{
	if ((ll<=l)&&(r<=rr))
		{
			t[n].f1=(t[n].f1+fib[l-ll+1])%mo,t[n].f2=(t[n].f2+fib[l-ll+2])%mo;
			t[n].s=(t[n].s+getsum(fib[l-ll+1],fib[l-ll+2],r-l+1))%mo;
		}else
		{
			push(l,r,n);
			if (ll<=mid)  updata(ll,rr,l,mid,Ls);
			if (mid<rr)  updata(ll,rr,mid+1,r,Rs);
			t[n].s=(t[Ls].s+t[Rs].s)%mo;
		}
}

int query(int ll,int rr,int l,int r,int n)
{
	if ((ll<=l)&&(r<=rr))
		return t[n].s;
	else
		{
			push(l,r,n);
			int res=0;
			if (ll<=mid)  res+=query(ll,rr,l,mid,Ls);
			if (mid<rr)  res+=query(ll,rr,mid+1,r,Rs);
			t[n].s=(t[Ls].s+t[Rs].s)%mo;
			return res%mo;
		}
}

void work()
{
	scanf("%d %d",&n,&m);
	fib[1]=fib[2]=1;
	for (int i=3; i<=n+2; i++)  fib[i]=(fib[i-1]+fib[i-2])%mo;
	build(1,n,1);
	for (int i=1,k,l,r; i<=m; i++)
		{
			scanf("%d %d %d",&k,&l,&r);
			if (k==1)  updata(l,r,1,n,1);
			else  printf("%d\n",query(l,r,1,n,1));
		}
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
