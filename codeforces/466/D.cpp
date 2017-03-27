#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=1000000007;
int n,h,a[2010],f[2010][2010],ans;

void work()
{
	scanf("%d %d",&n,&h);
	for (int i=1; i<=n; i++)
		{
			scanf("%d",&a[i]),a[i]=h-a[i];
			if (a[i]<0)  {printf("0");  return;}
		}
	for (int i=0; i<=n; i++)
		if (fabs(a[i]-a[i+1])>1)  {printf("0");  return;}
	f[0][0]=1;
	for (int i=1; i<=n; i++)
		for (int j=a[i]; j<=i; j++)
			if (a[i]==a[i-1])  f[i][j]=(f[i-1][j]+1LL*f[i-1][j-1]*a[i-1]%mo)%mo;
			else  if (a[i]>a[i-1])  f[i][j]=f[i-1][j-1];
			else  if (a[i]<a[i-1])  f[i][j]=1LL*f[i-1][j]*a[i-1]%mo;
	for (int i=a[n]; i<=n; i++)  ans=(ans+f[n][i])%mo;
	printf("%d",ans);
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
