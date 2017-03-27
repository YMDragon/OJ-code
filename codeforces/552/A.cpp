#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,ans;

void work()
{
	scanf("%d",&n);
	for (int i=1,a,b,c,d; i<=n; i++)
		{
			scanf("%d %d %d %d",&a,&b,&c,&d);
			ans+=(c-a+1)*(d-b+1);
		}
	printf("%d",ans);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
