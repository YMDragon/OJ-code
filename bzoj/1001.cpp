#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

struct edge{int s,t,d,n;}e[6000010];
int n,m,h[2000010],S,T,tot,dis[2000010],b[2000010];
queue <int> Q;

int gp(int x,int y,int k){return (x-1)*(m-1)+y+k*(n-1)*(m-1);}

int getint()
{
	char ch=getchar();
	int w=0;
	while ((ch<'0')||(ch>'9'))  ch=getchar();
	while ((ch>='0')&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return w;
}

void addedge(int s,int t,int d)
{
	e[++tot]=(edge){s,t,d,h[s]},h[s]=tot;
	e[++tot]=(edge){t,s,d,h[t]},h[t]=tot;
}

int SPFA(int s,int t)
{
	int x,y,i;
	for (int i=1; i<=2*(n-1)*(m-1)+2; i++)  dis[i]=(1<<30);
	Q.push(s),dis[s]=0,b[s]=1;
	while (!Q.empty())
		for (i=h[x=Q.front()],Q.pop(),b[x]=0; y=e[i].t,i; i=e[i].n)
			{
				if (dis[x]+e[i].d<dis[y])
					{
						dis[y]=dis[x]+e[i].d;
						if (!b[y])  Q.push(y),b[y]=1;
					}
			}
	return dis[t];
}

void work()
{
	scanf("%d %d",&n,&m);
	if ((n==1)||(m==1))
		{
			int ans=1<<30;
			for (int i=1; i<=n+m-2; i++)
				ans=min(ans,getint());
			printf("%d\n",ans);
			return;
		}
	S=2*(n-1)*(m-1)+1,T=S+1;
	for (int j=1; j<m; j++)
		addedge(gp(1,j,0),T,getint());
	for (int i=2; i<n; i++)
		for (int j=1; j<m; j++)
			addedge(gp(i,j,0),gp(i-1,j,1),getint());
	for (int j=1; j<m; j++)
		addedge(S,gp(n-1,j,1),getint());
	for (int i=1; i<n; i++)
		{
			addedge(S,gp(i,1,1),getint());
			for (int j=2; j<m; j++)
				addedge(gp(i,j-1,0),gp(i,j,1),getint());
			addedge(gp(i,m-1,0),T,getint());
		}
	for (int i=1; i<n; i++)
		for (int j=1; j<m; j++)
			addedge(gp(i,j,1),gp(i,j,0),getint());
	printf("%d\n",SPFA(S,T));
}

int main()
{
	freopen("1001.in","r",stdin);
	freopen("1001.out","w",stdout);
	work();
	return 0;
}
