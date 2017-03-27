#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
LL g,l;

void work()
{
	scanf("%lld %lld",&g,&l);
	printf("%lld %lld\n",2*LL(sqrt(l/g))*g,l+g);
}

int main()
{
	freopen("12.in","r",stdin);
	freopen("12.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
