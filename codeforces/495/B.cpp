#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int a,b,ans;

void work()
{
	scanf("%d %d",&a,&b);
	if (a<b)  printf("0");
	if (a==b)  printf("infinity");
	if (a>b)
		{
			a-=b;
			for (int i=1; i<=sqrt(a); i++)
				if (a%i==0)
					{
						if (i>b)  ans++;
						if ((i*i!=a)&&(a/i>b))  ans++;
					}
			printf("%d",ans);
		}
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
