#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,ans,s,x;

void work()
{
	scanf("%d",&n);
	while (s<=n)
		ans++,x+=ans,s+=x;
	printf("%d",ans-1);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
