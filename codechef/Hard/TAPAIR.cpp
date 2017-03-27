#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

typedef long long  LL;
struct edge{int s,t,ty,n;  LL x;}e[600010];
int n,m,h[100010],vis[100010],dep[100010],fa[100010],fae[100010];
LL ans;
map <LL,int> M;

void dfs(int x,int f,int fe)
{
	fa[x]=f,fae[x]=fe,vis[x]=1,dep[x]=dep[f]+1;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=f)
			{
				if (!vis[y])  e[i].ty=1,dfs(y,x,i);
				else  if (dep[y]>dep[x])  e[i].ty=2;
			}
}

void dfs(int x)
{
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (e[i].ty==1)
			dfs(y),e[fae[x]].x^=e[fae[y]].x;
}

void work()
{
	scanf("%d %d",&n,&m);
	srand(time(NULL));
	for (int i=1,s,t,tot=0; i<=m; i++)
		{
			scanf("%d %d",&s,&t);
			e[++tot]=(edge){s,t,0,h[s],0},h[s]=tot;
			e[++tot]=(edge){t,s,0,h[t],0},h[t]=tot;
		}
	dfs(1,0,0);
	for (int i=1; i<=2*m; i++)
		if (e[i].ty==2)
			{
				LL x=((1LL*rand())<<31)|rand();
				e[i].x=x,e[fae[e[i].s]].x^=x,e[fae[e[i].t]].x^=x;
				M[x]++;
			}
	dfs(1);
	for (int i=1,t=1; i<=2*m; i++)
		if ((e[i].ty)&&(e[i].x==0))  ans+=m-t,t++;
	for (int i=1; i<=2*m; i++)
		if ((e[i].ty==1)&&(M[e[i].x]))  ans++;
	M.clear();
	for (int i=1; i<=2*m; i++)
		if ((e[i].ty==1)&&(e[i].x))  M[e[i].x]++;
	for (map <LL,int> :: iterator x=M.begin();  x!=M.end();  x++)
		ans+=1LL*(*x).second*((*x).second-1)/2;
	cout<<ans;
}

int main()
{
	freopen("TAPAIR.in","r",stdin);
	freopen("TAPAIR.out","w",stdout);
	work();
	return 0;
}
