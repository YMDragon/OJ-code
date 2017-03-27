#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int n,a[400010];
LL ans,ans2;

void work()
{
	scanf("%d",&n),ans=1<<30;
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]),ans=min(ans,1LL*a[i]);
	for (int i=1; i<=n; i++)  a[i+n]=(a[i]-=ans);
	ans*=n;
	for (int i=1,f=0; i<=2*n; i++)
		{
			if (a[i])  f++;  else  f=0;
			ans2=max(ans2,1LL*f);
		}
	printf("%lld",ans+ans2);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
