#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int n=100000000,p[10000010],s[100000010];
bool b[100000010],c[100000010];
LL ans;

void work()
{
	b[1]=1,c[1]=1;
	for (int i=2,m=0; i<=n; i++)
		if (!b[i])
			for (LL j=i,k=0,mul=1,x; j<=n; j*=i)
				{
					while (mul<j)
						{
							x=(k+=i);
							while (x%i==0)  mul*=i,x/=i;
							}
					s[j]=k,c[j]=1,p[++m]=j;
					for (int l=j; l<=n; l+=j)
						if (s[l]<s[j])  s[l]=s[j],b[l]=1;
				}
	for (int i=1; i<=n; i++)  ans+=s[i];
	printf("%lld\n",ans);
}

int main()
{
	work();
	return 0;
}
