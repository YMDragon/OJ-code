#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,a[105],s[105],ans;

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=m; i++)
		{
			for (int j=1; j<=n; j++)
				scanf("%d",&a[j]);
			int Max=1;
			for (int j=1; j<=n; j++)
				if (a[Max]<a[j])  Max=j;
			s[Max]++;
		}
	ans=1;
	for (int i=1; i<=n; i++)
		if (s[ans]<s[i])  ans=i;
	printf("%d",ans);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
