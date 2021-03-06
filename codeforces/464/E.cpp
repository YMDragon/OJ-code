#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#define mp  make_pair
using namespace std;

typedef pair<int,int>  PII;
const int mo=1000000007,MX=100000;
struct edge{int s,t,d,n;}e[200010];
struct node{int hs,l,r;}t[10000000];
int n,m,flag,tot,h[100010],S,T,b[100010],f[100010],root[100010],pow2[100010];

bool cmp(int u,int v)
{
	if ((!t[u].l)&&(!t[u].r))  return t[u].hs>t[v].hs;
	if (t[u].hs==t[v].hs)  return u>v;
	return (t[t[u].r].hs==t[t[v].r].hs)?cmp(t[u].l,t[v].l):cmp(t[u].r,t[v].r);
}

struct compile{bool operator () (PII u, PII v){return cmp(u.first,v.first);}};
priority_queue <PII,vector<PII>,compile> PQ;
deque <int> Q;

void updata(int n,int l,int r)
{
	int mid=(l+r)>>1;
	t[n].hs=(t[t[n].l].hs+1LL*t[t[n].r].hs*pow2[mid-l+1]%mo)%mo;
}

int add(int n,int l,int r,int k)
{
	t[++tot]=t[n],n=tot;
	if (l==r)
		if (t[n].hs)  flag=1,t[n].hs=0;  else  t[n].hs=1;
	else
		{
			int mid=(l+r)>>1;
			if (k<=mid)
				{
					t[n].l=add(t[n].l,l,mid,k);
					if (flag)  flag=0,t[n].r=add(t[n].r,mid+1,r,mid+1);
				}else
				t[n].r=add(t[n].r,mid+1,r,k);
			updata(n,l,r);
		}
	return n;
}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1,u,v,x,tot=0; i<=m; i++)
		{
			scanf("%d %d %d",&u,&v,&x);
			e[++tot]=(edge){u,v,x,h[u]},h[u]=tot;
			e[++tot]=(edge){v,u,x,h[v]},h[v]=tot;
		}
	scanf("%d %d",&S,&T);
	pow2[0]=1;
	for (int i=1; i<=MX+1; i++)  pow2[i]=pow2[i-1]*2%mo;
	for (int i=1; i<=n; i++)
		if (i!=S)  flag=0,root[i]=add(root[i],0,MX+20,MX+20);
	PQ.push(mp(root[S],S));
	while (!PQ.empty())
		{
			int x=PQ.top().second;  PQ.pop();
			if (x==T)
				{
					printf("%d\n",t[root[x]].hs),Q.push_back(T);
					while (x!=S)  x=f[x],Q.push_back(x);
					printf("%d\n",int(Q.size()));
					while (!Q.empty())  printf("%d ",Q.back()),Q.pop_back();
					return;
				}
			if (b[x])  continue;  else  b[x]=1;
			for (int i=h[x],y,rt; flag=0,y=e[i].t,i; i=e[i].n)
				if (cmp(root[y],rt=add(root[x],0,MX+20,e[i].d)))
					root[y]=rt,f[y]=x,PQ.push(mp(root[y],y));
		}
	printf("-1");
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
