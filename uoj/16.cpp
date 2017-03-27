#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

const int mo=10007;
struct edge{int s,t,n;}e[400010];
int n,tot,h[200010],w[200010],f[200010],Max,ans;

void bfs(int s)
{
	queue <int> Q;  int x,y,i;
	Q.push(s),f[s]=0;
	while (!Q.empty())
		for (i=h[x=Q.front()],Q.pop(); y=e[i].t,i; i=e[i].n)
			if (y!=f[x])  f[y]=x,Q.push(y);
}

void work()
{
	scanf("%d",&n);
	for (int i=1,u,v; i<n; i++)
		{
			scanf("%d %d",&u,&v);
			e[++tot]=(edge){u,v,h[u]},h[u]=tot;
			e[++tot]=(edge){v,u,h[v]},h[v]=tot;
		}
	for (int i=1; i<=n; i++)
		scanf("%d",&w[i]);
	bfs(1);
	for (int i=1; i<=n; i++)
		{
			ans=(ans+2*w[i]*w[f[f[i]]])%mo,Max=max(Max,w[i]*w[f[f[i]]]);
			int sum=0,m1=0,m2=0;
			for (int j=h[i],y; y=e[j].t,j; j=e[j].n)
				if (y!=f[i])
					{
						sum=(sum+w[y])%mo,ans=(ans-w[y]*w[y]%mo+mo)%mo;
						if (w[y]>m2)
							{
								m2=w[y];
								if (m2>m1)  swap(m1,m2);
							}
					}
			ans=(ans+sum*sum)%mo,Max=max(Max,m1*m2);
		}
	printf("%d %d",Max,ans);
}

int main()
{
	freopen("16.in","r",stdin);
	freopen("16.out","w",stdout);
	work();
	return 0;
}
