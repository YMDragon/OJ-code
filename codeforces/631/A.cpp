#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,a[1010],b[1010],sa,sb;

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]),sa|=a[i];
	for (int i=1; i<=n; i++)  scanf("%d",&b[i]),sb|=b[i];
	printf("%d",sa+sb);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
