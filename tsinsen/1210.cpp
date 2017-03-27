#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct point{int x,y;}a[7010];
int n,q,pre[7010][7010],ans;

bool cmpxu(point x,point y){return x.x<y.x;}
bool cmpyd(point x,point y){return x.y>y.y;}

void work()
{
	scanf("%d %d",&n,&q),ans=n;
	for (int i=1; i<=n; i++)  scanf("%d %d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmpxu);
	for (int i=1; i<=n; i++)  a[i].x=i;
	sort(a+1,a+n+1,cmpyd);
	for (int i=1,x; x=a[i].x,i<=n; i++)
		{
			for (int j=1,t,P,Q; t=a[j].x,j<i; j++)
				if (t<x)
					if ((P=pre[j][n])>(Q=pre[j][x]))  pre[i][t]=P-Q+1;
					else  pre[i][t]=P+q-Q+1;
				else  pre[i][t]=pre[j][x]+1;
			for (int j=1; j<=n; j++)
				if ((pre[i][j]+=pre[i][j-1])>=q)
					pre[i][j]-=q;
			if ((ans+=pre[i][n])>=q)  ans-=q;
		}
	printf("%d",ans);
}

int main()
{
	freopen("1210.in","r",stdin);
	freopen("1210.out","w",stdout);
	work();
	return 0;
}
