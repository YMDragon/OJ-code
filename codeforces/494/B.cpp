#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=int(1e9+7),sd=131;
char s[100010],t[100010];
int n,m,hsh[100010],po=1,hs,p[100010],f[100010],s1[100010],s2[100010],ans;

void work()
{
	scanf("%s\n%s",s+1,t+1),n=strlen(s+1),m=strlen(t+1);
	for (int i=1; i<=n; i++)
		hsh[i]=(1LL*hsh[i-1]*sd+s[i])%mo;
	for (int i=1; i<=m; i++)
		hs=(1LL*hs*sd+t[i])%mo,po=1LL*po*sd%mo;
	for (int i=1; i<=n-m+1; i++)
		if ((hsh[i+m-1]-1LL*hsh[i-1]*po%mo+mo)%mo==hs)  p[i+m-1]=i;
	for (int i=1; i<=n; i++)  p[i]=p[i]?p[i]:p[i-1];
	s1[0]=1;
	for (int i=1; i<=n; i++)
		{
			s1[i]=s1[i-1],s2[i]=s2[i-1];
			if (!p[i])  continue;
			f[i]=(1LL*p[i]*s1[p[i]-1]%mo-s2[p[i]-1]+mo)%mo;
			ans=(ans+f[i])%mo,s1[i]=(s1[i]+f[i])%mo,s2[i]=(s2[i]+1LL*f[i]*i%mo)%mo;
		}
	printf("%d",ans);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
