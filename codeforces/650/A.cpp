#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct point{int x,y;}a[200010];
int n;
long long ans;

bool cmpx(point x,point y){return x.x<y.x;}
bool cmpy(point x,point y){return (x.y<y.y)||((x.y==y.y)&&(x.x<y.x));}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d %d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmpx);
	for (int i=2,cnt=0; i<=n; i++)
		{
			if (a[i].x==a[i-1].x)  cnt++;  else  cnt=0;
			ans+=cnt;
		}
	sort(a+1,a+n+1,cmpy);
	for (int i=2,cnt=0; i<=n; i++)
		{
			if (a[i].y==a[i-1].y)  cnt++;  else  cnt=0;
			ans+=cnt;
		}
	for (int i=2,cnt=0; i<=n; i++)
		{
			if ((a[i].x==a[i-1].x)&&(a[i].y==a[i-1].y))  cnt++;  else  cnt=0;
			ans-=cnt;
		}
	cout<<ans;
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
