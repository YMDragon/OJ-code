#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const int oo=int(1e9);
struct node{int a,b,c,d;}a[200010];
struct node2{int a,b,c,d,e;}b[100010];
struct Tnode{int s,ls,rs;}t[4000010];
int n,m,root,tot;
LL ans;

bool cmp(node x,node y){return (x.a<y.a)||((x.a==y.a)&&(x.d>y.d));}

bool cmp2(node2 x,node2 y)
{
	if (x.e!=y.e)  return x.e>y.e;
	if (x.e)  return (x.a<y.a)||((x.a==y.a)&&(x.b<y.b));
	else  return (x.b<y.b)||((x.b==y.b)&&(x.a<y.a));
}

void modify(int &n,int l,int r,int x,int p)
{
	if (n==0)  n=++tot;
	if (l==r)  t[n].s+=p;
	else
		{
			int mid=(l+r)>>1;
			x<=mid?modify(t[n].ls,l,mid,x,p):modify(t[n].rs,mid+1,r,x,p);
			t[n].s=t[t[n].ls].s+t[t[n].rs].s;
		}
}

int query(int n,int l,int r,int L,int R)
{
	if ((n==0)||((L<=l)&&(r<=R)))  return t[n].s;
	else
		{
			int mid=(l+r)>>1,res=0;
			if (L<=mid)  res+=query(t[n].ls,l,mid,L,R);
			if (mid<R)  res+=query(t[n].rs,mid+1,r,L,R);
			return res;
		}
}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		{
			scanf("%d %d %d %d",&b[i].a,&b[i].b,&b[i].c,&b[i].d);
			if (b[i].a>b[i].c)  swap(b[i].a,b[i].c);
			if (b[i].b>b[i].d)  swap(b[i].b,b[i].d);
			if (b[i].a==b[i].c)  b[i].e=1;
		}
	sort(b+1,b+n+1,cmp2);
	for (int i=1; i<n; i++)
		if ((b[i].e)&&(b[i+1].e))
			{
				if ((b[i].a==b[i+1].a)&&(b[i].d>=b[i+1].b))
					b[i+1].b=b[i].b,b[i+1].d=max(b[i+1].d,b[i].d),b[i].e=-1;
			}else  if ((!b[i].e)&&(!b[i+1].e))
			{
				if ((b[i].b==b[i+1].b)&&(b[i].c>=b[i+1].a))
					b[i+1].a=b[i].a,b[i+1].c=max(b[i+1].c,b[i].c),b[i].e=-1;
			}
	for (int i=1; i<=n; i++)
		if (b[i].e!=-1)
			{
				ans+=(b[i].c-b[i].a)+(b[i].d-b[i].b)+1;
				if (b[i].e)  a[++m]=(node){b[i].a,b[i].b,b[i].d,0};
				else  a[++m]=(node){b[i].a,b[i].b,0,1},a[++m]=(node){b[i].c,b[i].d,0,-1};
			}
	sort(a+1,a+m+1,cmp);
	for (int i=1; i<=m; i++)
		if (a[i].d)  modify(root,-oo,oo,a[i].b,a[i].d);
		else  ans-=query(root,-oo,oo,a[i].b,a[i].c);
	printf("%lld",ans);
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
