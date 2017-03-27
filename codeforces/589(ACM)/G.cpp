#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define Ls(n)  (n<<1)
#define Rs(n)  (Ls(n)|1)
#define lowbit(x)  (x&-x)
#define mp  make_pair
#define pb  push_back
#define FILENAME "G" 
using namespace std;

typedef long long  LL;
typedef pair<int,int>  PII;

struct node{int d,r,ans,id;}a[200010];
struct Node{LL sum,s;}tree[800010];
int n,m,t[200010];
priority_queue <PII,vector<PII>,greater<PII> > Q;

int getint()
{
	int w=0,p=1;  char ch=getchar();
	while (((ch<'0')||(ch>'9'))&&(ch!='-'))  ch=getchar();
	if (ch=='-')  p=0,ch=getchar();
	while (('0'<=ch)&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return p?w:-w;
}

void printint(int x)
{
	if (x<0)  putchar('-'),x=-x;
	if (x>=10)  printint(x/10);
	putchar(x%10+'0');
}

Node operator + (Node x,Node y){return (Node){x.sum+y.sum,x.s+y.s};}

bool cmpd(node x,node y){return x.d<y.d;}
bool cmpid(node x,node y){return x.id<y.id;}

void build(int n,int l,int r)
{
	if (l==r)  tree[n]=(Node){t[l],1};
	else
		{
			int mid=(l+r)>>1;
			build(Ls(n),l,mid),build(Rs(n),mid+1,r);
			tree[n]=tree[Ls(n)]+tree[Rs(n)];
		}
}

void modify(int n,int l,int r,int x)
{
	if (l==r)  tree[n]=(Node){0,0};
	else
		{
			int mid=(l+r)>>1;
			if (x<=mid)  modify(Ls(n),l,mid,x);  else  modify(Rs(n),mid+1,r,x);
			tree[n]=tree[Ls(n)]+tree[Rs(n)];
		}
}

Node ask(int n,int l,int r,int R)
{
	if (r<=R)  return tree[n];
	else
		{
			int mid=(l+r)>>1;  Node res;
			res=ask(Ls(n),l,mid,R);
			if (mid<R)  res=res+ask(Rs(n),mid+1,r,R);
			return res;
		}
}

void work()
{
	n=getint(),m=getint();
	for (int i=1; i<=m; i++)  t[i]=getint(),Q.push(mp(t[i],i));
	for (int i=1; i<=n; i++)  a[i].d=getint(),a[i].r=getint(),a[i].id=i;
	sort(a+1,a+n+1,cmpd);
	build(1,1,m);
	for (int i=1; i<=n; i++)
		{
			while ((!Q.empty())&&(a[i].d>=Q.top().first))
				modify(1,1,m,Q.top().second),Q.pop();
			int l=0,r=m+1,mid;
			while (r-l>1)
				{
					mid=(l+r)>>1;
					Node x=ask(1,1,m,mid);
					if (x.sum-x.s*a[i].d>=a[i].r)  r=mid;  else  l=mid;
				}
			if (r==m+1)  a[i].ans=0;  else  a[i].ans=r;
		}
	sort(a+1,a+n+1,cmpid);
	for (int i=1; i<=n; i++)  printf("%d ",a[i].ans);
}

int main()
{
	freopen(FILENAME".in","r",stdin);
	freopen(FILENAME".out","w",stdout);
	work();
	return 0;
}
