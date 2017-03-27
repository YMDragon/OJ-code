#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,A[2010][2010],cho[2010];

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
			A[i][j]=getint();
	memset(cho,0,sizeof(cho));
	for (int i=n,x; x=A[1][i],i>1; i--)
		{
			for (int j=2; j<=n; j++)
				if (!cho[A[x][j]])
					{
						printf("%d %d\n",x,A[x][j]);
						break;
					}
			cho[x]=1;
		}
	printf("\n");
}

int main()
{
	int t=getint();
	while (t--)  work();
	return 0;
}
