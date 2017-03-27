#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

long long n,m,f[100010],ans,sum;

void work()
{
	scanf("%d %d",&n,&m);
	if (n<m)  swap(n,m);
	for (long long i=m; i>=1; i--)
		{
			sum=(n/i)*(m/i);
			for (long long j=2; j<=m/i; j++)  sum-=f[i*j];
			f[i]=sum;  ans+=(2*i-1)*f[i];	
		}
	printf("%lld",ans);
}

int main()
{
	freopen("2005.in","r",stdin);
	freopen("2005.out","w",stdout);
	work();
	return 0;
} 
