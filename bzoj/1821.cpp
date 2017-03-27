#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct edge{
	int s,t;
	double d;
}e[1000010];

struct node{
	int x,y;
}a[1010];

int n,k,m,bcj[1010];

double dist(node x,node y)
{
	return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}

int cmp(edge x,edge y)
{
	return x.d<y.d;
}

int f(int x)
{
	if (bcj[x]==x)  return x;
	bcj[x]=f(bcj[x]);  return bcj[x];
}

void work()
{
	scanf("%d %d",&n,&k);
	for (int i=1; i<=n; i++)
		scanf("%d %d",&a[i].x,&a[i].y),bcj[i]=i;
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			e[++m]=(edge){i,j,dist(a[i],a[j])};
	sort(e+1,e+m+1,cmp);
	int x,y;
	for (int i=1; i<=m; i++)
	{
		x=f(e[i].s),y=f(e[i].t);
		if (x!=y)
		{
			if (n==k)
				{printf("%.2lf",e[i].d);  return;}
			bcj[y]=x;
			n--;	
		}
	}
}

int main()
{
	freopen("1821.in","r",stdin);
	freopen("1821.out","w",stdout);
	work();
	return 0;
}
