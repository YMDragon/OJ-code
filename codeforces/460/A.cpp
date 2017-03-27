#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m;

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1; ; i++)
		{
			if (n==0)  {printf("%d",i-1);  return;}
			n--;
			if (i%m==0)  n++;
		}
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
