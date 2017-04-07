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
	printf("%lf",0.5*n/m*(n-1));
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
