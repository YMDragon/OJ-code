#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int n;
LL ans;

void work()
{
	scanf("%d",&n);
	for (LL i=1,j=1; i<=n; i*=10,j++)
		ans+=min(i*9,n-i+1)*j;
	printf("%lld",ans);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
