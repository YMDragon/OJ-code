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
	if (n<0)  n=-n;
	n%=6;
	switch (n)
		{
		case 0:printf("2");  break;
		case 1:printf("1");  break;
		case 2:printf("-1");  break;
		case 3:printf("-2");  break;
		case 4:printf("-1");  break;
		case 5:printf("1");  break;
		}
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
