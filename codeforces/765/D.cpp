#include <bits/stdc++.h>
using namespace std;

int n,m,f[100010],g[100010],h[100010],p[100010];

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&f[i]);
	for (int i=1; i<=n; i++)
		if (f[i]==i)
			h[++m]=i,g[i]=m;
	for (int i=1; i<=n; i++)
		if (f[i]==f[f[i]])  g[i]=g[f[i]];
		else  {puts("-1");  return;}
	printf("%d\n",m);
	for (int i=1; i<=n; i++)  printf("%d ",g[i]);  puts("");
	for (int i=1; i<=m; i++)  printf("%d ",h[i]);
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
