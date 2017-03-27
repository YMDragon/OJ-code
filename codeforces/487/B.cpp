#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,s,l,a[100010],ans;

void work()
{
	scanf("%d %d %d",&n,&s,&l);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for (int i=1,t=1; i<=n; i++)
		if (t)
			{
				if (n-i+1<l)  {printf("-1");  return;}
			}
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
