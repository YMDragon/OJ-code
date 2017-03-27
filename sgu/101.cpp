#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,cnt,map[10][10],d[10],a[110][2],ans[110][2];

void dfs(int x)
{
	for (int y=0; y<=6; y++)
		if (map[x][y])
			{
				map[x][y]--,map[y][x]--;
				dfs(y);
				ans[++cnt][0]=x,ans[cnt][1]=y;
			}
}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		{
			scanf("%d %d",&a[i][0],&a[i][1]);
			map[a[i][0]][a[i][1]]++,map[a[i][1]][a[i][0]]++;
			d[a[i][0]]++,d[a[i][1]]++;
		}
	int t=0,s=0;
	for (int i=0; i<=6; i++)
		if (d[i]&1)  t++,s=i;  else  if ((d[i])&&(!s))  s=i;
	if (t>2)  {printf("No solution\n");  return;}
	dfs(s);
	if (cnt<n)
		printf("No solution\n");
	else
		for (int i=n; i>=1; i--)
			for (int j=1; j<=n; j++)
				if ((ans[i][0]==a[j][0])&&(ans[i][1]==a[j][1]))
					{printf("%d +\n",j),a[j][0]=-1;  break;}
				else  if ((ans[i][0]==a[j][1])&&(ans[i][1]==a[j][0]))
					{printf("%d -\n",j),a[j][0]=-1;  break;}
}

int main()
{
	freopen("101.in","r",stdin);
	freopen("101.out","w",stdout);
	work();
	return 0;
}
