#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
LL l,r;

LL gcd(LL x,LL y){return y?gcd(y,x%y):x;}

void work()
{
	scanf("%lld %lld",&l,&r);
	if (r-l>=3)
		if ((l&1)==0)  printf("%lld %lld %lld",l,l+1,l+2);
		else  printf("%lld %lld %lld",l+1,l+2,l+3);
	else  if ((r-l==2)&&(gcd(l,l+2)!=1))  printf("%lld %lld %lld",l,l+1,l+2);
	else  printf("-1");		
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
