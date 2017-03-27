#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=int(1e9+7);
int n,k,f[1010][1010][2][2][2],ans;

void upd(int &x,int y)
{
	x+=y;
	if (x>mo)  x-=mo;
}

int c(int x,int y){return 1LL*x*y%mo;}

void work()
{
	scanf("%d %d",&n,&k);
	f[1][0][1][0][0]=1;
	for (int i=1; i<n; i++)
		for (int j=0; j<=i; j++)
			for (int x=0; x<=1; x++)
				for (int y=0; y<=1; y++)
					for (int z=0; z<=1; z++)
						if ((x+z!=2)&&(x+y!=2)&&(f[i][j][x][y][z]))
							{
								int t=f[i][j][x][y][z];
								upd(f[i+1][j][1][0][0],t);

								if (x)  upd(f[i+1][j+2][0][1][1],t);
								else  if (y)  upd(f[i+1][j][0][0][1],t);
								else  upd(f[i+1][j+1][0][0][1],t);

								if (x)
									{
										upd(f[i+1][j][0][0][0],c(t,i-j-1));
										if (j)  upd(f[i+1][j-1][0][0][0],c(t,j));
									}else
									if (z)
										{
											upd(f[i+1][j][0][1][0],t);
											upd(f[i+1][j][0][0][0],c(t,i-j-1+y));
											if (j)  upd(f[i+1][j-1][0][0][0],c(t,j-1-y));
										}else
										{
											upd(f[i+1][j+1][0][1][0],t);
											upd(f[i+1][j][0][0][0],c(t,i-j-2+y));
											if (j)  upd(f[i+1][j-1][0][0][0],c(t,j-y));
										}
							}
	for (int x=0; x<=1; x++)
		for (int y=0; y<=1; y++)
			for (int z=0; z<=1; z++)
				if ((x+z!=2)&&(x+y!=2))
					upd(ans,f[n][k][x][y][z]);
	printf("%d",ans);
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
