#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define mp  make_pair
using namespace std;

typedef int arr[300010];
typedef pair<int,int>  PII;
struct edge{int s,t,n;}e[600010];
int n,q,m,tot,top,F[300010][20];
arr h,dep,dfn,sz,f,ask,tree,val,dis,Stack,ans,tmp;
PII near[300010];

bool cmp(int x,int y){return dfn[x]<dfn[y];}

void dfs(int x,int fa)
{
	F[x][0]=fa,dep[x]=dep[fa]+1,dfn[x]=++tot,sz[x]=1;
	for (int i=1; i<20; i++)  F[x][i]=F[F[x][i-1]][i-1];
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=fa)  dfs(y,x),sz[x]+=sz[y];
}

int LCA(int x,int y)
{
	if (dep[x]>dep[y])  swap(x,y);
	for (int i=19; i>=0; i--)
		if (dep[F[y][i]]>=dep[x])
			y=F[y][i];
	if (x==y)  return x;
	for (int i=19; i>=0; i--)
		if (F[x][i]!=F[y][i])
			x=F[x][i],y=F[y][i];
	return F[x][0];
}

int find(int x,int tdep)
{
	for (int i=19; i>=0; i--)
		if (dep[F[x][i]]>=tdep)
			x=F[x][i];
	return x;
}

void work()
{
	scanf("%d",&n);
	int x,y,tot=0;
	for (int i=1; i<n; i++)
	{
		scanf("%d %d",&x,&y);
		e[++tot]=(edge){x,y,h[x]},h[x]=tot;
		e[++tot]=(edge){y,x,h[y]},h[y]=tot;
	}
	dfs(1,0);
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d",&m);
		for (int i=1; i<=m; i++)
			scanf("%d",&tmp[i]),ask[i]=tmp[i],near[ask[i]]=mp(0,ask[i]),ans[ask[i]]=0,tree[i]=ask[i];
		sort(ask+1,ask+m+1,cmp);
		tot=m,top=0;
		for (int i=1; i<=m; i++)
			{
				int p=ask[i];
				if (!top)
					Stack[++top]=p,f[p]=0;
				else
					{
						int x=LCA(Stack[top],p);
						f[p]=x;
						while (dep[Stack[top]]>dep[x])
							{
								if (dep[Stack[top-1]]<=dep[x])  f[Stack[top]]=x;
								top--;
							}
						if (Stack[top]!=x)
							{
								f[x]=Stack[top];
								Stack[++top]=x,near[x]=mp(1<<30,0);
								tree[++tot]=x;
							}
						Stack[++top]=p;
					}
			}
		sort(tree+1,tree+tot+1,cmp);
		for (int i=1; i<=tot; i++)
			{
				int p=tree[i];
				val[p]=sz[p];
				if (i>1)  dis[p]=dep[p]-dep[f[p]];
			}
		for (int i=tot; i>1; i--)
			{
				int p=tree[i];
				near[f[p]]=min(near[f[p]],mp(near[p].first+dis[p],near[p].second));
			}
		for (int i=2; i<=tot; i++)
			{
				int p=tree[i];
				near[p]=min(near[p],mp(near[f[p]].first+dis[p],near[f[p]].second));
			}
		for (int i=1; i<=tot; i++)
			{
				int p=tree[i],sum=sz[find(p,dep[f[p]]+1)]-sz[p];
				if (!f[p])
					ans[near[p].second]+=sum;
				else
					{
						val[f[p]]-=sum+sz[p];
						if (near[p].second==near[f[p]].second)
							ans[near[p].second]+=sum;
						else
							{								
								int len=near[p].first+near[f[p]].first+dis[p],mid=dep[p]-(len/2-near[p].first),x;
								if ((len%2==0)&&(near[f[p]].second<near[p].second))  mid++;
								x=find(p,mid);
								ans[near[p].second]+=sz[x]-sz[p];
								ans[near[f[p]].second]+=sum-sz[x]+sz[p];
							}
					}
			}
		for (int i=1; i<=tot; i++)
			ans[near[tree[i]].second]+=val[tree[i]];
		for (int i=1; i<=m; i++)
			printf("%d ",ans[tmp[i]]);
		puts("");
	}
}

int main()
{
	freopen("3572.in","r",stdin);
	freopen("3572.out","w",stdout);
	work();
	return 0;
}
