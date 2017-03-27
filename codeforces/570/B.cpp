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
	if (n==1)  printf("1");
	else  if (m==n)  printf("%d",m-1);
	else  if (m==1)  printf("2");
	else  if (m-1>=n-m)  printf("%d",m-1);
	else  printf("%d",m+1);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
