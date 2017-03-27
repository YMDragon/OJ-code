#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

const int oo=(1<<30);
struct junc{int c,rc,t[2];}a[305];
struct edge{int s,t,d,n;}e[30000];
int s,t,n,m,tot,h[305],dis[305],f[305],inque[305];
queue <int> Q;

junc go(junc x,int t)
{
	t%=x.t[0]+x.t[1];
	x.rc-=t;
	while (x.rc<=0)  x.c^=1,x.rc+=x.t[x.c];
	return x;
}

int gettime(junc x,junc y)
{
	int t=0;
	for (int i=1; i<=4; i++)
		{
			if (x.c==y.c)  return t;
			int p=min(x.rc,y.rc);
			x=go(x,p),y=go(y,p),t+=p;
		}
	if (x.c==y.c)  return t;
	return oo;
}


void print(int x)
{
	if (x!=s)  print(f[x]);
	printf("%d ",x);
}

void work()
{
	scanf("%d %d",&s,&t);
	scanf("%d %d",&n,&m);
	for (int i=1; i<=n; i++)
		{
			char ch=getchar();
			while ((ch!='P')&&(ch!='B'))  ch=getchar();
			a[i].c=(ch=='P');
			scanf("%d %d %d",&a[i].rc,&a[i].t[0],&a[i].t[1]);
		}
	for (int i=1,u,v,d; i<=m; i++)
		{
			scanf("%d %d %d",&u,&v,&d);
			e[++tot]=(edge){u,v,d,h[u]},h[u]=tot;
			e[++tot]=(edge){v,u,d,h[v]},h[v]=tot;
		}
	for (int i=1; i<=n; i++)  dis[i]=oo;
	Q.push(s),dis[s]=0,inque[s]=1;
	while (!Q.empty())
		{
			int x=Q.front();  Q.pop(),inque[x]=0;
			for (int i=h[x],y,d; y=e[i].t,i; i=e[i].n)
				if ((d=dis[x]+gettime(go(a[x],dis[x]),go(a[y],dis[x]))+e[i].d)<dis[y])
					{
						dis[y]=d,f[y]=x;
						if (!inque[y])  Q.push(y),inque[y]=1;
					}
		}
	if (dis[t]==oo)  printf("0");  else  printf("%d\n",dis[t]),print(t);
}

int main()
{
	freopen("103.in","r",stdin);
	freopen("103.out","w",stdout);
	work();
	return 0;
}
