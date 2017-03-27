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
	for (int m=0,t=-1; m<n; )
		{
			ans++,t*=-1;
			for (int i=(t>0)?1:n; 1<=i&&i<=n; i+=t)
				if (a[i]<=m)  m++,a[i]=1<<30;
		}
	printf("%d",ans-1);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
