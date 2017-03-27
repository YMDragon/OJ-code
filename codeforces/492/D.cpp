#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,x,y,g,a;

int gcd(int x,int y){return y?gcd(y,x%y):x;}

void work()
{
	scanf("%d %d %d",&n,&x,&y),g=gcd(x,y),x/=g,y/=g,swap(x,y);
	while (n--)
		{
			scanf("%d",&a);
			a%=(x+y);
			if ((a==0)||(a+1==x+y))  printf("both");
			else
				{
					int l=1,r=x;
					while (r-l>1)
						{

						}
				}
		}
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
