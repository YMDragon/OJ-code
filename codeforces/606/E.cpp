#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
struct point{int x,y;}a[100010],b[100010];
int n,m,p,q;
double ans;

bool cmp(point x,point y){return (x.x<y.x )||((x.x==y.x)&&(x.y>y.y));}
LL cross(point o,point x,point y){return 1LL*(x.x-o.x)*(y.y-o.y)-1LL*(x.y-o.y)*(y.x-o.x);}

void work()
{
	scanf("%d %d %d",&n,&p,&q);
	for (int i=1; i<=n; i++)
		{
			scanf("%d %d",&a[i].x,&a[i].y);
			a[n+1].x=max(a[n+1].x,a[i].x);
			a[n+2].y=max(a[n+2].y,a[i].y);
		}
	n+=2,sort(a+1,a+n+1,cmp);
	for (int i=1; i<=n; i++)
		{
			while ((m>1)&&(cross(b[m-1],b[m],a[i])>=0))  m--;
			b[++m]=a[i];
		}
	ans=1e20;
	for (int i=1; i<m; i++)
		{
			double d=1.0*b[i].x*b[i+1].y-1.0*b[i+1].x*b[i].y;
			double x=(1LL*p*b[i+1].y-1LL*q*b[i+1].x)/d;
			double y=(1LL*q*b[i].x-1LL*p*b[i].y)/d;
			if ((x>=0)&&(y>=0))  ans=min(ans,x+y);
		}
	printf("%.10lf",ans);
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
