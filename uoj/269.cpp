#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=998244353;
int n,m,x,a[20010],b[20010],fac[20010],ifac[20010],ans;

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
	scanf("%d %d %d",&n,&m,&x);
	for (int i=0; i<=m; i++)  scanf("%d",&a[i]);
	for (int i=0; i<=m; i++)
		{
			b[i]=a[0];
			for (int j=0; j<m-i; j++)
				a[j]=(a[j+1]-a[j]+mo)%mo;
		}
	fac[0]=1;
	for (int i=1; i<=m; i++)  fac[i]=1LL*fac[i-1]*i%mo;
	ifac[m]=qpow(fac[m],mo-2);
	for (int i=m; i; i--)  ifac[i-1]=1LL*ifac[i]*i%mo;
	for (int i=0,_=1; i<=m; i++)
		{
			ans=(ans+1LL*b[i]*ifac[i]%mo*_)%mo;
			_=1LL*_*x%mo*(n-i)%mo;
		}
	printf("%d",ans);
}

int main()
{
	freopen("269.in","r",stdin);
	freopen("269.out","w",stdout);
	work();
	return 0;
}
