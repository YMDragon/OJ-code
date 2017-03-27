#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=1000000007;
int n,a,b,k,f[5010][5010],sum[5010][5010];

void work()
{
	scanf("%d %d %d %d",&n,&a,&b,&k);
	if (a>b)  a=n-a+1,n=n-b;  else  n=b-1;
	f[0][a]=1;
	for (int i=a; i<=n; i++)  sum[0][i]=1;
	for (int i=1; i<=k; i++)
		for (int j=1; j<=n; j++)
			{
				f[i][j]=sum[i-1][j-1];
				int p=(n+j)/2;
				(f[i][j]+=(sum[i-1][p]-sum[i-1][j]+mo)%mo)%=mo;
				sum[i][j]=(sum[i][j-1]+f[i][j])%mo;
			}
	printf("%d",sum[k][n]);
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
