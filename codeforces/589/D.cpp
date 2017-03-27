#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,t[1010],s[1010],f[1010],ft[1010];

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d %d %d",&t[i],&s[i],&f[i]),ft[i]=fabs(s[i]-f[i])+t[i];
	for (int i=1; i<=n; i++)
		{
			int res=0;
			for (int j=1; j<=n; j++)
				if ((s[i]<f[i])!=(s[j]<f[j]))
					{
						int T=(s[i]<f[i])?(s[j]-s[i]+t[j]+t[i]):(s[i]+t[i]-s[j]+t[j]);
						if ((T>=t[i]*2)&&(T>=t[j]*2)&&(T<=ft[i]*2)&&(T<=ft[j]*2))  res++;
					}else
					{
						int tag=(s[i]<f[i])?(s[i]-t[i]==s[j]-t[j]):(s[i]+t[i]==s[j]+t[j]);
						if ((tag)&&(max(t[i],t[j])<=min(ft[i],ft[j])))
							res++;
					}
			printf("%d ",res-1);
		}
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
