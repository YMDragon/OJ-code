#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

struct edge{int s,t,n;}e[200010];
vector <int> V[2000010];
int n,q,m,tot,a[100010],ans[100010],h[100010],d[100010],p[2000010];

void getp()
{
	for (int i=2; i<=2e6; i++)
		{
			if (p[i])  continue;
			for (int j=i; j<=2e6; j+=i)  p[j]=i;
		}
}

void dfs(int x,int deep,int f)
{
	vector <int> P;
	int q=a[x],pp;
	d[x]=deep;
	while (q!=1)
		{
			pp=p[q],P.push_back(pp);
			while (q%pp==0)  q/=pp;
		}
	for (int i=0; i<int(P.size()); i++)
		{
			if ((V[P[i]].size())&&((ans[x]==-1)||(d[ans[x]]<d[V[P[i]].back()])))
				ans[x]=V[P[i]].back();
			V[P[i]].push_back(x);
		}
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=f)  dfs(y,deep+1,x);
	for (int i=0; i<int(P.size()); i++)
		V[P[i]].pop_back();
}

void build()
{
	for (int i=1; i<=n; i++) ans[i]=-1;
	dfs(1,1,0);
}

void work()
{
	scanf("%d %d",&n,&q);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for (int i=1,x,y; i<n; i++)
		{
			scanf("%d %d",&x,&y);
			e[++tot]=(edge){x,y,h[x]},h[x]=tot;
			e[++tot]=(edge){y,x,h[y]},h[y]=tot;
		}
	getp(),build();
	for (int i=1,o,v,w; i<=q; i++)
		{
			scanf("%d %d",&o,&v);
			if (o==1)  printf("%d\n",ans[v]);
			else  scanf("%d",&w),a[v]=w,build();
		}
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
