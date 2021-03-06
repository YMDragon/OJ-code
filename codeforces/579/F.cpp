#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int n,m;
LL f[100010][8];
char ch[100010];

void work()
{
	scanf("%d %d\n",&n,&m);
	scanf("%s",ch+1);
	for (int i=1; i<=n; i++)  ch[i]-='a'-1;
	for (int i=1; i<=m; i++)
		{
			int x=1;
			if (i==ch[1])  x|=2;
			if ((i==ch[2])||(i==ch[1]))  x|=4;
			f[1][x]++;
		}
	for (int i=2; i<=n; i++)
		for (int j=0; j<8; j++)
			{
				int g[4]={i-3+((j&1)>0),i-2+((j&2)>0),i-2+((j&4)>0),0};
				for (int k=1; k<=m; k++)
					{
						int h[4]={0,0,0,0};
						for (int l=1; l<=3; l++)
							if (ch[i+l-2]==k)  h[l]=g[l-1]+1;
							else  h[l]=max(h[l-1],g[l]);
						if ((h[1]>=i-2)&&(h[2]>=i-1)&&(h[3]>=i-1))
							f[i][(h[1]==i-1)|((h[2]==i)<<1)|((h[3]==i)<<2)]+=f[i-1][j];
					}
			}
	cout<<f[n][0]+f[n][1]+f[n][2]+f[n][3];
}

int main()
{
  freopen("F.in","r",stdin);
  freopen("F.out","w",stdout);
  work();
  return 0;
}
