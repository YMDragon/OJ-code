#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,b,mo,a[505],f[2][505][505],ans;

void work()
{
	scanf("%d %d %d %d",&n,&m,&b,&mo);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	int cur=1,nex=0;
	f[cur][0][0]=1;
	for (int i=1; i<=n; i++)
		{
			for (int j=0; j<=m; j++)
				for (int k=0; k<=b; k++)
					{
						f[nex][j][k]=f[cur][j][k];
						if ((j>=1)&&(k>=a[i]))  (f[nex][j][k]+=f[nex][j-1][k-a[i]])%=mo;
					}
			swap(cur,nex);
		}
	for (int i=0; i<=b; i++)  (ans+=f[cur][m][i])%=mo;
	printf("%d",ans);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
