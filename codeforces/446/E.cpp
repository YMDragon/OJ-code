#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const LL mo=1051131,div2=525566;
LL m,t,s,n,a[(1<<25)+10],ans;

LL pow(LL a,LL b)
{
	LL x=a;a=1;
	while (b)
		{
			if (b&1)  a=a*x%mo;
			x=x*x%mo,b>>=1;
		}
	return a;
}

void solve(int n,int p,int q)
{
	if (n==1)
		{
			a[1]=a[1]*pow((p+q)%mo,t)%mo;
			return;
		}
	n>>=1;
	for (int i=1; i<=n; i++)
		{
			LL x=a[i],y=a[i+n];
			a[i]=(x+y)%mo,a[i+n]=(x-y+mo)%mo;
		}
	solve(n,p*2%mo,((n-1)*p+q)%mo);
	LL s=pow(((1-n)*p%mo+q+mo)%mo,t);
	for (int i=n+1; i<=2*n; i++)  a[i]=(a[i]*s+mo)%mo;
	for (int i=1; i<=n; i++)
		{
			LL x=a[i],y=a[i+n];
			a[i]=(x+y)*div2%mo,a[i+n]=(x-y+mo)*div2%mo;
		}
}

void work()
{
	scanf("%lld %lld %lld",&m,&t,&s),n=1<<m;
	for (int i=1; i<=s; i++)  scanf("%lld",&a[i]);
	for (int i=s+1; i<=n; i++)  a[i]=(101*a[i-s]+10007)%mo;
	solve(n,1,0);
	for (int i=1; i<=n; i++)  ans^=a[i];
	printf("%lld",ans);
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
