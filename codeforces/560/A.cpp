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
	for (int i=1,x; i<=n; i++)
		{
			scanf("%d",&x);
			if (x==1)  {printf("-1");  return;}
		}
	printf("1");
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
