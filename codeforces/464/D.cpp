#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int m=700;
int n,k;
double f[2][710];

void work()
{
	scanf("%d %d",&n,&k);
	int cur=0;
	for (int i=1; cur^=1,i<=n; i++)
		for (int j=1; j<=m; j++)
			f[cur][j]=1.0*(k-1)/k*f[cur^1][j]+1.0/k*(1.0*j/(j+1)*(f[cur^1][j]+1.0*(j+1)/2)+1.0/(j+1)*(f[cur^1][j+1]+j));
	printf("%.10lf",f[cur^1][1]*k);
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
