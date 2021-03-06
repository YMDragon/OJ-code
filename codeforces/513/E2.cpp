#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define upd(x,y)  {if (x<y)  x=y;}
using namespace std;

int n,k,a[100010],f[2][205][4][2],ans;

void work()
{
	scanf("%d %d",&n,&k);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	int now=0,las=1;
	for (int j=0; j<=k; j++)
		for (int l=0; l<4; l++)
			f[now][j][l][0]=f[now][j][l][1]=-1<<30;
	f[now][0][0][1]=f[now][0][1][1]=f[now][0][2][1]=f[now][0][3][1]=0;
	for (int i=1; i<=n; i++)
		{
			swap(now,las);
			for (int j=0; j<=k; j++)
				for (int l=0; l<4; l++)
					f[now][j][l][0]=f[now][j][l][1]=-1<<30;
			f[now][0][0][1]=f[now][0][1][1]=f[now][0][2][1]=f[now][0][3][1]=0;
			for (int j=1; j<=k; j++)
				for (int l=0; l<4; l++)
					{
						if (((j==1)||(j==k))&&((l==0)||(l==3)))  continue;
						upd(f[now][j][l][0],f[las][j-1][2*(l&1)][1]);
						upd(f[now][j][l][0],f[las][j-1][2*(l&1)+1][1]);
						upd(f[now][j][l][0],f[las][j][l][0]);
						f[now][j][l][0]+=a[i]*((j==1)||(j==k)?1:2)*(l==1?-1:l==2?1:0);
						upd(f[now][j][l][1],f[now][j][l][0]);
						upd(f[now][j][l][1],f[las][j][l][1]);
					}
			for (int j=0; j<4; j++)
				upd(ans,f[now][k][j][1]);
		}
	printf("%d",ans);
}

int main()
{
	freopen("E2.in","r",stdin);
	freopen("E2.out","w",stdout);
	work();
	return 0;
}
