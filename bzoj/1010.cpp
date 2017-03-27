#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int n,l,c[50010],g[50010];
LL s[50010],f[50010];

void work()
{
	scanf("%d %d",&n,&l);
	for (int i=1; i<=n; i++)
		scanf("%d",&c[i]),s[i]=s[i-1]+c[i]+1;
	for (int i=1; i<=n; i++)
		{
			f[i]=(s[i]-l-1)*(s[i]-l-1);
			for (int j=g[i-1]; j<i; j++)
				if (f[j]+(s[i]-s[j]-l-1)*(s[i]-s[j]-l-1)<f[i])
					f[i]=f[j]+(s[i]-s[j]-l-1)*(s[i]-s[j]-l-1),g[i]=j;
		}
	printf("%lld",f[n]);
}

int main()
{
	freopen("1010.in","r",stdin);
	freopen("1010.out","w",stdout);
	work();
	return 0;
} 
