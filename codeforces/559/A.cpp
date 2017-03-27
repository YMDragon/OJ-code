#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

double a[10],b[5],ans,p;

void work()
{
	for (int i=1; i<=6; i++)  scanf("%lf",&a[i]);
	for (int i=1; i<=3; i++)
		{
			int x=2*i-1,y=2*i;
			b[i]=sqrt(a[x]*a[x]+a[y]*a[y]+a[x]*a[y]);
			p=(a[x]+a[y]+b[i])/2;
			ans+=sqrt(p*(p-a[x])*(p-a[y])*(p-b[i]));
		}
	p=(b[1]+b[2]+b[3])/2;
	ans+=sqrt(p*(p-b[1])*(p-b[2])*(p-b[3]));
	ans/=sqrt(3)/4;
	printf("%d",int(ans+0.5));
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
