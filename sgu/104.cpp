#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,a[105][105],f[105][105],g[105][105];

void print(int i,int j)
{
	if (i<=0)  return;
	if (g[i][j])  print(i-1,j-1),printf("%d ",j);
	else  print(i,j-1);
}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			scanf("%d",&a[i][j]);
	for (int i=1; i<=n; i++)  f[i][i-1]=-(1<<30);
	for (int i=1; i<=n; i++)
		for (int j=i; j<=m; j++)
			if (f[i][j-1]<f[i-1][j-1]+a[i][j])  f[i][j]=f[i-1][j-1]+a[i][j],g[i][j]=1;
			else  f[i][j]=f[i][j-1],g[i][j]=0;
	printf("%d\n",f[n][m]);
	print(n,m);
}

int main()
{
	freopen("104.in","r",stdin);
	freopen("104.out","w",stdout);
	work();
	return 0;
} 
