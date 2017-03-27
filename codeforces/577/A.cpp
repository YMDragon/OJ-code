#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,x,ans;

void work()
{
	scanf("%d %d",&n,&x);
	for (int i=1; i<=n; i++)
		if ((x%i==0)&&(x/i<=n))
			ans++;
	printf("%d",ans);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
