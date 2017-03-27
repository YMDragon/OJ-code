#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int sg[1010],n,m,a[20],b[20],vis[20],ans;

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for (int i=1; i<=m; i++)
		scanf("%d",&b[i]);
	sort(b+1,b+m+1);
	for (int i=1; i<=1000; i++)
		{
			for (int j=1; j<=m; j++)
				if (b[j]<=i)
					vis[sg[i-b[j]]]=i;
			for (int j=0; ; j++)
				if (vis[j]!=i)  {sg[i]=j;  break;}
		}
	for (int i=1; i<=n; i++)
		ans^=sg[a[i]];
	if (ans==0)  {printf("NO");  return;}  else  printf("YES\n");
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if ((ans^sg[a[i]]^sg[a[i]-b[j]])==0)  {printf("%d %d",i,b[j]);  return;}
}

int main()
{
	freopen("1874.in","r",stdin);
	freopen("1874.out","w",stdout);
	work();
	return 0;
} 
