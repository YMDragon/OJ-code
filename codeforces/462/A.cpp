#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,a[105][105];

void work()
{
	char ch[105];
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		{
			scanf("\n%s",ch+1);
			for (int j=1; j<=n; j++)
				a[i][j]=(ch[j]=='o');
		}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if ((a[i-1][j]+a[i][j-1]+a[i+1][j]+a[i][j+1])&1)
				{printf("NO");  return;}
	printf("YES");
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
