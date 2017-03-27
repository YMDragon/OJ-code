#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,k,a[105],b[1010][2],t,Min,Max;

void work()
{
	scanf("%d %d",&n,&k);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for (int i=1; i<=k; i++)
		{
			Min=Max=1;
			for (int j=2; j<=n; j++)
				if (a[j]>a[Max])  Max=j;
				else  if (a[j]<a[Min])  Min=j;
			if (a[Max]-a[Min]<=1)  break;
			b[i][0]=Max,b[i][1]=Min;
			a[Max]--,a[Min]++,t++;
		}
	Min=Max=1;
	for (int i=2; i<=n; i++)
		if (a[i]>a[Max])  Max=i;
		else  if (a[i]<a[Min])  Min=i;
	printf("%d %d\n",a[Max]-a[Min],t);
	for (int i=1; i<=t; i++)
		printf("%d %d\n",b[i][0],b[i][1]);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
