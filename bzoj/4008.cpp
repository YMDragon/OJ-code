#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,r,d[225];
double p[225],f[225][135],s[225],Pow[225][135],ans;

void work()
{
	scanf("%d %d",&n,&r);
	for (int i=1; i<=n; i++)
		{
			scanf("%lf %d",&p[i],&d[i]),Pow[i][0]=1;
			for (int j=1; j<=r; j++)  Pow[i][j]=Pow[i][j-1]*(1-p[i]);
		}
	memset(f,0,sizeof(f)),memset(s,0,sizeof(s));
	f[0][r]=1;
	for (int i=0; i<n; i++)
		for (int j=1; j<=r; j++)
			{
				f[i+1][j]+=Pow[i+1][j]*f[i][j];
				f[i+1][j-1]+=(1-Pow[i+1][j])*f[i][j];
				s[i+1]+=(1-Pow[i+1][j])*f[i][j];
			}
	ans=0;
	for (int i=1; i<=n; i++)  ans+=s[i]*d[i];
	printf("%.8lf\n",ans);
}

int main()
{
	freopen("4008.in","r",stdin);
	freopen("4008.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
