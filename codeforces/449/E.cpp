#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;

const int N=1000000,mo=1000000007;
LL sgcd[N+10],f[3][N+10],phi[N+10],b[N+10],prime[N],t,n,m,ans;

void getphi()
{
	phi[1]=1;
	for (int i=2,m=0; i<=N; i++)
		{
			if (!b[i])  prime[++m]=i,phi[i]=i-1;
			for (int j=1; j<=m&&prime[j]*i<=N; j++)
				{
					b[i*prime[j]]=1;
					if (i%prime[j]==0)
						{
							phi[i*prime[j]]=phi[i]*prime[j];
							break;
						}
					phi[i*prime[j]]=phi[i]*(prime[j]-1);
				}
		}
}

void work()
{
	getphi();
	for (int i=1; i<=N; i++)
		for (int j=i; j<=N; j+=i)
			sgcd[j]=(sgcd[j]+phi[j/i]*i)%mo;
	for (int i=1; i<=N; i++)
		f[0][i]=(1LL*i*(i+1)*(2*i+1)/3+2*sgcd[i]-3LL*i*i)%mo;
	for (int i=1; i<=N; i++)
		f[1][i]=f[0][i]*i%mo,f[2][i]=f[1][i]*i%mo;
	for (int i=0; i<3; i++)
		for (int j=1; j<=N; j++)
			f[i][j]=(f[i][j]+f[i][j-1])%mo;
	scanf("%lld",&t);
	for (int i=1; i<=t; i++)
		{
			scanf("%lld %lld",&n,&m),n++,m++;
			if (n>m)  swap(n,m);
			ans=(n*m%mo*f[0][n-1]-(n+m)*f[1][n-1]+f[2][n-1])%mo;
			printf("%lld\n",(ans+mo)%mo);
		}
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
