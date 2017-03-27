#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,c[105],l[8][105];
double p[8][105],ans[8];

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&c[i]);
	for (int i=1; i<=7; i++)
		for (int j=1; j<=n; j++)
			scanf("%lf",&p[i][j]);
	for (int i=1; i<=7; i++)
		for (int j=1; j<=n; j++)
			scanf("%d",&l[i][j]);
	ans[0]=0;
	for (int i=1,ok; i<=7; i++)
		{
			ok=0;
			for (int j=1; j<=n; j++)
				if (p[i][j]>0)
					{
						if (ok)
							ans[i]=min(ans[i],(c[j]+(1-p[i][j])*(ans[i-1]-ans[i-l[i][j]-1]))/p[i][j]);
						else  ans[i]=(c[j]+(1-p[i][j])*(ans[i-1]-ans[i-l[i][j]-1]))/p[i][j],ok=1;
					}
			if (!ok)  {printf("-1");  return;}
			ans[i]+=ans[i-1];
		}
	printf("%.10lf",ans[7]);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
