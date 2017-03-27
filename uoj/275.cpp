#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const int mo=int(1e9+7);
int k,f[65][2][2][2][2],ans;
LL n,m;

void upd(int &x,int y){if ((x+=y)>=mo)  x-=mo;}

int get(LL x,int Dig)
{
	for (; Dig--; )  x/=k;
	return x%k;
}

void work()
{
	scanf("%lld %lld",&n,&m);
	memset(f,0,sizeof(f));
	f[64][1][1][1][1]=1;
	for (int Dig=63; Dig>=0; Dig--)
		for (int a=0; a<=1; a++)
			for (int b=0; b<=1; b++)
				for (int c=0; c<=1; c++)
					for (int d=0; d<=1; d++)
						if (f[Dig+1][a][b][c][d])
							{
								int x=get(n,Dig),y=get(m,Dig);
								for (int i=0; i<k; i++)
									for (int j=0; j<k; j++)
										{
											if ((a)&&(i>x))  continue;
											if ((b)&&(j>y))  continue;
											if ((c)&&(j>i))  continue;
											int na,nb,nc,nd;
											if (a)  na=(i==x);  else  na=0;
											if (b)  nb=(j==y);  else  nb=0;
											if (c)  nc=(i==j);  else  nc=0;
											if (d)  nd=(j<=i);  else  nd=0;
											upd(f[Dig][na][nb][nc][nd],f[Dig+1][a][b][c][d]);
										}
							}
	ans=0;
	for (int a=0; a<=1; a++)
		for (int b=0; b<=1; b++)
			for (int c=0; c<=1; c++)
				upd(ans,f[0][a][b][c][0]);
	printf("%d\n",ans);
}

int main()
{
	freopen("275.in","r",stdin);
	freopen("275.out","w",stdout);
	int t;
	scanf("%d %d",&t,&k);
	while (t--)  work();
	return 0;
}
