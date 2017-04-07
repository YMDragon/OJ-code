#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,l[205],ans;

void work()
{
	scanf("%d",&n),n*=2;
	for (int i=1; i<=n; i++)  scanf("%d",&l[i]);
	sort(l+1,l+n+1);
	for (int i=1; i<=n; i+=2)  ans+=l[i];
	printf("%d",ans);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
