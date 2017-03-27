#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int n,k,x,s,a[200010],b[200010],c[200010];
LL ans;

void work()
{
	scanf("%d %d %d",&n,&k,&x),s=1;
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	for (int i=1; i<=k; i++)  s*=x;
	for (int i=1; i<=n; i++)  b[i]=b[i-1]|a[i];
	for (int i=n; i; i--)  c[i]=c[i+1]|a[i];
	for (int i=1; i<=n; i++)
		ans=max(ans,b[i-1]|(1LL*a[i]*s)|c[i+1]);
	cout<<ans;
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
