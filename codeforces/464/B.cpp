#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const int n=8;
struct point{int x,y,z;}p[10],q[5];

point operator - (point x,point y){return (point){x.x-y.x,x.y-y.y,x.z-y.z};}
LL dj(point x,point y){return x.x*y.x+x.y*y.y+x.z*y.z;}

void check()
{
	LL dis2[10][10],Min=1LL<<60;
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			if ((p[i].x==p[j].x)&&(p[i].y==p[j].y)&&(p[i].z==p[j].z))
				return;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			dis2[i][j]=1LL*(p[i].x-p[j].x)*(p[i].x-p[j].x)+1LL*(p[i].y-p[j].y)*(p[i].y-p[j].y)+1LL*(p[i].z-p[j].z)*(p[i].z-p[j].z),Min=min(Min,dis2[i][j]);
	for (int i=1; i<=n; i++)
		{
			LL Min=(i==1)?dis2[i][2]:dis2[i][1];
			int t=0,tot=0;
			for (int j=1; j<=n; j++)
				if (i!=j)  Min=min(Min,dis2[i][j]);
			for (int j=1; j<=n; j++)
				if (Min==dis2[i][j])
					t++,q[++tot]=p[j];
			if (t!=3)  return;
			if ((dj(q[1]-p[i],q[2]-p[i])!=0)||(dj(q[2]-p[i],q[3]-p[i])!=0)||(dj(q[3]-p[i],q[1]-p[i])!=0))  return;
		}
	printf("YES\n");
	for (int i=1; i<=n; i++)
		printf("%d %d %d\n",p[i].x,p[i].y,p[i].z);
	exit(0);
}

void dfs(int x)
{
	if (x>n)  check();
	else
		{
			int a=p[x].x,b=p[x].y,c=p[x].z;
			p[x]=(point){a,b,c},dfs(x+1);
			p[x]=(point){a,c,b},dfs(x+1);
			p[x]=(point){b,a,c},dfs(x+1);
			p[x]=(point){b,c,a},dfs(x+1);
			p[x]=(point){c,a,b},dfs(x+1);
			p[x]=(point){c,b,a},dfs(x+1);
		}
}

void work()
{
	for (int i=1; i<=n; i++)
		scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].z);
	dfs(1);
	printf("NO");
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
