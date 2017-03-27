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
	for (int i=1,p,q; i<=n; i++)
		{
			scanf("%d %d",&p,&q);
			if (p+2<=q)  ans++;
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
