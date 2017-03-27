#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int N=505;
struct edge{int s,t,n;}e[N*N];
int n,m,ans,cnt,MK,h[N],mat[N],col[N],nex[N],ufs[N],fa[N],vis[N],mark[N];

struct queue{
	int dl[N],l,r;

	void clear(){l=1,r=0;}
	bool empty(){return l>r;}
	int front(){return dl[l];}
	void pop(){l++;}
	void push(int x){dl[++r]=x;}
}Q;

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
			if (col[y])  col[y]=0,Q.push(y);
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
	for (i=1; i<=n; i++)  fa[i]=nex[i]=0,ufs[i]=i;
	Q.clear(),Q.push(s),vis[s]=++cnt;
	while (!Q.empty())
		for (i=h[x=Q.front()],Q.pop(); y=e[i].t,i; i=e[i].n)
			if (vis[y]!=cnt)
				if (!mat[y])
					{augment(x),mat[x]=y,mat[y]=x,ans++;  return;}
				else
					fa[y]=nex[y]=x,vis[y]=vis[mat[y]]=cnt,col[y]=1,col[mat[y]]=0,Q.push(mat[y]);
			else  if ((col[y]==0)&&(find(y)!=find(x)))
				{
					int lca=LCA(ufs[x],ufs[y]);
					merge(x,y,lca),merge(y,x,lca);
				}
}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1,u,v,tot=0; i<=m; i++)
		{
			scanf("%d %d",&u,&v);
			e[++tot]=(edge){u,v,h[u]},h[u]=tot;
			e[++tot]=(edge){v,u,h[v]},h[v]=tot;
		}
	for (int i=1; i<=n; i++)
		if (!mat[i])  match(i);
	printf("%d\n",ans);
	for (int i=1; i<=n; i++)
		printf("%d ",mat[i]);
}

int main()
{
	freopen("79.in","r",stdin);
	freopen("79.out","w",stdout);
	work();
	return 0;
}
