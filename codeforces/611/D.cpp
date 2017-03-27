#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const int seed=173,mo=int(1e9+7);
int n,hs[5010],sd[5010],f[5010][5010];
char ch[5010];

int get(int l,int r)
{
	return (hs[r]-1LL*hs[l-1]*sd[r-l+1]%mo+mo)%mo;
}

void work()
{
	scanf("%d\n%s",&n,ch+1),sd[0]=1;
	for (int i=0; i<=n; i++)  f[0][i]=1;
	for (int i=1; i<=n; i++)
		hs[i]=(1LL*hs[i-1]*seed+ch[i])%mo,sd[i]=1LL*sd[i-1]*seed%mo;
	for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=i; j++)
				if (ch[i-j+1]!='0')
					{
						f[i][j]=f[i-j][j-1];
						if (f[i-j][j-1]!=f[i-j][j])
							{
								int l=0,r=j+1,mid;
								while (r-l>1)
									{
										mid=(l+r)>>1;
										if (get(i-2*j+1,i-2*j+mid)==get(i-j+1,i-j+mid))
											l=mid;  else  r=mid;
									}
								if ((l!=j)&&(ch[i-j+l+1]>ch[i-2*j+l+1]))
									(f[i][j]+=f[i-j][j]-f[i-j][j-1])%=mo;
							}
						(f[i][j]+=f[i][j-1])%=mo;
					}else  f[i][j]=f[i][j-1];
			for (int j=i+1; j<=n; j++)  f[i][j]=f[i][j-1];
		}
	printf("%d",f[n][n]);
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
