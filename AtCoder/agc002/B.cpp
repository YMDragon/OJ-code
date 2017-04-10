#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,num[100010],red[100010],ans;

void work()
{
	scanf("%d %d",&n,&m),red[1]=1;
	for (int i=1; i<=n; i++)  num[i]=1;
	for (int i=1,x,y; i<=m; i++)
		{
			scanf("%d %d",&x,&y);
			if (red[x])  red[y]=1;
			num[x]--,num[y]++;
			if (!num[x])  red[x]=0;
		}
	for (int i=1; i<=n; i++)  ans+=red[i];
	printf("%d",ans);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
