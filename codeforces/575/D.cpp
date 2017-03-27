#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

void work()
{
	printf("2000\n");
	for (int i=1; i<=1000; i++)  printf("%d 1 %d 2\n",i,i);
	for (int i=1000; i>=1; i--)  printf("%d 1 %d 2\n",i,i);
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
