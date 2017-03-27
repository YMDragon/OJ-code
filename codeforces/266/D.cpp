#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <ctime>
using namespace std;

struct edge{int s,t,d,n;}e[40010];
struct point{int x,y;}a[205];
int n,m,h[205],dis[205][205],vis[205],in[205],Z[205];
int ans;

int min(int x,int y){return x>y?y:x;}

void spfa(int s)
{
	queue <int> Q;  int x,y,i;
	Q.push(s),dis[s][s]=0,vis[s]=s,in[s]=1;
	while (!Q.empty())
		for (i=h[x=Q.front()],Q.pop(),in[x]=0;  y=e[i].t,i; i=e[i].n)
			if ((vis[y]!=s)||(dis[s][y]>dis[s][x]+e[i].d))
				{
					vis[y]=s,dis[s][y]=dis[s][x]+e[i].d;
					if (!in[y])  Q.push(y),in[y]=1;
				}
}

bool cmp(point x,point y){return (x.x<y.x)||((x.x==y.x)&&(x.y<y.y));}

point calc(int a,int b,int w)
{
	if (a+w<=b)  return (point){w*2,(a+w)*2};
	if (b+w<=a)  return (point){0*2,(b+w)*2};
	return (point){(w-a+b),(w+a+b)};
}

int calc(point x,point y){return (x.x-y.x+x.y+y.y);}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1,u,v,w,tot=0; i<=m; i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			e[++tot]=(edge){u,v,w,h[u]},h[u]=tot;
			e[++tot]=(edge){v,u,w,h[v]},h[v]=tot;
		}
	for (int i=1; i<=n; i++)  spfa(i);
	ans=1e10;
	for (int i=1; i<=2*m; i+=2)
		{
			for (int j=1; j<=n; j++)
				a[j]=calc(dis[e[i].s][j],dis[e[i].t][j],e[i].d);
			sort(a+1,a+n+1,cmp);
			int top=0;
			for (int j=1; j<=n; j++)
				{
					while ((top)&&(a[j].y-a[Z[top]].y>=a[j].x-a[Z[top]].x))  top--;
					if ((!top)||(a[Z[top]].y-a[j].y<a[j].x-a[Z[top]].x))  Z[++top]=j;
				}
			ans=min(ans,2*(a[Z[1]].y-a[Z[1]].x));
			for (int j=1; j<top; j++)
				ans=min(ans,calc(a[Z[j]],a[Z[j+1]]));
			ans=min(ans,2*(a[Z[top]].y-e[i].d+a[Z[top]].x));
		}
	printf("%.8lf",ans/4.0);
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
