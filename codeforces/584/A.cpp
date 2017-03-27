#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,t,x;

void work()
{
	scanf("%d %d",&n,&t);
	if (n==1)  {printf("%d",(t==10)?-1:t);  return;}
	printf("1"),x=1;
	for (int i=2; i<n; i++)  printf("0"),x=x*10%t;
	x=x*10%t;
	printf("%d",x?(t-x):0);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
