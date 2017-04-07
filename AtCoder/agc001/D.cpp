#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,a[105],Odd;

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=m; i++)  scanf("%d",&a[i]);
	if (m==1)
		{
			printf("%d\n",a[1]);
			if (a[1]==1)  printf("1\n1");
			else  printf("2\n%d 1",a[1]-1);
			return;
		}
	if (m==2)
		{
			printf("%d %d\n",a[1],a[2]);
			if (a[1]==1)  printf("1\n%d",n);
			else  printf("2\n%d %d",a[1]-1,a[2]+1);
			return;
		}
	for (int i=1; i<=m; i++)  Odd+=(a[i]&1);
	if (Odd>2)  {puts("Impossible");  return;}
	for (int i=1; i<=m; i++)
		if (a[i]&1)
			swap(a[i],(a[1]&1)?a[m]:a[1]);
	for (int i=1; i<=m; i++)  printf("%d ",a[i]);  puts("");
	a[1]++,a[m]--;
	if (a[m]==0)  m--;
	printf("%d\n",m);
	for (int i=1; i<=m; i++)  printf("%d ",a[i]);
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
