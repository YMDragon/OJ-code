#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n=2000000,m,b[2000010],prime[2000010];
long long sum;

void work()
{
	for (int i=2; i<=n; i++)
		{
			if (!b[i])  sum+=i,prime[++m]=i;
			for (int j=1; j<=m&&i*prime[j]<=n; j++)
				{
					b[i*prime[j]]=1;
					if (!(i%prime[j]))  break;
				}
		}
	printf("%lld\n",sum);
}

int main()
{
	work();
	return 0;
}
