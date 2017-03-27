#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const int m=int(1e6);
int n,a[300010];
LL ans;

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1; i<=n; i++)
		ans+=1LL*min(n,i+1)*a[i];
	printf("%I64d",ans);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
