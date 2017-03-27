#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=int(1e9+7);
int n,N,m,c[20][20],b[20],f[1<<16],g[1<<16];

void dfs(int x,int s,int i)
{
	if (x>m)  f[i]=(f[i]-1LL*f[s]*g[i-s]%mo+mo)%mo;
	else  dfs(x+1,s+(1<<(b[x]-1)),i),dfs(x+1,s,i);
}

void work()
{
	scanf("%d",&n),N=1<<n;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			scanf("%d",&c[i][j]);
	for (int i=1; i<N; i++)
		{
			g[i]=1;
			for (int j=1; j<=n; j++)
				if (i&(1<<(j-1)))
					for (int k=j; k<=n; k++)
						if (i&(1<<(k-1)))
							g[i]=(1LL*g[i]*(c[j][k]+1))%mo;
		}
	for (int i=1; i<N; i++)
		{
			m=0;
			for (int j=1; j<=n; j++)
				if (i&(1<<(j-1)))
					b[++m]=j;
			f[i]=g[i],dfs(2,1<<(b[1]-1),i);
		}
	printf("%d",f[N-1]);
}

int main()
{
	freopen("2560.in","r",stdin);
	freopen("2560.out","w",stdout);
	work();
	return 0;
}
