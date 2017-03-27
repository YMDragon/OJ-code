#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define oo  (1<<30)
typedef long long  LL;
using namespace std;

LL n,m,k;

LL getrank(LL x)
{
	LL res=0;
	for (int i=1; i<=n; i++)
		res+=min(m,(x-1)/i);
	return res;
}

void work()
{
	scanf("%lld %lld %lld",&n,&m,&k),k--;
	LL l=1,r=1LL*n*m+1,mid;
	while (r-l>1)
		{
			mid=(l+r)>>1;
			if (getrank(mid)<=k)  l=mid;  else  r=mid;
		}
	printf("%lld",l);
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
