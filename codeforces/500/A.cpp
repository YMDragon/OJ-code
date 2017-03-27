#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,t,a[30010];

void work()
{
	scanf("%d %d",&n,&t);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	int x=1;
	while (x<t)  x+=a[x];
	if (x==t)  printf("YES");  else  printf("NO");
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
