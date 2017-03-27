#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int m=100,ans=0,f[101][101];

int gcd(int a,int b){return b?gcd(b,a%b):a;}

bool check(int x)
{
	return (x==int(sqrt(x))*int(sqrt(x)));
}

void work()
{
	for (int i=1; i<=m; i++)
		for (int j=1; j<=m; j++)
			f[i][j]=((i+1)*(j+1)-gcd(i,j)-1)/2;
	for (int a=1; a<=m; a++)
		for (int b=1; b<=m; b++)
			for (int c=1; c<=m; c++)
				for (int d=1; d<=m; d++)
					if (check(f[a][b]+f[b][c]+f[c][d]+f[d][a]-a-b-c-d+1))
						ans++;
	printf("%d\n",ans);
}

int main()
{
	work();
	return 0;
}
