#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,a[405][405],dis[405],vis[405],ans;

int dij()
{
	for (int i=0; i<=n; i++)  dis[i]=1<<30,vis[i]=0;
	dis[1]=0;
	for (int i=1; i<=n; i++)
		{
			int x=0;
			for (int j=1; j<=n; j++)
				if ((!vis[j])&&(dis[j]<dis[x]))  x=j;
			if ((vis[x])||(x==n))  break;
			vis[x]=1;
			for (int j=1; j<=n; j++)
				if ((a[x][j])&&(dis[x]<dis[j]))  dis[j]=dis[x]+1;
		}
	return dis[n];
}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1,x,y; i<=m; i++)  scanf("%d %d",&x,&y),a[x][y]=a[y][x]=1;
	ans=dij();
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (i!=j)  a[i][j]^=1;
	ans=max(ans,dij());
	printf("%d",(ans!=(1<<30))?ans:-1);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
