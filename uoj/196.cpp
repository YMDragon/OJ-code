#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

const int mo=int(1e9+7);
int n,q,a[405],f[405][405],s[405],Calc[405][405],ans;
map <int,int> M[405];

void work()
{
	scanf("%d %d",&n,&q);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	for (int i=1; i<=n; i++)  Calc[i][0]=1LL*i*(i+1)/2%mo;
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j++)
			Calc[i][j]=(0LL+Calc[i-1][0]+Calc[j-i+1][0]+Calc[n-j][0])%mo;
	for (int i=1,l,r; i<=n; i++)
		{
			l=i,r=i;
			while ((l>1)&&(a[l-1]<=a[i]))  l--;
			while ((r<n)&&(a[r+1]<=a[i]))  r++;
			for (int j=l; j<=r; j++)
				for (int k=l; k<=r; k++)
					f[j][k]=0;
			f[l][r]=1;
			for (int t=q; t--; )
				{
					for (int j=l; j<=r; j++)  s[j]=0;
					for (int j=l,sum,_; j<=r; j++)
						{
							sum=0;
							for (int k=r; k>=j; k--)
								{
									_=f[j][k];
									f[j][k]=(1LL*_*Calc[j][k]+s[k]+sum)%mo;
									s[k]=(s[k]+1LL*_*(j-1))%mo;
									sum=(sum+1LL*_*(n-k))%mo;
								}
						}
				}
			for (int j=l,sum; j<=r; j++)
				{
					sum=0;
					for (int k=r; k>=j; k--)
						sum=(sum+f[j][k])%mo,M[k][a[i]]=(M[k][a[i]]+sum)%mo;
				}
		}
	for (int i=1,_,ans; i<=n; i++)
		{
			_=ans=0;
			for (map <int,int>::iterator x=M[i].begin(); x!=M[i].end(); x++)
				ans=(ans+1LL*((*x).second+mo-_)*(*x).first)%mo,_=(*x).second;
			printf("%d ",ans);
		}
}

int main()
{
	freopen("196.in","r",stdin);
	freopen("196.out","w",stdout);
	work();
	return 0;
}
