#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int mo=1e9+7;
struct edge{int s,t,n;}e[105];
int n,m,tot,h[105],C[105][105],f[105][105],g[105],bcj[105],s[105],rd[105],ans;

int find(int x){return (bcj[x]==x)?x:bcj[x]=find(bcj[x]);}

void dfs(int x)
{
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		{
			dfs(y);
			if (!s[x])
				for (int j=1; j<=s[y]; j++)  f[x][j]=f[y][j];
			else
				{
					for (int j=1; j<=s[x]+s[y]; j++)  g[j]=0;
					for (int j=1; j<=s[x]; j++)
						for (int k=1; k<=s[y]; k++)
							for (int l=max(j,k); l<=j+k; l++)
								(g[l]+=1LL*C[l][j]*C[j][l-k]%mo*f[x][j]%mo*f[y][k]%mo)%=mo;
					for (int j=1; j<=s[x]+s[y]; j++)  f[x][j]=g[j];
				}
			s[x]+=s[y];
		}
	for (int i=s[x]; i; i--)  f[x][i+1]=f[x][i];
	s[x]++;
	if ((s[x]==1)&&(x))  f[x][1]=1;  else  f[x][1]=0;
}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=n; i++)  bcj[i]=i;
	for (int i=1; i<=m; i++)
		{
			int x,y;  char ch;
			scanf("%d %c %d\n",&x,&ch,&y);
			if (ch=='=')  bcj[find(y)]=find(x);
			else  e[++tot]=(edge){x,y,0};
		}
	for (int i=1; i<=tot; i++)
		{
			e[i].s=find(e[i].s),e[i].t=find(e[i].t);
			e[i].n=h[e[i].s],h[e[i].s]=i,rd[e[i].t]++;
		}
	for (int i=1; i<=n; i++)
		if ((bcj[i]==i)&&(rd[i]==0))
			e[++tot]=(edge){0,i,h[0]},h[0]=tot;
	for (int i=0; i<=n; i++)
		{
			C[i][0]=1;
			for (int j=1; j<=i; j++)
				C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
		}
	dfs(0);
	for (int i=1; i<=n+1; i++)
		(ans+=f[0][i])%=mo;
	printf("%d",ans);
}

int main()
{
	freopen("4013.in","r",stdin);
	freopen("4013.out","w",stdout);
	work();
	return 0;
}
