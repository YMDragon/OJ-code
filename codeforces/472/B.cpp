#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,k,a[2010],ans;

void work()
{
	scanf("%d %d",&n,&k);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int t=n; t>=1; t-=k)
		ans+=a[t]-1;
	ans*=2;
	printf("%d",ans);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
