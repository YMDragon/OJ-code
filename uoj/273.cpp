#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=998244353;
int n,m,ans;

void work()
{
	scanf("%d",&n),ans=1;
	for (int i=1,x; i<=n; i++)  scanf("%d",&x),m+=x;
	for (int i=m; i!=m-n+1; i--)  ans=1LL*ans*i%mo;
	for (int i=1; i!=m-n+1; i++)  ans=1LL*ans*i%mo;
	printf("%d",ans);
}

int main()
{
	freopen("273.in","r",stdin);
	freopen("273.out","w",stdout);
	work();
	return 0;
}
