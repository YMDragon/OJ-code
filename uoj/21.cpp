#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int n,a[1000010],maxa,b[2000010];
LL sum,ans;

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]),b[a[i]]++,maxa=max(maxa,a[i]),sum+=a[i];
	for (int i=1; i<=2*maxa; i++)  b[i]+=b[i-1];
	for (int i=1; i<=maxa; i++)
		{
			LL res=0;
			for (int j=0,k=0; j<=maxa; j+=i,k++)
				res+=k*(b[j+i-1]-b[j-1]);
			ans=max(ans,res*(i-1));
		}
	printf("%lld",sum-ans);
}

int main()
{
	freopen("21.in","r",stdin);
	freopen("21.out","w",stdout);
	work();
	return 0;
}
