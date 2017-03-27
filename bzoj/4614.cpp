#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const double pi=acos(-1);
struct node{int xl,xr,y;}a[2010];
struct point{LL k;int x;}b[4010];
int n,ans;

bool cmp(point x,point y){return (x.k<y.k)||((x.k==y.k)&&(x.x>y.x));}

int solve(int sx,int sy)
{
	int m=0,s=0,res=0;
	for (int i=1; i<n; i++)
		if (a[i].y!=sy)
			{
				double alpha=atan2(sy-a[i].y,sx-a[i].xl);
				double beta=atan2(sy-a[i].y,sx-a[i].xr);
				if (alpha<0)  alpha+=pi,beta+=pi;
				if (alpha>beta)  swap(alpha,beta);
				b[++m]=(point){LL(alpha*1e12),a[i].xr-a[i].xl};
				b[++m]=(point){LL(beta*1e12),a[i].xl-a[i].xr};
			}
	sort(b+1,b+m+1,cmp);
	for (int i=1; i<=m; i++)
		s+=b[i].x,res=max(res,s);
	return res;
}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		{
			scanf("%d %d %d",&a[i].xl,&a[i].xr,&a[i].y);
			if (a[i].xl>a[i].xr)  swap(a[i].xl,a[i].xr);
		}
	for (int i=1; i<=n; i++)
		{
			swap(a[i],a[n]);
			ans=max(ans,solve(a[n].xl,a[n].y)+a[n].xr-a[n].xl);
			ans=max(ans,solve(a[n].xr,a[n].y)+a[n].xr-a[n].xl);
			swap(a[i],a[n]);
		}
	printf("%d",ans);
}

int main()
{
	freopen("4614.in","r",stdin);
	freopen("4614.out","w",stdout);
	work();
	return 0;
}
