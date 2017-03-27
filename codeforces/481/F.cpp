#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,k,f[200010],sum[200010],ans;

void work()
{
	scanf("%d %d",&n,&k);
	for (int i=1; i<=n; i++)
		scanf("%d",&f[i]),sum[i]=sum[i-1]+f[i];
	if (2*k>=n)  {printf("%d",sum[n]);  return;}
	for (int i=2*k,Max=0; i<=n; i++)
		Max=max(Max,sum[i-k]-sum[i-2*k]),ans=max(ans,sum[i]-sum[i-k]+Max);
	printf("%d",ans);
}

int main()
{
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
	work();
	return 0;
}
