#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
LL n,k,m,p,ans;

LL ksm(LL a,LL b)
{
	LL x=a;a=1;
	while (b)
		{
			if (b&1)  a=a*x%p;
			x=x*x%p,b>>=1;
		}
	return a;
}

void work()
{
	scanf("%lld %lld %lld %lld",&n,&k,&m,&p);
	ans=(n%p*ksm(m,k-1)-m*(m+1)/2%p*ksm(m,k-2)%p*(k-1)%p)%p;
	printf("%lld",ans);
}

int main()
{
	freopen("3142.in","r",stdin);
	freopen("3142.out","w",stdout);
	work();
	return 0;
}
