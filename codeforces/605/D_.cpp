#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#define Ls(n)  (n<<1)
#define Rs(n)  (Ls(n)|1)
using namespace std;

struct node{int a,b,c,d;}a[100010];
int n,m,mx,my,rt[100010],b[100010],t[400010],t2[400010],f[100010],pre[100010];
vector <int> V[100010];
queue <int> Q;

bool cmp(int x,int y){return a[x].b<a[y].b;}

int find(int x)
{
	int l=1,r=m+1,mid;
	for (; r-l>1; b[mid=(l+r)>>1]<=x?l=mid:r=mid);
	return l;
}

void modify(int n,int l,int r,int x,int k)
{
	t[n]++,t2[n]=min(t2[n],k);
	if (l!=r)
		{
			int mid=(l+r)>>1;
			x<=mid?modify(Ls(n),l,mid,x,k):modify(Rs(n),mid+1,r,x,k);
		}
}

int update(int k,int x)
{
	if (a[x].d<a[V[k][0]].b)  return 0;
	int res=0,y;
	while ((V[k].size())&&(a[V[k][0]].b<=a[x].d))
		y=V[k][0],Q.push(y),f[y]=f[x]+1,pre[y]=x,res++,V[k].erase(V[k].begin());
	return res;
}

void search(int n,int l,int r,int x)
{
	if ((!t[n])||(t2[n]>a[x].d))  return;
	if (l==r)  t[n]-=update(l,x),t2[n]=V[l].size()?a[V[l][0]].b:(1<<30);
	else
		{
			int mid=(l+r)>>1;
			search(Ls(n),l,mid,x);
			if (mid<a[x].c)  search(Rs(n),mid+1,r,x);
			t[n]=t[Ls(n)]+t[Rs(n)];
		}
}

void print(int x){if (x)  print(pre[x]),printf("%d ",x);}

void work()
{
	scanf("%d",&n),m=0;
	for (int i=1; i<=n; i++)
		{
			scanf("%d %d %d %d",&a[i].a,&a[i].b,&a[i].c,&a[i].d);
			if ((!a[i].a)&&(!a[i].b))  m++;
		}
	if (!m)  {printf("-1");  return;}
	for (int i=1; i<=n; i++)  b[i]=a[i].a;
	sort(b+1,b+n+1),m=n,mx=n;
	for (int i=1,t=0; i<=n; i++)
		if ((b[i]==b[i+1])&&(i!=n))  t++,m--,mx--;  else  b[i-t]=b[i];
	for (int i=1; i<=n; i++)  a[i].a=find(a[i].a),a[i].c=find(a[i].c);
	for (int i=1; i<=n; i++)  b[i]=a[i].b;
	sort(b+1,b+n+1),m=n,my=n;
	for (int i=1,t=0; i<=n; i++)
		if ((b[i]==b[i+1])&&(i!=n))  t++,m--,my--;  else  b[i-t]=b[i];
	for (int i=1; i<=n; i++)  a[i].b=find(a[i].b),a[i].d=find(a[i].d);
	memset(t2,127,sizeof(t2));
	for (int i=1; i<=n; i++)
		if ((a[i].a==1)&&(a[i].b==1))  Q.push(i),f[i]=1;
		else  V[a[i].a].push_back(i),modify(1,1,mx,a[i].a,a[i].b);
	for (int i=1; i<=mx; i++)  sort(V[i].begin(),V[i].end(),cmp);
	while (!Q.empty())
		{
			int x=Q.front();  Q.pop();
			search(1,1,mx,x);
		}
	if (f[n])  printf("%d\n",f[n]),print(n);
	else  printf("-1");
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
