#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const double pi=acos(-1),eps=1e-8;
double r=1,s=(1-pi/4)*r*r,target=0.001;
int n;

double f(double x){return min(x/n,r-sqrt(x*(2*r-x)));}

double Simpson(double l,double m,double r,double fl,double fm,double fr)
{
	double lm=(l+m)/2,rm=(r+m)/2,flm=f(lm),frm=f(rm);
	if (fabs((fl+6*fm+fr-4*flm-4*frm))<eps/90)  return (r-l)/6*(fl+4*fm+fr);
	return Simpson(l,lm,m,fl,flm,fm)+Simpson(m,rm,r,fm,frm,fr);
}

double calc(int k)
{
	n=k;
	return Simpson(0,r/2,r,0,f(r/2),0);
}

void work()
{
	int l=0,r=1,mid;
	while (calc(r)/s>=target)  l=r,r<<=1;
	for (; r-l>1; calc(mid=(l+r)>>1)/s<target?r=mid:l=mid);
	printf("%d\n",r);
}

int main()
{
	work();
	return 0;
}
