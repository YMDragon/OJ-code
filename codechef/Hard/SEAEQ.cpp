#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=int(1e9+7),N=500;
int f[505][125010],g[505][125010],jc[505],jcn[505],n,e,ans;

int ksm(int a,int b)
{
	int x=a;  a=1;
	while (b)
		{
			if (b&1)  a=1LL*a*x%mo;
			x=1LL*x*x%mo,b>>=1;
		}
	return a;
}

void prepare()
{
	f[0][0]=1,g[0][0]=1;
	for (int i=1; i<=N; i++)
		for (int j=0; j<=i*(i-1)/2; j++)
			{
				f[i][j]=(((j>(i-1)*(i-2)/2)?g[i-1][(i-1)*(i-2)/2]:g[i-1][j])-((j>=i)?g[i-1][j-i]:0)+mo)%mo;
				g[i][j]=(j!=0)?(g[i][j-1]+f[i][j])%mo:f[i][j];
			}
	jc[0]=1;
	for (int i=1; i<=N; i++)  jc[i]=1LL*jc[i-1]*i%mo,jcn[i]=ksm(jc[i],mo-2);
}

void work()
{
	scanf("%d %d",&n,&e),ans=0;
	for (int i=1; i<=n; i++)
		{
			int res=1LL*jc[n]*jcn[i]%mo;
			res=1LL*res*res%mo;
			res=1LL*res*(n-i+1)%mo*g[i][min(e,i*(i-1)/2)]%mo;
			(ans+=res)%=mo;
		}
	printf("%d\n",ans);
}

int main()
{
	freopen("SEAEQ.in","r",stdin);
	freopen("SEAEQ.out","w",stdout);
	int t;
	prepare();
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
