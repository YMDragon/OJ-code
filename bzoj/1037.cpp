#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=12345678;
int f[160][160][30][30];
int n,m,k,ans;

void work()
{
	scanf("%d %d %d",&n,&m,&k);
	int b,g,bk,gk;
	f[0][0][0][0]=1;
	for (int i=0; i<=n+m; i++)
		for (b=0; b<=min(n,i); b++)
		{
			g=i-b;
			if (g>m)  continue;
			for (bk=0; bk<=k; bk++)
				for (gk=0; gk<=k; gk++)
				{
					if ((bk<k)&&(b<n))
						f[b+1][g][bk+1][max(gk-1,0)]=(f[b+1][g][bk+1][max(gk-1,0)]+f[b][g][bk][gk])%mo;
					if ((gk<k)&&(g<m))
						f[b][g+1][max(bk-1,0)][gk+1]=(f[b][g+1][max(bk-1,0)][gk+1]+f[b][g][bk][gk])%mo;
				}
		}
	for (int i=0; i<=k; i++)
		for (int j=0; j<=k; j++)
			ans=(ans+f[n][m][i][j])%mo;
	printf("%d",ans);
} 

int main()
{
	freopen("1037.in","r",stdin);
	freoepn("1037.out","w",stdout);
	work();
	return 0;
}
