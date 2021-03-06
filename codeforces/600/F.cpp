#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int na,nb,m,lmat[1010][1010],rmat[1010][1010],id[1010][1010],ans,color[100010];

void work()
{
	scanf("%d %d %d",&na,&nb,&m);
	for (int i=1,x,y; i<=m; i++)
		{
			scanf("%d %d",&x,&y);
			int u=1,v=1;
			while (lmat[u][x])  u++;
			while (rmat[v][y])  v++;
			id[x][y]=i;
			if (u==v)  lmat[u][x]=y,rmat[v][y]=x;
			else
				{
					lmat[u][x]=y;
					while (1)
						{
							int tmp1=rmat[u][y];
							rmat[u][y]=x,rmat[v][y]=tmp1;
							if (!tmp1)  break;
							int tmp2=lmat[v][tmp1];
							lmat[u][tmp1]=tmp2,lmat[v][tmp1]=y;
							if (!tmp2)  break;
							x=tmp1,y=tmp2;
						}
				}
		}
	for (int i=1; i<=max(na,nb); i++)
		for (int j=1; j<=na; j++)
			if (lmat[i][j])  color[id[j][lmat[i][j]]]=i,ans=max(ans,i);
	printf("%d\n",ans);
	for (int i=1; i<=m; i++)  printf("%d ",color[i]);
}

int main()
{
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
	work();
	return 0;
}
