#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n=4000000;

void work()
{
	int a=0,b=1,sum=0;
	while (a+b<=n)
		{
			b=a+b,a=b-a;
			if (!(b&1))  sum+=b;
		}
	printf("%d\n",sum);
}

int main()
{
	work();
	return 0;
}
