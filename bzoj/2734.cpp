#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const int mo=1000000001;
int n,f[2][1<<12],r,c,a[20][15],b[100010];
LL ans=1;

void incmod(int &a,int b){a=(a+b)%mo;}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		if (!b[i])
			{
				r=c=0;
				memset(a,0,sizeof(a));
				for (int j=1,p=i; p<=n; j++,p*=2,r++)
					for (int k=1,q=p; q<=n; k++,q*=3)
						a[j][k]=q,b[q]=1,c=max(c,k);
				int l=0,m=(1<<c)-1,res=0;
				for (int i=1; i<=m; i++)  f[l][i]=0;
				f[l][0]=1;
				for (int j=1; j<=r; j++)
					for (int k=1; k<=c; k++)
						{
							for (int z=0; z<=m; z++)  f[l^1][z]=0;
							for (int z=0; z<=m; z++)
								if (f[l][z])
									{
										incmod(f[l^1][(z<<1)&m],f[l][z]);
										if ((a[j][k])&&(k==1)&&((z&(1<<(c-1)))==0))
											incmod(f[l^1][((z<<1)|1)&m],f[l][z]);
										if ((a[j][k])&&(k!=1)&&((z&(1<<(c-1)))==0)&&((z&1)==0))
											incmod(f[l^1][((z<<1)|1)&m],f[l][z]);

									}
							l^=1;
						}
				for (int j=0; j<=m; j++)
					incmod(res,f[l][j]);
				ans=ans*res%mo;
			}
	printf("%lld",ans);
}

int main()
{
	freopen("2734.in","r",stdin);
	freopen("2734.out","w",stdout);
	work();
	return 0;
}
