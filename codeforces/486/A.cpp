#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
LL n;

void work()
{
	scanf("%lld",&n);
	if (n&1)  printf("-%lld",(n+1)/2);  else  printf("%lld",n/2);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
