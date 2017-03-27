#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,a[505],f[505][505];

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]),f[i][i]=1;
	for (int j=1; j<n; j++)
		for (int i=1; i+j<=n; i++)
			{
				f[i][i+j]=f[i+1][i+j]+1;
				for (int k=i+2; k<=i+j; k++)
					if (a[i]==a[k])  f[i][i+j]=min(f[i][i+j],f[i+1][k-1]+f[k+1][i+j]);
				if (a[i]==a[i+1])  f[i][i+j]=min(f[i][i+j],f[i+2][i+j]+1);
			}
	printf("%d",f[1][n]);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
