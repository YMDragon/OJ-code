#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int l,p,q;

void work()
{
	scanf("%d %d %d",&l,&p,&q);
	printf("%lf",1.0*l/(p+q)*p);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
