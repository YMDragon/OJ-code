#include <bits/stdc++.h>
using namespace std;

int n,a[105][105],b[105][105][105];

bool check()
{
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			for (int k=j+1; k<=n; k++)
				b[i][j][k]=0;
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			for (int k=j+1; k<=n; k++)
				{
					int x=a[i][j],y=a[j][k],z=a[i][k];
					if (x>y)  swap(x,y);
					if (x>z)  swap(x,z);
					if (y>z)  swap(y,z);
					if (b[x][y][z])  return 0;
					b[x][y][z]=1;
				}
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			printf("%d %d %d\n",i,j,a[i][j]);
	return 1;
}

bool dfs(int x,int y)
{
	if (x>n)  return check();
	if (y>n)  return dfs(x+1,x+2);
	int c[11];
	for (int i=1; i<=n; i++)  c[i]=0;
	for (int i=1; i<x; i++)  c[a[i][y]]=1;
	for (int i=1; i<y; i++)  c[a[i][x]]=c[a[x][i]]=1;
	for (a[x][y]=1; a[x][y]<=n; a[x][y]++)
		if (!c[a[x][y]])
			if (dfs(x,y+1))  
				return 1;
	return 0;
}

void work()
{
	scanf("%d",&n),printf("%d\n",n);
	//if (!dfs(1,2))  printf("No solution\n");
	if (n&1)
		{
			for (int i=1; i<=n; i++)
				for (int j=i+1; j<=n; j++)
					printf("%d %d %d ",i,j,(i+j-3)%n+1);
			puts("");
		}else  puts("No solution");
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
