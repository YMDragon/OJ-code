#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct edge{int s,t,d;}e[330000];
int n,m,f[805];

bool cmp(edge x,edge y){return x.d>y.d;}

void work()
{
	scanf("%d",&n),n<<=1;
	for (int i=1,x; i<=n; i++)
		for (int j=1; j<i; j++)
			scanf("%d",&x),e[++m]=(edge){j,i,x};
	sort(e+1,e+m+1,cmp);
	for (int i=1; i<=m; i++)
		if ((!f[e[i].s])&&(!f[e[i].t]))
			f[e[i].s]=e[i].t,f[e[i].t]=e[i].s;
	for (int i=1; i<=n; i++)
		printf("%d ",f[i]);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
