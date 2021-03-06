#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
using namespace std;

long double X1,Y1,X2,Y2,d,r1,r2,ans;

void work()
{
	cin>>X1>>Y1>>r1>>X2>>Y2>>r2;
	d=sqrt((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2));
	if (r1<r2)  swap(r1,r2);
	if (d>=r1+r2)  ans=0;
	else  if (d>r1-r2)
		{
			long double cos1=(d*d+r1*r1-r2*r2)/(2*d*r1),cos2=(d*d+r2*r2-r1*r1)/(2*d*r2);
			ans=r1*r1*(acos(cos1)-cos1*sqrt(1-cos1*cos1))+r2*r2*(acos(cos2)-cos2*sqrt(1-cos2*cos2));
		}else  ans=acos(-1)*r2*r2;
	cout<<fixed<<setprecision(10)<<ans;
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
