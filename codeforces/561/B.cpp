#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,d[1000010],ans;

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1,x,y; i<=m; i++)
		scanf("%d %d",&x,&y),d[x]++,d[y]++;
	for (int i=1; i<=n; i++)  ans+=(d[i]&1);
	printf("%d",ans/2);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
