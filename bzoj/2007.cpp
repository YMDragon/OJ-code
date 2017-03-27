#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#define p(x,y)  ((x-1)*n+y)
#define oo  (1<<30)
using namespace std;
struct node{
	int x,dis;
	bool operator < (const node &B) const {
		return dis > B.dis;
	}
};
struct edge{int s,t,d,n;}e[1010000];
int n,S,T,tot,h[260000],dis[260000],vis[260000];

int getint()
{
	int w=0;
	char ch=getchar();
	while ((ch<'0')||(ch>'9'))  ch=getchar();
	while ((ch>='0')&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return w;
}

void addedge(int s,int t,int d)
{
	e[++tot]=(edge){s,t,d,h[s]},h[s]=tot;
}

int SPFA(int s,int t)
{
	node x,y;
	priority_queue <node> Q;
	for (int i=1; i<=T; i++)  dis[i]=oo;
	Q.push((node){s,0}),dis[s]=0;
	while (!Q.empty())
		{
			x=Q.top(),Q.pop();
			if (x.dis==dis[x.x])
				for (int i=h[x.x]; y=(node){e[i].t,0},i; i=e[i].n)
					if (dis[y.x]>dis[x.x]+e[i].d)
						y.dis=dis[y.x]=dis[x.x]+e[i].d,Q.push(y);
		}
	return dis[t];
}

void work()
{
	scanf("%d",&n);
	S=n*n+1,T=n*n+2;
	for (int i=1; i<=n; i++)
		addedge(S,p(1,i),getint());
	for (int i=1; i<n; i++)
		for (int j=1; j<=n; j++)
			addedge(p(i,j),p(i+1,j),getint());
	for (int i=1; i<=n; i++)
		addedge(p(n,i),T,getint());
	for (int i=1; i<=n; i++)
		{
			addedge(p(i,1),T,getint());
			for (int j=1; j<n; j++)
				addedge(p(i,j+1),p(i,j),getint());
			addedge(S,p(i,n),getint());
		}
	for (int i=1; i<=n; i++)
		addedge(p(1,i),S,getint());
	for (int i=1; i<n; i++)
		for (int j=1; j<=n; j++)
			addedge(p(i+1,j),p(i,j),getint());
	for (int i=1; i<=n; i++)
		addedge(T,p(n,i),getint());
	for (int i=1; i<=n; i++)
		{
			addedge(T,p(i,1),getint());
			for (int j=1; j<n; j++)
				addedge(p(i,j),p(i,j+1),getint());
			addedge(p(i,n),S,getint());
		}
	printf("%d",SPFA(S,T));
}

int main()
{
	freopen("2007.in","r",stdin);
	freopen("2007.out","w",stdout);
	work();
	return 0;
}
