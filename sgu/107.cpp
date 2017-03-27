#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n;

void work()
{
	scanf("%d",&n);
	if (n<9)  printf("0");
	if (n==9)  printf("8");
	if (n>9)
		{
			printf("72");
			for (int i=1; i<=n-10; i++)
				printf("0");
		}
}

int main()
{
	freopen("107.in","r",stdin);
	freopen("107.out","w",stdout);
	work();
	return 0;
}
