#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int n=300000,m,p[30000],x[30000],y[30000],ans[30000];
bool b[300010];

int ksm(int a,int b,int mo)
{
	int x=a;  a=1;
	while (b)
		{
			if (b&1)  a=1LL*a*x%mo;
			x=1LL*x*x%mo,b>>=1;
		}
	return a;
}

void work()
{
	b[1]=1;
	for (int i=2; i<=n; i++)
		{
			if (!b[i])  p[++m]=i;
			for (int j=1; j<=m&&i*p[j]<=n; j++)
				{
					b[i*p[j]]=1;
					if (i%p[j]==0)  break;
				}
		}
	for (int i=1; i<=m; i++)  x[i]=0,y[i]=1;
	for (int i=1; i<=m; i++)
		{
			int k=1LL*(i-x[i]+p[i])*ksm(y[i],p[i]-2,p[i])%p[i];
			ans[0]+=ans[i]*p[i];
			for (int j=i+1; j<=m; j++)
				{
					x[j]=(x[j]+1LL*k*y[j])%p[j],y[j]=1LL*y[j]*p[i]%p[j];
					if (x[j]==0)  ans[j]=1;
				}
		}
	printf("%d\n",ans[0]);
}

int main()
{
	work();
	return 0;
}
