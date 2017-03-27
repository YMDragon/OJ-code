#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,a[2010][2010],b[2010];

int getint()
{
	int w=0;  char ch=getchar();
	while ((ch<'0')||(ch>'9'))  ch=getchar();
	while (('0'<=ch)&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return w;
}

void work()
{
	n=getint();
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			a[i][j]=getint();
	memset(b,0,sizeof(b));
	for (int i=n,x; x=a[1][i],i>1; i--)
		{
			for (int j=2; j<=n; j++)
				if (!b[a[x][j]])
					{
						printf("%d %d\n",x,a[x][j]);
						break;
					}
			b[x]=1;
		}
	printf("\n");
}

int main()
{
	freopen("K.in","r",stdin);
	freopen("K.out","w",stdout);
	int t=getint();
	while (t--)  work();
	return 0;
}
