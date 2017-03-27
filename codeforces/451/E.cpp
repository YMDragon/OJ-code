#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const LL mo=1000000007;
LL n,s,f[25],ans[25],m,ni[25];

LL ksm(LL a,LL b)
{
	LL res=1,x=a;
	while (b)
		{
			if (b&1)  res=res*x%mo;
			x=x*x%mo,b>>=1;
		}
	return res;
}

void work()
{
	scanf("%lld %lld",&n,&s),m=1<<n;
	for (int i=1; i<=n; i++)  scanf("%lld",&f[i]);
	for (int i=1; i<n; i++)  ni[i]=ksm(i,mo-2);
	for (int i=0; i<m; i++)
		{
			LL sum=s,g=0,c=1;
			for (LL x=i,j=1; j<=n; j++,x>>=1)
				if (x&1)  sum-=f[j]+1,g++;
			if (sum>=0)
				{
					for (int j=1; j<n; j++)
						c=c*((sum+n-j)%mo)%mo*ni[j]%mo;
					ans[g]=(ans[g]+c)%mo;
				}
		}
	for (int i=1; i<=n; i++)
		if (i&1)  ans[0]=(ans[0]-ans[i]+mo)%mo;
		else  ans[0]=(ans[0]+ans[i])%mo;
	printf("%lld",ans[0]);
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
