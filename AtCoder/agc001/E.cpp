#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=int(1e9+7),Z=2001;
int n,a[200010],b[200010],f[4010][4010],fac[8010],ifac[8010],ans;

int C(int n,int m){return 1LL*fac[n]*ifac[m]%mo*ifac[n-m]%mo;}

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
	scanf("%d",&n),fac[0]=1;
	for (int i=1; i<=8000; i++)  fac[i]=1LL*fac[i-1]*i%mo;
	ifac[8000]=qpow(fac[8000],mo-2);
	for (int i=8000; i; i--)  ifac[i-1]=1LL*ifac[i]*i%mo;
	for (int i=1; i<=n; i++)
		{
			scanf("%d %d",&a[i],&b[i]);
			f[Z-a[i]][Z-b[i]]++;
			ans=(ans+mo-C(2*(a[i]+b[i]),2*a[i]))%mo;
		}
	for (int i=1; i<2*Z; i++)
		for (int j=1; j<2*Z; j++)
			f[i][j]=(f[i][j]+f[i-1][j]+f[i][j-1])%mo;
	for (int i=1; i<=n; i++)  (ans+=f[Z+a[i]][Z+b[i]])%=mo;
	printf("%d",int(1LL*ans*qpow(2,mo-2)%mo));
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
