#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int N=605;
struct edge{int s,t,n;}e[N*N];
int n,m,E,tot,ans,cnt,MK,h[N],mat[N],col[N],nex[N],ufs[N],fa[N],vis[N],mark[N];
int L,R,Q[N];

void addedge(int u,int v)
{
	e[++tot]=(edge){u,v,h[u]},h[u]=tot;
	e[++tot]=(edge){v,u,h[v]},h[v]=tot;
}

int find(int x){return ufs[x]==x?x:ufs[x]=find(ufs[x]);}

int LCA(int x,int y)
{
	MK++;
	for (;;)
		{
			if (x)
				{
					if (mark[x]==MK)  return x;
					mark[x]=MK;
					x=find(fa[mat[x]]);
				}
			swap(x,y);
		}
}

void merge(int x,int y,int lca)
{
	while (find(x)!=lca)
		{
			nex[x]=y,y=mat[x];
			if (col[y])  col[y]=0,Q[++R]=y;
			if (ufs[x]==x)  ufs[x]=lca;
			if (ufs[y]==y)  ufs[y]=lca;
			x=nex[y];
		}
}

void augment(int x)
{
	int y=mat[x];  mat[x]=0,x=nex[y];
	while (x)
		{
			mat[y]=x,swap(mat[x],y);
			x=nex[y];
		}
}

void match(int s)
{
	int x,y,i;
	for (i=1; i<=n+3*m; i++)  fa[i]=nex[i]=0,ufs[i]=i;
	L=1,R=0,Q[++R]=s,vis[s]=++cnt;
	while (L<=R)
		for (i=h[x=Q[L++]]; y=e[i].t,i; i=e[i].n)
			if (vis[y]!=cnt)
				if (!mat[y])
					{augment(x),mat[x]=y,mat[y]=x,ans++;  return;}
				else
					fa[y]=nex[y]=x,vis[y]=vis[mat[y]]=cnt,col[y]=1,col[mat[y]]=0,Q[++R]=mat[y];
			else  if ((col[y]==0)&&(find(y)!=find(x)))
				{
					int lca=LCA(ufs[x],ufs[y]);
					merge(x,y,lca),merge(y,x,lca);
				}
}

void work()
{
	memset(h,0,sizeof(h)),memset(mat,0,sizeof(mat)),memset(col,0,sizeof(col));
	scanf("%d %d %d",&n,&m,&E),tot=1;
	for (int i=1,u,v; i<=E; i++)
		{
			scanf("%d %d",&u,&v);
			addedge(u+3*m,v),addedge(u+3*m,v+m),addedge(u+3*m,v+2*m);
		}
	for (int i=1; i<=m; i++)
		addedge(i,i+m),addedge(i+m,i+2*m),addedge(i+2*m,i);
	ans=-n;
	for (int i=n+3*m; i; i--)  if (!mat[i])  match(i);
	printf("%d\n",ans);
	for (int i=1; i<=n; i++)  printf("%d ",(mat[i+3*m]-1)%m+1);
	puts("");
}

int main()
{
  freopen("171.in","r",stdin);
  freopen("171.out","w",stdout);
  int t;;
  scanf("%d",&t);
  while (t--)  work();
  return 0;
}
