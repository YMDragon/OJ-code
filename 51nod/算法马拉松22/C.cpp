#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const int N=205,mo=998244353;
struct ENC{LL e,c;ENC(LL e=0,LL c=0):e(e),c(c){}}ing[N];
int n;
LL g[N][N],sol[N],ans[2][N];

ENC operator + (ENC a,ENC b){return ENC((a.e+b.e)%mo,(a.c+b.c)%mo);}
ENC operator - (ENC a,ENC b){return ENC((a.e-b.e+mo)%mo,(a.c-b.c+mo)%mo);}
ENC operator * (ENC a,LL b){return ENC(a.e*b%mo,a.c*b%mo);}

LL qpow(LL a,LL b)
{
	LL x=a;  a=1;
	while (b)
		{
			if (b&1)  a=a*x%mo;
			x=x*x%mo,b>>=1;
		}
	return a;
}

void gauss()
{
	for (int i=0; i<n; i++)
		{
			LL tmp=qpow(g[i][i],mo-2);
			for (int j=i+1; j<=n; j++) 
				for (int k=n+1; k>=i; k--)
					g[j][k]=(g[j][k]-tmp*g[i][k]%mo*g[j][i]%mo+mo)%mo;
		}
	for (int i=n; i>=0; i--)
		{
			for (int j=i+1; j<=n; j++)
				g[i][n+1]=(g[i][n+1]-sol[j]*g[i][j]%mo+mo)%mo;
			sol[i]=g[i][n+1]*qpow(g[i][i],mo-2)%mo;
		}
}

void prepare()
{
	ing[0].e=1,ing[0].c=mo-1;
	for (int i=1; i<=200; i++)
		ing[i]=ENC(1,0)-ing[i-1]*i;
}

void work()
{
	scanf("%d",&n);
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			g[i][j]=qpow(i+j+1,mo-2);
	for (int i=0; i<=n; i++)  g[i][n+1]=ing[i].c;
	gauss();
	for (int i=0; i<=n; i++)  ans[0][i]=sol[i];
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			g[i][j]=qpow(i+j+1,mo-2);
	for (int i=0; i<=n; i++)  g[i][n+1]=ing[i].e;
	gauss();
	for (int i=0; i<=n; i++)  ans[1][i]=sol[i];
	for (int i=0; i<=n; i++)  printf("%lld %lld\n",ans[1][i],ans[0][i]);

}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int t;
	scanf("%d",&t),prepare();
	while (t--)  work();
	return 0;
}
