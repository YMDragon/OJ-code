#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,w,a[200010];

void work()
{
	scanf("%d %d",&n,&w);
	for (int i=1; i<=2*n; i++)  scanf("%d",&a[i]);
	sort(a+1,a+2*n+1);
	double x=min(1.0*a[1],a[n+1]/2.0);
	printf("%lf",min(1.0*w,x*3*n));
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
