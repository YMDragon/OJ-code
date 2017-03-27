#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
LL l,r,ans;

void work()
{
	scanf("%I64d %I64d",&l,&r);
	for (int i=1; i<=60; i++)
		{
			LL x=(1LL<<i)-1;
			for (int j=1; j<i; j++)
				{
					LL y=x^(1LL<<(j-1));
					if ((l<=y)&&(y<=r))  ans++;
				}
		}
	printf("%I64d",ans);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
