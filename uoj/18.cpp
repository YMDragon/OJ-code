#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int d,n,x[25],y[25],k[25],ans,ansg;

void work()
{
	scanf("%d %d",&d,&n);
	for (int i=1; i<=n; i++)
		scanf("%d %d %d",&x[i],&y[i],&k[i]);
	for (int i=0; i<=128; i++)
		for (int j=0; j<=128; j++)
			{
				int res=0;
				for (int l=1; l<=n; l++)
					if (max(fabs(i-x[l]),fabs(j-y[l]))<=d)
						res+=k[l];
				if (res>ans)  ans=res,ansg=0;
				if (res==ans)  ansg++;
			}
	printf("%d %d",ansg,ans);
}

int main()
{
	freopen("18.in","r",stdin);
	freopen("18.out","w",stdout);
	work();
	return 0;
}
