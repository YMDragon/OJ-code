#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=int(1e9+7);
int R,G,B,n,s,M,m,f[30][30][55],g[30][55],h[30][30][80],C[80][80],ans;

void work()
{
	scanf("%d %d %d %d",&R,&G,&B,&n);
	s=R+G+B,M=max(R,max(G,B)),m=min(R,min(G,B));
	for (int i=0; i<=s; i++)
		{
			C[i][0]=1;
			for (int j=1; j<=i; j++)
				C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
		}
	h[0][0][0]=1;
	for (int i=0; i<n; i++)
		{
			for (int j=0; j<=M; j++)
				for (int k=0; k<=s; k++)
					if (h[i][j][k])
						for (int l=0; l<=M&&k+l<=s; l++)
							(h[i+1][max(j,l)][k+l]+=h[i][j][k])%=mo;
		}
	for (int i=0; i<=n; i++)
		for (int j=1; j<=M; j++)
			for (int k=0; k<=s; k++)
				(h[i][j][k]+=h[i][j-1][k])%=mo;
	g[0][0]=1;
	for (int i=1; i<=M; i++)
		for (int j=0; j<=s-m; j++)
			for (int H=1; H<=i; H++)
				for (int ii=1; ii<=n; ii++)
					for (int k=0; k+H<=i+j; k++)
						(g[i][j]+=1LL*h[ii-1][H-1][k]*h[n-ii][H][i+j-H-k]%mo*C[i+j-H][i-H]%mo)%=mo;
	f[0][0][0]=1;
	for (int i=1; i<=n; i++)
		for (int j=0; j<=M; j++)
			for (int k=0; k<=s-m; k++)
				for (int jj=0; jj<=j; jj++)
					for (int kk=0; kk<=k; kk++)
						(f[i][j][k]+=1LL*f[i-1][j-jj][k-kk]*g[jj][kk]%mo)%=mo;
	(ans+=1LL*f[n][R][s-R]*C[s-R][G]%mo)%=mo;
	(ans+=1LL*f[n][G][s-G]*C[s-G][B]%mo)%=mo;
	(ans+=1LL*f[n][B][s-B]*C[s-B][R]%mo)%=mo;
	printf("%d",ans);
}

int main()
{
	freopen("4313.in","r",stdin);
	freopen("4313.out","w",stdout);
	work();
	return 0;
}
