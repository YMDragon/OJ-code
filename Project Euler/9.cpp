#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n=1000;

void work()
{
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j++)
			{
				int k=sqrt(i*i+j*j);
				if ((i*i+j*j==k*k)&&(i+j+k==n))
					printf("%d\n",i*j*k);
			}
}

int main()
{
	work();
	return 0;
}
