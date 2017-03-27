#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,l,a[1010];
double ans;

void work()
{
	scanf("%d %d",&n,&l);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	ans=max(a[1],l-a[n]);
	for (int i=1; i<n; i++)  ans=max(ans,(a[i+1]-a[i])/2.0);
	printf("%.9lf",ans);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
