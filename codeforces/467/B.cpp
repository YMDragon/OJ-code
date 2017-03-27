#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,k,x[1010],ans;

void work()
{
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1; i<=m+1; i++)
		scanf("%d",&x[i]);
	for (int i=1; i<=m; i++)
		{
			int a=x[i],b=x[m+1],t=0;
			while ((a)||(b))
				{
					if ((a&1)!=(b&1))  t++;
					a>>=1,b>>=1;
				}
			if (t<=k)  ans++;
		}
	printf("%d",ans);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
