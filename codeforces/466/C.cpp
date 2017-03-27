#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int n,a[500010];
LL sum[500010],s,ans,t;

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	if (sum[n]%3)  {printf("0");  return;}  else  s=sum[n]/3;
	for (int i=1; i<n; i++)
		{
			if (sum[i]==s*2)  ans+=t;
			if (sum[i]==s)  t++;
		}
	printf("%I64d",ans);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
} 
