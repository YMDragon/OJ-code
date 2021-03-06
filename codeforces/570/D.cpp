#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

struct edge{int s,t,n;}e[500010];
int n,m,tot,fa[500010],h[500010],mark[500010][2];
char ch[500010];
vector <int> V[500010][26];

void dfs(int x,int dep)
{
	mark[x][0]=++tot,V[dep][ch[x]-'a'].push_back(tot);
	for (int i=h[x]; i; i=e[i].n)  dfs(e[i].t,dep+1);
	mark[x][1]=tot;
}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=2; i<=n; i++)
		scanf("%d",&fa[i]),e[i]=(edge){fa[i],i,h[fa[i]]},h[fa[i]]=i;
	scanf("\n%s",ch+1);
	dfs(1,1);
	for (int i=1,v,h,tag; i<=m; i++)
		{
			scanf("%d %d",&v,&h),tag=0;
			for (int i=0; i<26; i++)
				if ((upper_bound(V[h][i].begin(),V[h][i].end(),mark[v][1])-lower_bound(V[h][i].begin(),V[h][i].end(),mark[v][0]))&1)
					tag++;
			if (tag<=1)  printf("Yes\n");  else  printf("No\n");
		}
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
