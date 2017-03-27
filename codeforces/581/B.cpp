#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,a[100010],Max,ans[100010];

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	for (int i=n; i; i--)  ans[i]=Max+1,Max=max(Max,a[i]);
	for (int i=1; i<=n; i++)  printf("%d ",max(0,ans[i]-a[i]));
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
