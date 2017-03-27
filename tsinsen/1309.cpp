#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

struct point{int x,y;};
int n,m,a[55][55],dis[55][55],vis[55][55],tot,ans;
queue <point> Q;

bool allisW()
{
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (a[i][j])  return 0;
	return 1;
}

int bfs(int si,int sj)
{
	int x,y,nx,ny,res=0;
	Q.push((point){si,sj}),vis[si][sj]=++tot,dis[si][sj]=0;
	while (!Q.empty())
		{
			x=Q.front().x,y=Q.front().y,Q.pop();
			nx=x,ny=y+1;
			if ((ny<=m)&&((vis[nx][ny]!=tot)||(dis[nx][ny]>dis[x][y]+(a[x][y]^a[nx][ny]))))
				Q.push((point){nx,ny}),vis[nx][ny]=tot,dis[nx][ny]=dis[x][y]+(a[x][y]^a[nx][ny]);
			nx=x,ny=y-1;
			if ((ny>=1)&&((vis[nx][ny]!=tot)||(dis[nx][ny]>dis[x][y]+(a[x][y]^a[nx][ny]))))
				Q.push((point){nx,ny}),vis[nx][ny]=tot,dis[nx][ny]=dis[x][y]+(a[x][y]^a[nx][ny]);
			nx=x+1,ny=y;
			if ((nx<=n)&&((vis[nx][ny]!=tot)||(dis[nx][ny]>dis[x][y]+(a[x][y]^a[nx][ny]))))
				Q.push((point){nx,ny}),vis[nx][ny]=tot,dis[nx][ny]=dis[x][y]+(a[x][y]^a[nx][ny]);
			nx=x-1,ny=y;
			if ((nx>=1)&&((vis[nx][ny]!=tot)||(dis[nx][ny]>dis[x][y]+(a[x][y]^a[nx][ny]))))
				Q.push((point){nx,ny}),vis[nx][ny]=tot,dis[nx][ny]=dis[x][y]+(a[x][y]^a[nx][ny]);
		}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if ((vis[i][j]==tot)&&(a[i][j]))
				res=max(res,dis[i][j]);
	return res;
}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			{
				char ch;
				do  ch=getchar();  while ((ch!='W')&&(ch!='B'));
				a[i][j]=(ch=='B');
			}
	if (allisW())  {printf("0");  return;}
	ans=1<<30;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			ans=min(ans,bfs(i,j));
	printf("%d",ans+1);
}

int main()
{
	freopen("1309.in","r",stdin);
	freopen("1309.out","w",stdout);
	work();
	return 0;
}
