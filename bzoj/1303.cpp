#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int n,b,a[100010],f[2][200010];
LL ans;

void work()
{
	scanf("%d %d",&n,&b);
	int sum=0;
	f[0][sum+100000]++;
	for (int i=1; i<=n; i++)
		{
			scanf("%d",&a[i]);
			if (a[i]<b)  a[i]=-1;
			if (a[i]==b)  a[i]=0;
			if (a[i]>b)  a[i]=1;
			sum+=a[i];
			f[i&1][sum+100000]++;
		}
	for (int i=100000-n; i<=100000+n; i++)
		ans+=1LL*f[0][i]*f[1][i];
	printf("%lld",ans);
}

int main()
{
	freopen("1303.in","r",stdin);
	freopen("1303.out","w",stdout);
	work();
	return 0;
} 
