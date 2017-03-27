#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int a,b,c,n,ans[100];

void work()
{
	scanf("%d %d %d",&a,&b,&c);
	for (int i=1; i<=81; i++)
		{
			long long x=1,y;  int s=0;
			for (int j=1; j<=a; j++)  x*=i;
			x*=b,x+=c,y=x;
			if ((x<=0)||(x>1e9))  continue;
			while (x)  s+=x%10,x/=10;
			if (s==i)  ans[++n]=y;
		}
	printf("%d\n",n);
	for (int i=1; i<=n; i++)
		printf("%d ",ans[i]);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
