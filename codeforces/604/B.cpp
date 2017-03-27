#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,k,s[100010],ans;

void work()
{
	scanf("%d %d",&n,&k);
	for (int i=1; i<=n; i++)  scanf("%d",&s[i]),ans=max(ans,s[i]);
	for (int i=1; i<=n-k; i++)
		ans=max(ans,s[i]+s[2*(n-k)-i+1]);
	printf("%d",ans);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
