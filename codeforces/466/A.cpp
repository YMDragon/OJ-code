#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,a,b;

void work()
{
	scanf("%d %d %d %d",&n,&m,&a,&b);
	if (m*a<=b)  printf("%d",n*a);
	else  if (n%m*a<=b)  printf("%d",n/m*b+n%m*a);
	else  printf("%d",(n+m-1)/m*b);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
} 
