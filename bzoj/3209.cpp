#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const int mo=10000007,phi=9988440;
int L,c[50][50],ans;
LL n;

int qpow(int a,int b)
{
	int x=a;  a=1;
	while (b)
		{
			if (b&1)  a=1LL*a*x%mo;
			x=1LL*x*x%mo,b>>=1;
		}
	return a;
}

void work()
{
	scanf("%lld",&n),ans=1,n++;
	for (int i=0; i<50; i++)
		{
			c[i][0]=1;
			for (int j=1; j<=i; j++)
				c[i][j]=(c[i-1][j]+c[i-1][j-1])%phi;
		}
	for (int i=49,s=0; i>=0; i--)
		if (n&(1LL<<i))
			{
				for (int j=s?0:1; j<=i; j++)
					ans=1LL*ans*qpow(j+s,c[i][j])%mo;
				s++;
			}
	printf("%d\n",ans);
}

int main()
{
	freopen("3209.in","r",stdin);
	freopen("3209.out","w",stdout);
	work();
	return 0;
}
