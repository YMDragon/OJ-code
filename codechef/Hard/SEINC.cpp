#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,a[100010],b[100010],k[5],ans;

void work()
{
	scanf("%d",&n),ans=0,memset(k,0,sizeof(k));
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	for (int i=1; i<=n; i++)  scanf("%d",&b[i]),a[i]=(b[i]-a[i]+4)%4;
	for (int i=1; i<=n; i++)
		{
			if (a[i-1]!=a[i])  k[(a[i]-a[i-1]+4)%4]++;  else  k[4]++;
			if (a[i-1]>=a[i])  continue;
			for (int j=1; j<=4; j++)  if (k[j])  {ans+=j,k[j]--;  break;}
		}
	printf("%d\n",ans);
}

int main()
{
	freopen("SEINC.in","r",stdin);
	freopen("SEINC.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
