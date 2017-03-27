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
	if (n&1)  {printf("0");  return;}
	printf("%d",(n/2-1)/2);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
