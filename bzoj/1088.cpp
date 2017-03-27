#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int a[10010],b[10010],n,ans;

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for (b[1]=0; b[1]<2; b[1]++)
	{
		for (int i=1; i<=n; i++)
		{
			b[i+1]=a[i]-b[i]-b[i-1];
			if ((b[i+1]!=0)&&(b[i+1]!=1))  break;
			if ((i==n)&&(b[n+1]==0))
				ans++;
		}
	}
	printf("%d",ans);
}

int main()
{
	freopen("1088.in","r",stdin);
	freopen("1088.out","w",stdout);
	work();
	return 0;
}
