#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

const int oo=1<<30;
struct edge{int s,t,c,n;}e[3300000];
int n,m,tot,S,T,a[405],b[405],h[1700000],nh[1700000],dis[1700000],vis[1700000],ans,p[405][10];
queue <int> Q;
map <int,int> M,M1,M2;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int find(int x){if (!M[x])  M[x]=++m;  return M[x];}

void addedge(int s,int t,int c)
{
	e[++tot]=(edge){s,t,c,h[s]},h[s]=tot;
	e[++tot]=(edge){t,s,0,h[t]},h[t]=tot;
}

bool bfs()
{
	int x,y,i;
	while (!Q.empty())  Q.pop();
	Q.push(T),vis[T]=++tot,dis[T]=0;
	while (!Q.empty())
		for (i=h[x=Q.front()],Q.pop(); y=e[i].t,i; i=e[i].n)
			if ((e[i^1].c)&&(vis[y]!=tot))
				{
					vis[y]=tot,dis[y]=dis[x]+1,Q.push(y),nh[y]=h[y];
					if (y==S)  return 1;
				}
	return 0;
}

int dfs(int x,int a)
{
	if ((x==T)||(!a))  return a;
	int flow=0,y;
	for (int &i=nh[x]; y=e[i].t,i; i=e[i].n)
		if ((e[i].c)&&(vis[y]==tot)&&(dis[y]+1==dis[x]))
			{
				int t=dfs(y,min(a,e[i].c));
				e[i].c-=t,e[i^1].c+=t,flow+=t,a-=t;
				if (!a)  return flow;
			}
	dis[x]=oo;
	return flow;
}

void clear()
{
	tot=1,S=1,T=2,m=2,ans=0;
	M.clear(),M1.clear(),M2.clear();
	memset(p,0,sizeof(p));
	memset(h,0,sizeof(h));
	memset(vis,0,sizeof(vis));
}

void work()
{
	scanf("%d",&n),clear();
	for (int i=1,x; i<=n; i++)
		{
			scanf("%d",&a[i]),x=a[i];
			for (int j=2; j<=sqrt(x); j++)
				if (x%j==0)
					{
						p[i][++p[i][0]]=j;
						while (x%j==0)  x/=j;
					}
			if (x!=1)  p[i][++p[i][0]]=x;
		}
	for (int i=1; i<=n; i++)  scanf("%d",&b[i]);
	for (int i=1; i<=n; i++)
		for (int j=1,g,x; j<=n; j++)
			if ((g=gcd(a[i],b[j]))!=1)
				{
					if (a[i]<b[j])
						{
							if (M1[g])  e[M1[g]].c++;
							else
								{
									x=++m;
									addedge(S,x,1);
									M1[g]=tot-1;
									for (int k=1; k<=p[i][0];  k++)
										if (g%p[i][k]==0)
											addedge(x,find(p[i][k]),oo);
								}
						}
					if (a[i]>b[j])
						{
							if (M2[g])  e[M2[g]].c++;
							else
								{
									x=++m;
									addedge(x,T,1);
									M2[g]=tot-1;
									for (int k=1; k<=p[i][0]; k++)
										if (g%p[i][k]==0)
											addedge(find(p[i][k]),x,oo);
								}
						}
				}
	tot=0;
	while (bfs())  ans+=dfs(S,oo);
	printf("%d\n",ans);
}

int main()
{
	freopen("GNUM.in","r",stdin);
	freopen("GNUM.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
