#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

int n,m,x[501];
double ans;

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=n; i++)  scanf("%d",&x[i]);
	for (int i=1,a,b,c; i<=m; i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			ans=max(ans,double(x[a]+x[b])/c);
		}
	printf("%.10lf",ans);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
} 
