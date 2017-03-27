#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,h[100010],ans;

void work()
{
	scanf("%d",&n);
	for (int i=1,t=0; i<=n; i++)
		{
			scanf("%d",&h[i]),t+=h[i-1]-h[i];
			if (t<0)  ans+=-t,t=0;
		}
	printf("%d",ans);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
