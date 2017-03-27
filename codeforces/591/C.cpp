#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,a[500010],b[500010],ans;

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	for (int i=2; i<n; i++)  b[i]=(a[i]==a[i+1])|(a[i]==a[i-1]);
	b[1]=b[n]=1;
	for (int i=1,t=0; i<=n; i++)
		{
			if (b[i])
				{
					for (int l=i-t,r=i-1; l<=r; l++,r--)  a[l]=a[i-t-1],a[r]=a[i];
					t=0;
				}else  t++;
			ans=max(ans,t);
		}
	printf("%d\n",(ans+1)/2);
	for (int i=1; i<=n; i++)  printf("%d ",a[i]);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
