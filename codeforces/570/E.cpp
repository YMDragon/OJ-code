#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=1e9+7;
int n,m,f[2][505][505],ans;
char ch[505][505];

void work()
{
	scanf("%d %d\n",&n,&m);
	for (int i=1; i<=n; i++)  scanf("%s\n",ch[i]+1);
	if (ch[1][1]!=ch[n][m])  {printf("0");  return;}
	f[1][1][n]=1;
	int now=1,nex=0;
	for (int i=1; i<=n&&i<=(n+m)/2; i++)
		{
			for (int j=1; j<=m; j++)
				for (int k=1; k<=n; k++)
					f[nex][j][k]=0;
			for (int j=1; j<=m; j++)
				for (int k=1; k<=n; k++)
					if (f[now][j][k])
						{
							int l=n+m+2-i-j-k;
							if ((1<=l)&&(l<=m))
								{
									if (ch[i][j+1]==ch[k][l-1])  (f[now][j+1][k]+=f[now][j][k])%=mo;
									if (ch[i][j+1]==ch[k-1][l])  (f[now][j+1][k-1]+=f[now][j][k])%=mo;
									if (ch[i+1][j]==ch[k][l-1])  (f[nex][j][k]+=f[now][j][k])%=mo;
									if (ch[i+1][j]==ch[k-1][l])  (f[nex][j][k-1]+=f[now][j][k])%=mo;
								}
						}
			if ((n+m)&1)  (ans+=(f[now][(n+m)/2-i+1][i]+f[now][(n+m)/2-i+1][i+1])%mo)%=mo;
			else  (ans+=f[now][(n+m)/2-i+1][i])%=mo;			
			swap(now,nex);
		}
	printf("%d",ans);
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
