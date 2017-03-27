#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
struct node{int t,x,y;}a[10010];

int f[10010],n,m,ans;

bool cmp(node x,node y)
{
	return x.t<y.t;
}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=m; i++)
		scanf("%d %d %d",&a[i].t,&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	for (int i=1; i<=m; i++)
		{
			f[i]=1;
			for (int j=1; j<i; j++)
				if (fabs(a[i].x-a[j].x)+fabs(a[i].y-a[j].y)<=a[i].t-a[j].t)
					f[i]=max(f[i],f[j]+1);
			ans=max(ans,f[i]);
		}
	printf("%d",ans);
}

int main()
{
	freopen("1207.in","r",stdin);
	freopen("1207.out","w",stdout);
	work();
	return 0;
}
