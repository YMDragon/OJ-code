#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n=1000,sum;

void work()
{
	for (int i=1; i<n; i++)
		if ((i%3==0)||(i%5==0))  sum+=i;
	printf("%d\n",sum);
}

int main()
{
	work();
	return 0;
}
