#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int sx,sy,tx,ty,vmax,t,vx,vy,wx,wy;

bool check(double mid)
{
	double x=sx,y=sy;
	if (mid<=t)  x+=mid*vx,y+=mid*vy;
	else  x+=t*vx+(mid-t)*wx,y+=t*vy+(mid-t)*wy;
	return mid*vmax>sqrt((x-tx)*(x-tx)+(y-ty)*(y-ty));
}

void work()
{
	scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
	scanf("%d %d",&vmax,&t);
	scanf("%d %d %d %d",&vx,&vy,&wx,&wy);
	double l=0,r=1e8,mid;
	for (; r-l>1e-7; check(mid=(l+r)/2)?r=mid:l=mid);
	printf("%.10lf",r);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
