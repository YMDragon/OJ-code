#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,a[105],b[105],ans;
char ch[105][105];

void work()
{
	scanf("%d %d\n",&n,&m);
	for (int i=1; i<=n; i++)
		scanf("%s\n",ch[i]+1);
	a[0]=-1;
	for (int j=1,t; t=1,j<=m; j++)
		{
			for (int i=1; i<=n; i++)
				if (a[i]!=a[i-1])  b[i]=b[i-1]+1;
				else  if (ch[i][j]>ch[i-1][j])  b[i]=b[i-1]+1;
				else  if (ch[i][j]==ch[i-1][j])  b[i]=b[i-1];
				else  {t=0;  break;}
			if (t)  for (int i=1; i<=n; i++)  a[i]=b[i];
			else  ans++;
		}
	printf("%d",ans);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
