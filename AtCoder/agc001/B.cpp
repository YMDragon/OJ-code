#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
LL n,x,y,ans;

void work()
{
	scanf("%lld %lld",&n,&x),ans=n,y=n-x;
	while (x)  ans+=2*x*(y/x),y%=x,swap(x,y);
	printf("%lld",ans-y);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
