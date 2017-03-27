#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int sg[100010],t,f,vis[100010],inpu[110][110],maxs;

void getsg()
{
	int x;
	for (int i=1; i<f; i++)  sg[i]=0;
	for (int i=f; i<=maxs; i++)
		{
			for (int j=2; j<=i; j=i/(i/j)+1)
				for (int k=j; k<=j+1&&k<=i; k++)
					{
						x=(((k-i%k)%2)*sg[i/k])^(((i%k)%2)*sg[i/k+1]);
						vis[x]=i;
					}
			for (int j=0; ; j++)  if (vis[j]!=i)  {sg[i]=j;  break;}
		}
}

void work()
{
	scanf("%d %d",&t,&f);
	f=max(2,f);
	for (int i=1; i<=t; i++)
		{
			scanf("%d",&inpu[i][0]);
			for (int j=1; j<=inpu[i][0]; j++)
				scanf("%d",&inpu[i][j]),maxs=max(maxs,inpu[i][j]);
		}
	getsg();
	for (int i=1; i<=t; i++)
		{
			int ans=0;
			for (int j=1; j<=inpu[i][0]; j++)
				ans^=sg[inpu[i][j]];
			if (i==t)
				if (ans)  printf("1");  else  printf("0");
			else
				if (ans)  printf("1 ");  else  printf("0 ");
		}
}

int main()
{
	freopen("3576.in","r",stdin);
	freopen("3576.out","w",stdout);
	work();
	return 0;
} 
