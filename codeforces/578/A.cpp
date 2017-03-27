#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int a,b,k;

void work()
{
	scanf("%d %d",&a,&b);
	if (a<b)  {printf("-1");  return;}
	k=a/b,k-=!(k&1);
	printf("%.9lf",b+1.0*(a-k*b)/(k+1));
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
