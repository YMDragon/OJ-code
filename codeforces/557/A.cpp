#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,l1,l2,l3,r1,r2,r3,x1,x2,x3,t;

void work()
{
	scanf("%d %d %d %d %d %d %d",&n,&l1,&r1,&l2,&r2,&l3,&r3);
	x1=l1,x2=l2,x3=l3;
	x1+=min(n-x1-x2-x3,r1-l1);
	x2+=min(n-x1-x2-x3,r2-l2);
	x3+=min(n-x1-x2-x3,r3-l3);
	printf("%d %d %d",x1,x2,x3);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
