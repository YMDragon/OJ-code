#include <cstdlib>
#include <cstdio>
using namespace std;

int n,m,a[110],ans;

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]),a[i]=(a[i]+m-1)/m;
	for (int i=n; i>=1; i--)  if (a[i]>a[ans])  ans=i;
	printf("%d",ans);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
