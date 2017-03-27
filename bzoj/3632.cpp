#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int e[60][60],n,ans,Max[60],s[60];

void clear(int d){for (int i=1; i<=n; i++)  if (s[i]==d)  s[i]--;}

int dfs(int x,int d)
{
	int k=0;
	for (int i=x+1; i<=n; i++)
		if ((e[x][i])&&(s[i]==d-1))
			s[i]=d,k++;
	if (k)
		{
			for (int i=x+1; i<=n; i++)
				if (s[i]==d)
					{
						if (d+k<=ans)  {clear(d);  return 0;}
						if (d+Max[i]<=ans)  {clear(d);  return 0;}
						if (dfs(i,d+1))  {clear(d);  return 1;}
						k--,s[i]--;
					}
		}else
		{
			if (d>ans){ans=d;  return 1;}
			else  return 0;
		}
	return 0;
}

void work()
{
	scanf("%d",&n);
	int x,y;
	while (scanf("%d %d",&x,&y)!=EOF)
		e[x][y]=1,e[y][x]=1;
	for (int i=n; i>=1; i--)
		{
			for (int j=i; j<=n; j++)  s[j]=0;
			dfs(i,1),Max[i]=ans;
		}
	printf("%d",ans);
}

int main()
{
	freopen("3632.in","r",stdin);
	freopen("3632.out","w",stdout);
	work();
	return 0;
}
