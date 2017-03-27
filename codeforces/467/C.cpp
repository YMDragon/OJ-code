#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int n,m,k,a[5010];
LL sum[5010],f[5010],g[5010];

void work()
{
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	for (int i=1; i<=k; i++)
		{
			for (int j=n; j>=m; j--)
				f[j]=sum[j]-sum[j-m]+g[j-m];
			for (int j=1; j<=n; j++)
				g[j]=max(g[j-1],f[j]);
		}
	printf("%lld",g[n]);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
