#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio> 
#include <cmath>
#include <map>
using namespace std;

typedef long long  LL;

struct edge{int s,t,n;}e[200010];
int n,h[100010],c[100010],f[100010];
LL ans[100010];
map <int,int> M[100010];

int dfs(int x,int fa)
{
	int S=x,T;
	M[S][c[x]]=1,ans[x]=c[x],f[x]=1;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=fa)
			{
				T=dfs(y,x);
				if (M[S].size()<M[T].size())  swap(S,T),ans[x]=ans[y],f[x]=f[y];
				for (map <int,int>::iterator j=M[T].begin(); j!=M[T].end(); j++)
					{
						int t=(*j).first;
						M[S][t]+=(*j).second;
						if (M[S][t]>f[x])  f[x]=M[S][t],ans[x]=t;
						else  if (M[S][t]==f[x])  ans[x]+=t;
					}
			}
	return S;
}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&c[i]);
	for (int i=1,x,y,t=0; i<n; i++)
		{
			scanf("%d %d",&x,&y);
			e[++t]=(edge){x,y,h[x]},h[x]=t;
			e[++t]=(edge){y,x,h[y]},h[y]=t;
		}
	dfs(1,0);
	for (int i=1; i<=n; i++)  printf("%lld ",ans[i]);
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
