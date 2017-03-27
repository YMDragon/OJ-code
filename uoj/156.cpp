#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int u0,u1,a,b,c,n;
long double u[2333];

void work()
{
	scanf("%d %d %d %d %d %d",&u0,&u1,&a,&b,&c,&n);
	u[0]=u0,u[1]=u1;
	if (n==0)  printf("%.10lf",1.0*u0),exit(0);
	if (n==1)  printf("%.10lf",1.0*u1),exit(0);
	for (int i=2; ; i++)
		{
			u[i]=a+b/u[i-1]+c/u[i-1]/u[i-2];
			if ((i==n)||(fabs(u[i]-int(u[i]))<1e-6)||(fabs(u[i]-int(u[i])-1)<1e-6))
				printf("%.10lf",double(u[i])),exit(0);
		}
}

int main()
{
	freopen("156.in","r",stdin);
	freopen("156.out","w",stdout);
	work();
	return 0;
}
