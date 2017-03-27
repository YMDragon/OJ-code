#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int c[5][5]={{0,-1,1,1,-1},{1,0,-1,1,-1},{-1,1,0,-1,1},{-1,-1,1,0,1},{1,1,-1,-1,0}};
int n,na,nb,a[205],b[205],sa,sb;

void work()
{
	scanf("%d %d %d",&n,&na,&nb);
	for (int i=1; i<=na; i++)  scanf("%d",&a[i]);
	for (int i=1; i<=nb; i++)  scanf("%d",&b[i]);
	for (int i=1,j=1,k=1; i<=n; i++,j++,k++)
		{
			if (j>na)  j=1;
			if (k>nb)  k=1;
			if (c[a[j]][b[k]]==1)  sa++;
			if (c[a[j]][b[k]]==-1)  sb++;
		}
	printf("%d %d",sa,sb);
}

int main()
{
	freopen("15.in","r",stdin);
	freopen("15.out","w",stdout);
	work();
	return 0;
}
