#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,a[300010],ans;

void work()
{
	scanf("%d %d\n",&n,&m);
	for (int i=1; i<=n; i++)
		{
			char ch=getchar();
			a[i]=(ch=='.');
		}
	for (int i=1; i<n; i++)
		ans+=(a[i])&(a[i+1]);
	for (int i=1,x; i<=m; i++)
		{
			char ch;
			scanf("%d %c",&x,&ch);
			ans-=(a[x-1])&(a[x]),ans-=(a[x])&(a[x+1]);
			a[x]=(ch=='.');
			ans+=(a[x-1])&(a[x]),ans+=(a[x])&(a[x+1]);
			printf("%d\n",ans);
		}
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
