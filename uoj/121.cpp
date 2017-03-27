#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,d,k,a[100010][105];

void solve(int i)
{
	for (int j=1,s; j<=n; j++)
		if (i!=j)
			{
				s=0;
				for (int l=1; l<=d; l++)
					s+=a[i][l]*a[j][l];
				if (s%k==0)
					{
						if (i<j)  printf("%d %d\n",i,j);  else  printf("%d %d\n",j,i);
						return;
					}
			}
}

namespace solve2{
	int b[105];
	
	void work()
	{
		for (int i=1,s; i<=n; i++)
			{
				s=0;
				for (int j=1; j<=d; j++)  s+=a[i][j]*b[j];
				if (s%2!=(i-1)%2)  {solve(i);  return;}
				for (int j=1; j<=d; j++)  b[j]=(b[j]+a[i][j])%k;
			}
		printf("-1 -1");
	}
}

namespace solve3{
	int b[105][105];
	
	void work()
	{
		for (int i=1,s; i<=n; i++)
			{
				s=0;
				for (int x=1; x<=d; x++)
					for (int y=1; y<=d; y++)
						s+=a[i][x]*a[i][y]*b[x][y];
				if (s%3!=(i-1)%3)  {solve(i);  return;}
				for (int x=1; x<=d; x++)
					for (int y=1; y<=d; y++)
						b[x][y]=(b[x][y]+a[i][x]*a[i][y])%k;
			}
		printf("-1 -1");
	}
}

void work()
{
	scanf("%d %d %d",&n,&d,&k);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=d; j++)
			scanf("%d",&a[i][j]),a[i][j]%=k;
	if (k==2)  solve2::work();  else  solve3::work();
}

int main()
{
	freopen("121.in","r",stdin);
	freopen("121.out","w",stdout);
	work();
	return 0;
}
