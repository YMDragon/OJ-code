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
	if (n==0)  {printf("0 1\n0 %d\n0 0\n0 %d",m,m-1);  return;}
	if (m==0)  {printf("1 0\n%d 0\n0 0\n%d 0",n,n-1);  return;}
	if (n>=m)
		{
			double dis1=2*sqrt((m-1)*(m-1)+n*n),dis2=sqrt(n*n+m*m)+n;
			if (dis1>=dis2)  printf("%d %d\n0 0\n%d %d\n0 1",n,m-1,n,m);
			else  printf("0 0\n%d %d\n0 %d\n%d 0",n,m,m,n);
		}else
		{
			double dis1=2*sqrt((n-1)*(n-1)+m*m),dis2=sqrt(n*n+m*m)+m;
			if (dis1>=dis2)  printf("%d %d\n0 0\n%d %d\n1 0",n-1,m,n,m);
			else  printf("0 0\n%d %d\n%d 0\n0 %d",n,m,n,m);
		}
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
} 
