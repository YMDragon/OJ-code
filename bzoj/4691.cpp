#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct point{int x,y,z;}o,b[16];
struct sphere{point o;int r;}a[2010];
int n,m,r,f[16][105],g[1<<20],tmp[16][105];
double e[16],ans;

void read(point &x){scanf("%d %d %d",&x.x,&x.y,&x.z);}
int sqr(int x){return x*x;}
point operator + (point x,point y){return (point){x.x+y.x,x.y+y.y,x.z+y.z};}
point operator - (point x,point y){return (point){x.x-y.x,x.y-y.y,x.z-y.z};}
int dis2(point x,point y){return sqr(x.x-y.x)+sqr(x.y-y.y)+sqr(x.z-y.z);}
double dis(point x,point y){return sqrt(dis2(x,y));}
int dot(point x,point y){return x.x*y.x+x.y*y.y+x.z*y.z;}

bool check(point x,sphere z)
{
	point y=o;
	double a=dis(x,z.o),b=dis(y,z.o),c=dis(x,y),p=(a+b+c)/2;
	if ((a<=z.r)&&(b<=z.r))  return 0;
	if ((dot(y-x,z.o-x)<0)||(dot(x-y,z.o-y)<0))
		return min(dis(x,z.o),dis(y,z.o))<=z.r;
	return 2*sqrt(p*(p-a)*(p-b)*(p-c))<z.r*c;
}

void check(double S)
{
	int s=0;
	for (int i=0; i<=n/20; i++)
		s+=g[tmp[m][i]];
	if ((s<=r)&&(ans<S))  ans=S;
}

void dfs(int x,double S)
{
	if (x>m)  return check(S);
	for (int i=0; i<=n/20; i++)  tmp[x][i]=tmp[x-1][i];
	dfs(x+1,S);
	for (int i=0; i<=n/20; i++)  tmp[x][i]|=f[x][i];
	dfs(x+1,S+e[x]);
}

bool work()
{
	scanf("%d %d %d",&n,&m,&r);
	if ((n==0)&&(m==0)&&(r==0))  return 0;
	for (int i=1; i<=n; i++)  read(a[i].o),scanf("%d",&a[i].r);
	for (int i=1; i<=m; i++)  read(b[i]),scanf("%lf",&e[i]);
	read(o);
	for (int i=1; i<=m; i++)  e[i]/=dis2(b[i],o);
	for (int i=1; i<(1<<20); i++)  g[i]=g[i-(i&-i)]+1;
	for (int i=1; i<=m; i++)
		{
			for (int j=0; j<=n/20; j++)
				f[i][j]=0;
			for (int j=1; j<=n; j++)
				if (check(b[i],a[j]))
					f[i][(j-1)/20]|=1<<((j-1)%20);
		}
	ans=0,dfs(1,0);
	printf("%lf\n",ans);
	return 1;
}

int main()
{
	freopen("4691.in","r",stdin);
	freopen("4691.out","w",stdout);
	while (work())  ;
	return 0;
}
