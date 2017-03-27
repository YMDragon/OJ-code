#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>
#define pc  putchar
using namespace std;

int x1,y1,x2,y2,x3,y3,sum,n,a[105][105];
char c1,c2,c3;

void work()
{
	scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
	sum=x1*y1+x2*y2+x3*y3;
	int tag=1;
	for (int i=1; i<=sum&&tag; i++)
		if (i*i==sum)  tag=0,n=i;
	if (tag)  {printf("-1");  return;}
	if (x1>y1)  swap(x1,y1);
	if (x2>y2)  swap(x2,y2);
	if (x3>y3)  swap(x3,y3);
	c1='A',c2='B',c3='C';
	if ((y1==n)&&(y2==n)&&(y3==n))
		{
			printf("%d\n",n);
			for (int i=1; i<=x1; i++)
				{
					for (int j=1; j<=n; j++)  pc(c1);
					pc('\n');
				}
			for (int i=1; i<=x2; i++)
				{
					for (int j=1; j<=n; j++)  pc(c2);
					pc('\n');
				}
			for (int i=1; i<=x3; i++)
				{
					for (int j=1; j<=n; j++)  pc(c3);
					pc('\n');
				}
		}else
		if ((y1==n)+(y2==n)+(y3==n)==1)
			{
				if (y2==n)  swap(x1,x2),swap(y1,y2),swap(c1,c2);
				if (y3==n)  swap(x1,x3),swap(y1,y3),swap(c1,c3);
				if (x1+y2==n)  swap(x2,y2);
				if (x1+y3==n)  swap(x3,y3);
				if ((x1+x2==n)&&(x1+x3==n))
					{
						printf("%d\n",n);
						for (int i=1; i<=x1; i++)
							{
								for (int j=1; j<=n; j++)  pc(c1);
								pc('\n');
							}
						for (int i=1; i<=n-x1; i++)
							{
								for (int j=1; j<=y2; j++)  pc(c2);
								for (int j=1; j<=y3; j++)  pc(c3);
								pc('\n');
							}
					}else  printf("-1");
			}else
			printf("-1");
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
