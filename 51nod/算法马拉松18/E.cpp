#include <bits/stdc++.h>
using namespace std;

const int mo=int(1e9+7);
int n,k,m,f[500010],prime[500010],b[500010],mp[500010],h[500010],g[500010];
int fac[500010],facinv[500010],inv[500010];

int getint()
{
	int w=0;  char ch=getchar();
	while ((ch<'0')||('9'<ch))  ch=getchar();
	while (('0'<=ch)&&(ch<='9'))  w=(10LL*w+ch-'0')%mo,ch=getchar();
	return w;
}

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

int calc(int s)
{
	int res=1;
	for (int i=1; i<=s; i++)
		res=1LL*res*(k+s-i)%mo*facinv[i]%mo*fac[i-1]%mo;
	return res;
}

void work()
{
	n=getint(),k=getint();
	for (int i=1; i<=n; i++)  f[i]=getint();
	b[1]=1;
	for (int i=2; i<=n; i++)
		{
			if (!b[i])  prime[++m]=i,mp[i]=i;
			for (int j=1; i*prime[j]<=n&&j<=m; j++)
				{
					b[i*prime[j]]=1,mp[i*prime[j]]=prime[j];
					if (i%prime[j]==0)  break;
				}
		}
	fac[0]=1;
	for (int i=1; i<=n; i++)  fac[i]=1LL*fac[i-1]*i%mo;
	facinv[n]=qpow(fac[n],mo-2);
	for (int i=n; i; i--)  facinv[i-1]=1LL*facinv[i]*i%mo;
	h[1]=1;
	for (int i=2,x,t; i<=n; i++)
		{
			x=i,t=0;
			while (x%mp[i]==0)  x/=mp[i],t++;
			h[i]=1LL*h[x]*calc(t)%mo;
		}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n/i; j++)
			g[i*j]=(g[i*j]+1LL*f[i]*h[j])%mo;
	for (int i=1; i<=n; i++)
		printf("%d ",g[i]);
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
