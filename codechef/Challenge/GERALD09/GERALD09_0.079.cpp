#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,k;

void work()
{
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=m; j++)
				printf("A");
			printf("\n");
		}
}

int main()
{
	freopen("GREALD09.in","r",stdin);
	freopen("GERALD09.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
