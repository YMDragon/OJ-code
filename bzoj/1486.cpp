#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

struct edge{int s,t,n;  double d;}e[10010],E[10010];
int n,m,tot,h[3010],in[3010],vis[3010],Vis[3010];
double dis[3010];
queue <int> Q;

bool check(double res)
{
	int x,y,i;
	for (i=1; i<=m; i++)
		E[i].d=e[i].d-res;
	for (i=1; i<=n; i++)  in[i]=Vis[i]=0;
	while (!Q.empty())  Q.pop();
	dis[1]=0,vis[1]=++tot,Q.push(1),in[1]=Vis[i]=1;
	while (!Q.empty())
		for (i=h[x=Q.front()],Q.pop(),in[x]=0; y=e[i].t,i; i=e[i].n)
			if ((vis[y]!=tot)||(dis[y]>dis[x]+E[i].d))
				{
					vis[y]=tot,dis[y]=dis[x]+E[i].d;
					if (!in[y])  Q.push(y),in[y]=1;
					if ((++Vis[y])>sqrt(n))  return 1;
				}
	return 0;
}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=m; i++)
		scanf("%d %d %lf",&e[i].s,&e[i].t,&e[i].d),e[i].n=h[e[i].s],h[e[i].s]=i;
	double l=-10e7,r=10e7,mid;
	while (r-l>1e-9)
		{
			mid=(l+r)/2;
			if (check(mid))  r=mid;  else  l=mid;
		}
	printf("%.8lf",r);
}

int main()
{
	freopen("1486.in","r",stdin);
	freopen("1486.out","w",stdout);
	work();
	return 0;
}
