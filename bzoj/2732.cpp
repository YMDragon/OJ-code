#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct point{double x,y;};
struct line{point a,b;};
struct node{line v;int t;double p;}a[200010];
const double eps=1e-30;
int n,v[200010],q[200010];

double cj(point o,point a,point b){return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);}
bool cmp(node x,node y){return x.p-y.p<eps;}
point cp(line a,line b)
{
	double seq=cj(a.a,b.a,b.b);
	seq=seq/(seq-cj(a.b,b.a,b.b));
	return (point){a.a.x+(a.b.x-a.a.x)*seq,a.a.y+(a.b.y-a.a.y)*seq};
}

bool check(int t)
{
	int m=0,l=1,r=0;
	for (int i=0; i<2*n+2; i++)
		if (a[i].t<=t)
			v[++m]=i;
	for (int i=1; i<=m; i++)
		{
			int x=v[i];
			while ((r-l>0)&&(cj(a[x].v.a,a[x].v.b,cp(a[q[r]].v,a[q[r-1]].v))<=eps))  r--;
			while ((r-l>0)&&(cj(a[x].v.a,a[x].v.b,cp(a[q[l]].v,a[q[l+1]].v))<=eps))  l++;
			q[++r]=x;
			if ((fabs(a[q[r-1]].p-a[x].p)<eps)&&(cj(a[x].v.a,a[x].v.b,a[q[--r]].v.a)<0)) 
				q[r]=x;
		}
	while ((r-l>1)&&(cj(a[q[l]].v.a,a[q[l]].v.b,cp(a[q[r]].v,a[q[r-1]].v))<=eps))  r--;
	while ((r-l>1)&&(cj(a[q[r]].v.a,a[q[r]].v.b,cp(a[q[l]].v,a[q[l+1]].v))<=eps))  l++;
	return r-l>1;
}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		{
			double x,y,z;
			scanf("%lf %lf %lf",&x,&y,&z);
			a[i]=(node){(line){(point){0,z/x},(point){-1,z/x+x}},i,atan2(x,-1)};
			a[i+n]=(node){(line){(point){0,y/x},(point){1,y/x-x}},i,atan2(-x,1)};
		}
	a[0]=(node){(line){(point){0,0},(point){1,0}},0,atan2(0,1)};
	a[2*n+1]=(node){(line){(point){1e9,1e9},(point){0,1e9}},0,-atan2(0,-1e9)};

	sort(a,a+n+1,cmp);
	sort(a+n+1,a+2*n+2,cmp);
	int l=1,r=n+1,mid;
	while (r-l>1)
		{
			mid=(l+r)>>1;
			if (check(mid))  l=mid;  else  r=mid;
		}
	printf("%d",l);
}

int main()
{
	freopen("2732.in","r",stdin);
	freopen("2732.out","w",stdout);
	work();
	return 0;
}

