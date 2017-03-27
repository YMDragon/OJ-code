#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,k,a[10000010],l,r,ans;

void work()
{
	scanf("%d %d",&n,&k),l=1e7+1,r=0;
	for (int i=1,x; i<=n; i++)
		scanf("%d",&x),l=min(l,x),r=max(r,x),a[x]=1;
	while (l<=r)
		if (a[l])  l+=k,ans++;  else  l++;
	printf("%d",ans);
}

int main()
{
	freopen("VOGOZO.in","r",stdin);
	freopen("VOGOZO.out","w",stdout);
	work();
	return 0;
}
