#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=int(1e9+7);
struct edge{int s,t,d,n;}e[200010];
int n,q,h[100010],f[100010][6],g[100010][20],gg[100010][20],dp[100010];

int sqr_mod(int x){return 1LL*x*x%mo;}

void dfs(int x,int fa)
{
	f[x][3]=1;
	for (int i=h[x],y,d; y=e[i].t,d=e[i].d,i; i=e[i].n)
		if (y!=fa)
			{
				dfs(y,x);
				f[x][1]=(f[x][1]+f[y][1]+2LL*f[y][2]*d+1LL*sqr_mod(d)*f[y][3])%mo;
				f[x][2]=(f[x][2]+f[y][2]+1LL*d*f[y][3])%mo;
				f[x][3]+=f[y][3];
			}
}

void dfs(int x,int fa,int d)
{
	if (fa)
		{
			f[x][4]=((1LL*(n-4*f[x][3])*sqr_mod(d)+(2LL*f[fa][5]+2LL*f[fa][2]-4LL*f[x][2])*d+f[fa][4]+f[fa][1]-f[x][1])%mo+mo)%mo;
			f[x][5]=((1LL*(n-2*f[x][3])*d+f[fa][5]+f[fa][2]-f[x][2])%mo+mo)%mo;
		}
	g[x][0]=fa,gg[x][0]=d,dp[x]=dp[fa]+1;
	for (int i=h[x]; i; i=e[i].n)  if (e[i].t!=fa)  dfs(e[i].t,x,e[i].d);
}

void LCA(int x,int y,int &t,int &d)
{
	if (dp[x]>dp[y])  swap(x,y);
	for (int i=19; i>=0; i--)
		if (dp[x]<=dp[g[y][i]])
			d=(d+gg[y][i])%mo,y=g[y][i];
	if (x==y)  return void(t=x);
	for (int i=19; i>=0; i--)
		if (g[x][i]!=g[y][i])
			d=((d+gg[x][i])%mo+gg[y][i])%mo,x=g[x][i],y=g[y][i];
	d=((d+gg[x][0])%mo+gg[y][0])%mo,t=g[x][0];
}

void work()
{
	scanf("%d",&n);
	for (int i=1,s,t,d,tot=0; i<n; i++)
		{
			scanf("%d %d %d",&s,&t,&d);
			e[++tot]=(edge){s,t,d,h[s]},h[s]=tot;
			e[++tot]=(edge){t,s,d,h[t]},h[t]=tot;
		}
	dfs(1,0),dfs(1,0,0);
	for (int i=1; i<=n; i++)  f[i][0]=(f[i][1]+f[i][4])%mo;
	for (int j=1; j<20; j++)
		for (int i=1; i<=n; i++)
			g[i][j]=g[g[i][j-1]][j-1],gg[i][j]=(gg[i][j-1]+gg[g[i][j-1]][j-1])%mo;
	scanf("%d",&q);
	for (int i=1,x,y,t,d,ans; i<=q; i++)
		{
			scanf("%d %d",&x,&y),d=0;
			LCA(x,y,t,d);
			if (t==y)
				ans=(((f[x][1]+f[x][4]-f[y][4]-2LL*d*f[y][5]-1LL*(n-f[y][3])*sqr_mod(d))%mo*2LL-f[x][0])%mo+mo)%mo;
			else
				ans=(((f[y][1]+2LL*d*f[y][2]+1LL*f[y][3]*sqr_mod(d))%mo*2LL-f[x][0])%mo+mo)%mo;
			printf("%d\n",ans);
		}
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
