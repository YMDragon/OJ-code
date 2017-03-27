#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int d1,d2,d3;

void work()
{
	scanf("%d %d %d",&d1,&d2,&d3);
	printf("%d",min(min(min(d1+d2+d3,2*(d1+d2)),2*(d1+d3)),2*(d2+d3)));
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
