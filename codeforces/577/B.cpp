#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,a[1010],f[1010][1010];

void work()
{
	scanf("%d %d",&n,&m);
	if (n>=m)  {printf("YES");  return;}
	for (int i=1; i<=n; i++)
		{
			scanf("%d",&a[i]),a[i]%=m,f[i][a[i]]=1;
			for (int j=0; j<m; j++)  f[i][(j+a[i])%m]|=f[i-1][j],f[i][j]|=f[i-1][j];
		}
	if (f[n][0])  printf("YES");  else  printf("NO");
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
