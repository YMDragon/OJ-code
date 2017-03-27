#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int w,m;

void work()
{
	scanf("%d %d",&w,&m);
	if (w==2)  {printf("YES");  return;}
	while (m)
		{
			int r=m%w;  m/=w;
			if ((1<r)&&(r<w-1))  {printf("NO");  return;}
			if (r==w-1)  m++;
		}
	printf("YES");
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
