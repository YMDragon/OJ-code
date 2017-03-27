#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int na,nb,k,m,a[100010],b[100010];

void work()
{
	scanf("%d %d",&na,&nb);
	scanf("%d %d",&k,&m);
	for (int i=1; i<=na; i++)  scanf("%d",&a[i]);
	for (int i=1; i<=nb; i++)  scanf("%d",&b[i]);
	if (a[k]<b[nb-m+1])  printf("YES");  else  printf("NO");
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
