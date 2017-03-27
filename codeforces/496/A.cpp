#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,a[1010],ans;

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	ans=1<<30;
	for (int i=2; i<n; i++)
		{
			int d=0;
			for (int j=2; j<=n; j++)
				if (i!=j)
					{
						if (j==i+1)  d=max(d,a[j]-a[j-2]);
						else  d=max(d,a[j]-a[j-1]);
					}
			ans=min(ans,d);
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
