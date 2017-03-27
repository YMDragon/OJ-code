#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,prime[1000010],b[1000010];

void work()
{
	scanf("%d",&n);
	for (int i=2; i<=n; i++)
		{
			if (!b[i])  prime[++m]=i;
			for (int j=1; j<=m&&prime[j]*i<=n; j++)
				{
					b[prime[j]*i]=1;
					if (i%prime[j]==0)  break;
				}
		}
	for (int i=2; i<=n/2; i++)
		if ((b[i])&&(b[n-i]))
			{
				printf("%d %d",i,n-i);
				return;
			}
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
