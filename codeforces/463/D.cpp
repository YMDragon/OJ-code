#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,k,a[6][1010],f[1010],b[6][1010],ans;

void work()
{
	scanf("%d %d",&n,&k);
	for (int i=1; i<=k; i++)
		for (int j=1; j<=n; j++)
			scanf("%d",&a[i][j]),b[i][a[i][j]]=j;
	for (int i=1; i<=n; i++)
		{
			f[i]=1;
			for (int j=1; j<i; j++)
				{
					int t=1;
					for (int l=2; l<=k; l++)
						if (b[l][a[1][i]]<b[l][a[1][j]])
							t=0;
					if (t)  f[i]=max(f[i],f[j]+1);
				}
			ans=max(ans,f[i]);
		}
	printf("%d",ans);
}

int main()
{
	freoepn("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
