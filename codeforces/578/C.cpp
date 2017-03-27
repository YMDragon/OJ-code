#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,a[200010];

double calc(double x)
{
	double res=0,s1=0,s2=0;
	for (int i=1; i<=n; i++)
		{
			s1+=a[i]-x,s2+=a[i]-x;
			if (s1<0)  s1=0;  if (s2>0)  s2=0;
			res=max(res,max(s1,-s2));
		}
	return res;
}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	double l=-1e4,r=1e4,mid1,mid2,f1,f2,f_1,f_2;
	while (1)
		{
			mid1=(2*l+r)/3,mid2=(l+2*r)/3;
			f_1=f1,f_2=f2;
			f1=calc(mid1),f2=calc(mid2);
			if (f1>f2)  l=mid1;  else  r=mid2;
			if ((fabs(f1-f_1)<1e-8)&&(fabs(f2-f_2)<1e-8))  break;
		}
	printf("%.9lf",calc(l));
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
