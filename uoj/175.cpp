#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

typedef unsigned long long  ULL;
int n,m,a[100010],ans[100010];
ULL hs[100010];
vector <int> V[100010];

void clear()
{
	memset(ans,0,sizeof(ans));
	for (int i=1; i<=n; i++)  V[i].clear();
}

bool cmp(int x,int y){return hs[x]<hs[y];}

void solve()
{
	for (int i=1; i<=n; i++)
		{
			hs[i]=1;
			for (int j=0; j<V[i].size(); j++)
				hs[i]=hs[i]*(V[i][j]*2+233333);
			a[i]=i;
		}
	sort(a+1,a+n+1,cmp);
	for (int i=1; i<n; i++)
		if (hs[a[i]]==hs[a[i+1]])
			ans[a[i]]=ans[a[i+1]]=1;
}

void work()
{
	scanf("%d %d",&n,&m),clear();
	for (int i=1,u,v; i<=m; i++)
		scanf("%d %d",&u,&v),V[u].push_back(v),V[v].push_back(u);
	for (int i=1; i<=n; i++)
		if (V[i].size()==1)  ans[i]=ans[V[i][0]]=1;
	solve();
	for (int i=1; i<=n; i++)
		V[i].push_back(i);
	solve();
	for (int i=1; i<=n; i++)  ans[0]+=ans[i];
	printf("%d\n",ans[0]);
	for (int i=1; i<=n; i++)  if (ans[i])  printf("%d ",i);
	puts("");
}

int main()
{
	freopen("175.in","r",stdin);
	freopen("175.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
