#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef pair<int,int>  PII;
const int prime[9]={0,2,3,5,7,11,13,17,19};
int n,m,M,p,ans,f[256][256],g[2][256][256];
PII a[505];

void work()
{
	scanf("%d %d",&n,&p);
	for (int i=2,x; i<=n; i++)
		{
			x=i;
			for (int j=1; j<=8; j++)
				if (!(x%prime[j]))
					{
						a[i].second|=1<<(j-1);
						for (; !(x%prime[j]); x/=prime[j]);
					}
			a[i].first=x;
		}
	sort(a+2,a+n+1);
	f[0][0]=1;
	for (int i=2; i<=n; i++)
		{
			if ((i==2)||(a[i].first==1)||(a[i].first!=a[i-1].first))
				memcpy(g[0],f,sizeof(f)),memcpy(g[1],f,sizeof(f));
			for (int j=255; j>=0; j--)
				for (int k=255; k>=0; k--)
					{
						if (!(a[i].second&k))  (g[0][j|a[i].second][k]+=g[0][j][k])%=p;
						if (!(a[i].second&j))  (g[1][j][k|a[i].second]+=g[1][j][k])%=p;
					}
			if ((i==n)||(a[i].first==1)||(a[i].first!=a[i+1].first))
				for (int j=0; j<=255; j++)
					for (int k=0; k<=255; k++)
						f[j][k]=((g[0][j][k]+g[1][j][k]-f[j][k])%p+p)%p;
		}
	for (int i=0; i<=255; i++)
		for (int j=0; j<=255; j++)
			if (!(i&j))
				(ans+=f[i][j])%=p;
	printf("%d",ans);
}

int main()
{
	freopen("129.in","r",stdin);
	freopen("129.out","w",stdout);
	work();
	return 0;
}
