#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int hy,ay,dy,hm,am,dm,h,a,d,ans;

void work()
{
	scanf("%d %d %d",&hy,&ay,&dy);
	scanf("%d %d %d",&hm,&am,&dm);
	scanf("%d %d %d",&h,&a,&d);
	ans=max(0,am-dy)*d+max(0,dm+hm-ay)*a;
	if (dy>=am)  ans=min(ans,max(0,dm-ay+1)*a);
	for (int i=dy; i<=am; i++)
		{
			if (ay>=dm+hm)  ans=min(ans,max(0,am-i-hy+1)*h+(i-dy)*d);
			for (int j=max(ay,dm+1); j<=dm+hm; j++)
				ans=min(ans,max(0,(am-i)*((hm+j-dm-1)/(j-dm))-hy+1)*h+(i-dy)*d+(j-ay)*a);
		}
	printf("%d",ans);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
