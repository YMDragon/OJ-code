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
	for (int i=1,a,p,mp=101; i<=n; i++)
		{
			scanf("%d %d",&a,&p),mp=min(mp,p);
			ans+=a*mp;
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
