#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,b[1010],ans[1010];

void work()
{
	scanf("%d",&n);
	for (int i=2; i<=n; i++)
		{
			if (b[i])  continue;
			for (int j=i; j<=n; j*=i)  ans[++ans[0]]=j;
			for (int j=2*i; j<=n; j+=i)  b[j]=1;
		}
	printf("%d\n",ans[0]);
	for (int i=1; i<=ans[0]; i++)
		printf("%d ",ans[i]);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
