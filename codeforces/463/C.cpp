#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long  LL;
int n,a[2010][2010];
LL sum1[4010],sum2[4010],sum[2010][2010],ans1=-1,ans2=-1,x1,y1,x2,y2;

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			scanf("%d",&a[i][j]),sum1[i-j+n]+=1LL*a[i][j],sum2[i+j-1]+=1LL*a[i][j];
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			{
				LL s=sum1[i-j+n]+sum2[i+j-1]-a[i][j];
				if ((i+j)&1)
					{
						if (s>ans1)  ans1=s,x1=i,y1=j;
					}else
					{
						if (s>ans2)  ans2=s,x2=i,y2=j;
					}
			}
	printf("%I64d\n%I64d %I64d %I64d %I64d",ans1+ans2,x1,y1,x2,y2);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
