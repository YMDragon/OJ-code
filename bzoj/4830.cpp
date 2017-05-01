#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;

int gi()
{
	int w=0,q=1;  char ch=getchar();
	while (((ch<'0')||('9'<ch))&&(ch!='-'))  ch=getchar();
	if (ch=='-')  q=0,ch=getchar();
	while (('0'<=ch)&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return q?w:-w;
}

void pi(int x)
{
	if (x<0)  putchar('-');
	if (x>9)  pi(x/10);
	putchar(x%10+'0');
}

int qpow(int a,LL b,int mo)
{
	int x=a;  a=1;
	while (b)
		{
			if (b&1)  a=1LL*a*x%mo;
			x=1LL*x*x%mo,b>>=1;
		}
	return a;
}

struct node{
	int p,mo,fac[2000000],ifac[2000000],inv[2000000];

	void calc(LL n,int &x,LL &y)
	{
		if (n<p)  {x=1LL*x*fac[n]%mo;  return;}
		x=1LL*x*fac[n%mo]%mo,y+=n/p;
		if ((n/mo)&1)  x=1LL*x*fac[mo-1]%mo;
		calc(n/p,x,y);
	}

	void init(int m,int P)
	{
		mo=m,p=P,fac[0]=1;
		for (int i=1; i<m; i++)
			if (i%p)  fac[i]=1LL*fac[i-1]*i%mo;
			else  fac[i]=fac[i-1];
		ifac[m-1]=qpow(fac[m-1],mo/p*(p-1)-1,mo);
		for (int i=m-1; i; i--)
			if (i%p)  ifac[i-1]=1LL*ifac[i]*i%mo;
			else  ifac[i-1]=ifac[i];
		for (int i=1; i<m; i++)  if (i%p)  inv[i]=1LL*ifac[i]*fac[i-1]%mo;
	}

	int C(LL n,LL m,bool op)
	{
		int res=1,t=1,x;  LL q=0,y;
		x=1,y=0,calc(n,x,y),res=1LL*res*x,q+=y;
		x=1,y=0,calc(m,x,y),res=1LL*res*inv[x]%mo,q-=y;
		x=1,y=0,calc(n-m,x,y),res=1LL*res*inv[x]%mo,q-=y;
		q=min(q,10LL);
		if (op)  {if (p==2)  q--;  else  res=1LL*res*inv[2]%mo;}
		for (int i=1; i<=q; i++)  t=t*p;
		return 1LL*res*t%mo;
	}

	int solve(LL n,LL m)
	{
		int s=qpow(2,n+m-1,mo);
		if (n==m)  return (s+mo-C(2*n,n,1))%mo;
		for (LL i=m+1,j=n-1; i<=j; i++,j--)
			s=(s+C(n+m,i,i==j))%mo;
		return s;
	}
}a2,a5;

void prepare()
{
	a2.init(512,2),a5.init(1953125,5);
}

void work()
{
	const int mo=int(1e9);
	LL n,m,k;
	if (scanf("%lld %lld %lld",&n,&m,&k)==EOF)  exit(0);
	int ans2=a2.solve(n,m),ans5=a5.solve(n,m);
	int ans=(212890625LL*ans2+787109376LL*ans5)%mo;
	for (int x=qpow(10,k-1,mo); x; x/=10)  putchar(ans/x%10+'0');  puts("");
}

int main()
{
	freopen("4830.in","r",stdin);
	freopen("4830.out","w",stdout);
	for (prepare(); ; )  work();
	return 0;
}
