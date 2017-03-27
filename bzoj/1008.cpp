#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long LL;
const int mo=100003;
LL n,m,ans;

LL ksm(LL a,LL b)
{
	LL x=a,res=1;
	while (b)
		{
			if (b&1)  res=res*x%mo;
			x=x*x%mo,b>>=1;
		}
	return res;
}

void work()
{
	scanf("%lld %lld",&m,&n);
	ans=ksm(m,n);
	ans-=m*ksm(m-1,n-1)%mo;
	printf("%lld",(ans+mo)%mo);
}

int main()
{
	freopen("1008.in","r",stdin);
	freopen("1008.out","w",stdout);
	work();
	return 0;
} 
