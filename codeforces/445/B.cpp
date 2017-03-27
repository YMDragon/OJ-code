#include <cstdlib>
#include <cstdio>
#define LL  long long
using namespace std;

int n,m,e[51][51],vis[51],s;

void dfs(int x)
{
	for (int i=1; i<=n; i++)
		if ((e[x][i])&&(!vis[i]))
			vis[i]=1,dfs(i);
}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1,x,y; i<=m; i++)
		scanf("%d %d",&x,&y),e[x][y]=1,e[y][x]=1;
	for (int i=1; i<=n; i++)
		if (!vis[i])  dfs(i),s++;
	printf("%lld",(1LL)<<(n-s));
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
} 
