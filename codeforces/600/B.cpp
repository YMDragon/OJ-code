#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int n,m,a[200010];

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1,b; i<=m; i++)
		scanf("%d",&b),printf("%d ",upper_bound(a+1,a+n+1,b)-a-1);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
