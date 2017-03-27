#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

const int oo=int(1e9);
struct edge{int s,t,n;}e[200010];
struct node{int x,y,id;}a[50010],b[50010];
struct flowedge{int s,t,c,n;}fe[6000010];
int n,tot,h[50010],dis[50010],fa[50010],ndis[50010],nfa[50010],ans;
int S,T,inout[50010],can[50010][2],vis[100010],Dis[100010],fh[100010],flow;
queue <int> Q;

bool cmpx(node x,node y){return (x.x<y.x)||((x.x==y.x)&&(x.y<y.y));}
bool cmpy(node x,node y){return (x.y<y.y)||((x.y==y.y)&&(x.x<y.x));}
bool cmpz(node x,node y){return (x.x-x.y<y.x-y.y)||((x.x-x.y==y.x-y.y)&&(x.y<y.y));}
bool cmpr(node x,node y){return (x.x+x.y<y.x+y.y)||((x.x+x.y==y.x+y.y)&&(x.y<y.y));}
void addedge(int s,int t){e[++tot]=(edge){s,t,h[s]},h[s]=tot;}

void addedge(int s,int t,int c)
{
	fe[++tot]=(flowedge){s,t,c,fh[s]},fh[s]=tot;
	fe[++tot]=(flowedge){t,s,0,fh[t]},fh[t]=tot;
}

void upd(int x,int k,int id,int tag)
{
	if (tag)
		{if (k>ndis[x])  ndis[x]=k,nfa[x]=id;}
	else
		{if (k>dis[x])  dis[x]=k,fa[x]=id;}
}

void print(int x)
{
	if (!x)  return;
	if (nfa[x]!=x)
		{
			print(fa[nfa[x]]);
			if (b[x].id>b[nfa[x]].id)
				{
					for (int j=b[nfa[x]].id; a[j].y==b[x].y; j--)
						printf("%d ",a[j].id);
					for (int j=b[nfa[x]].id+1; j<b[x].id; j++)
						printf("%d ",a[j].id);
				}else
				{
					for (int j=b[nfa[x]].id; a[j].y==b[x].y; j++)
						printf("%d ",a[j].id);
					for (int j=b[nfa[x]].id-1; j>b[x].id; j--)
						printf("%d ",a[j].id);
				}
		}else
		print(fa[x]);
	printf("%d ",x);
}

bool BFS()
{
	int x,y,i;
	while (!Q.empty())  Q.pop();
	memset(Dis,-1,sizeof(Dis));
	Q.push(T),Dis[T]=1;
	while (!Q.empty())
		for (i=fh[x=Q.front()],Q.pop(); y=fe[i].t,i; i=fe[i].n)
			if ((Dis[y]==-1)&&(fe[i^1].c))
				{
					Dis[y]=Dis[x]+1,Q.push(y);
					if (y==S)  return 1;
				}
	return 0;
}

int DFS(int x,int a)
{
	if ((x==T)||(!a))  return a;
	int flow=0;
	for (int i=fh[x],y,t; y=fe[i].t,i; i=fe[i].n)
		if ((Dis[y]+1==Dis[x])&&(fe[i].c))
			{
				t=DFS(y,min(a,fe[i].c));
				flow+=t,a-=a,fe[i].c-=t,fe[i^1].c+=t;
				if (!a)  return flow;
			}
	Dis[x]=oo;
	return flow;
}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d %d",&a[i].x,&a[i].y),a[i].id=i;
	sort(a,a+n+1,cmpx);
	for (int i=0; i<n; i++)
		if (a[i].x==a[i+1].x)
			addedge(a[i].id,a[i+1].id);
	sort(a,a+n+1,cmpz);
	for (int i=0; i<n; i++)
		if (a[i].x-a[i].y==a[i+1].x-a[i+1].y)
			addedge(a[i].id,a[i+1].id);
	sort(a,a+n+1,cmpr);
	for (int i=0; i<n; i++)
		if (a[i].x+a[i].y==a[i+1].x+a[i+1].y)
			addedge(a[i].id,a[i+1].id);
	sort(a,a+n+1,cmpy);
	for (int i=1; i<=n; i++)  dis[i]=ndis[i]=-1;
	for (int i=0; i<=n; i++)
		{
			int l=i,r;
			while (a[i+1].y==a[i].y)  i++;
			r=i;
			for (int j=l,x=-1,y=-1; j<=r; j++)
				{
					if (x!=-1)  upd(a[j].id,x+j-l,y,1);
					if (dis[a[j].id]>x)  x=dis[a[j].id],y=a[j].id;
				}
			for (int j=r,x=-1,y=-1; j>=l; j--)
				{
					if (x!=-1)  upd(a[j].id,x+r-j,y,1);
					if (dis[a[j].id]>x)  x=dis[a[j].id],y=a[j].id;
				}
			for (int j=l; j<=r; j++)
				upd(a[j].id,dis[a[j].id],a[j].id,1);
			for (int j=l; j<=r; j++)
				if (ndis[a[j].id]!=-1)
					for (int k=h[a[j].id]; k; k=e[k].n)
						upd(e[k].t,ndis[a[j].id]+1,a[j].id,0);
		}
	ans=0;
	for (int i=1; i<=n; i++)  if (ndis[ans]<ndis[a[i].id])  ans=a[i].id;
	printf("%d\n",ndis[ans]);
	for (int i=1; i<=n; i++)  b[a[i].id]=(node){a[i].x,a[i].y,i};
	print(ans);
	tot=1;
	for (int i=n; i>=0; i--)
		{
			int l,r=i;
			while ((i>0)&&(a[i-1].y==a[i].y))  i--;
			l=i;
			for (int j=l; j<=r; j++)
				{
					if (ndis[a[j].id]==ndis[ans])  can[a[j].id][1]=1;
					for (int k=h[a[j].id]; k; k=e[k].n)
						if ((ndis[a[j].id]+1==dis[e[k].t])&&(can[e[k].t][0]))
							can[a[j].id][1]|=1,addedge(a[j].id,e[k].t+n+1,oo),inout[a[j].id]--,inout[e[k].t]++;
				}
			for (int j=l; j<=r; j++)
				if (can[a[j].id][1])
					{
						for (int k=l; k<j; k++)
							if (dis[a[k].id]+(j-l)==ndis[a[j].id])
								can[a[k].id][0]=1;
						for (int k=r; k>j; k--)
							if (dis[a[k].id]+(r-j)==ndis[a[j].id])
								can[a[k].id][0]=1;
						if (ndis[a[j].id]==dis[a[j].id])  can[a[j].id][0]=1;
					}
		}
	S=2*n+3,T=2*n+4;
	for (int i=0; i<=n; i++)
		{
			if (inout[i]>0)  addedge(S,i,inout[i]),flow+=inout[i];
			else  if (inout[i]<0)  addedge(i+n+1,T,-inout[i]);
			addedge(i+n+1,i,oo);
		}
	tot=0;
	while (BFS())  flow-=DFS(S,oo);
	printf("\n%d",flow);
}

int main()
{
	freopen("4200.in","r",stdin);
	freopen("4200.out","w",stdout);
	work();
	return 0;
}
