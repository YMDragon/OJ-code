#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

const int oo=1<<30;
struct query{int x1,y1,x2,y2,id,ans;}Q[100010];
int n,m,q,N,t[1<<16];

struct Array{
	int memory[20010];
	int* operator [] (int x){return &memory[(x-1)*m];}
}r,c,dis,vis;

bool cmpid(query x,query y){return x.id<y.id;}
void upd(int &x,int y){x=(x<y)?x:y;}

void build(){for (int i=1; i<2*N; i++)  t[i]=oo;}

int getmin()
{
	if (t[1]==oo)  return -1;
	int x=1;
	for (; x<N; )  if (t[x]==t[x<<1])  x<<=1;  else  x<<=1,x|=1;
	return x-N+1;
}

void modify(int x,int k)
{
	x+=N-1,t[x]=k;
	for (; x!=1; x>>=1)  t[x>>1]=(t[x]<t[x^1])?t[x]:t[x^1];
}

void dij(int xl,int xr,int yl,int yr,int sx,int sy)
{
	for (int i=xl; i<=xr; i++)
		for (int j=yl; j<=yr; j++)
			dis[i][j]=oo,vis[i][j]=0;
	dis[sx][sy]=0,modify((sx-1)*m+sy,0);
	while (1)
		{
			int t=getmin(),x=(t-1)/m+1,y=(t-1)%m+1;
			if (t==-1)  break;
			modify(t,oo);
			if ((y<yr)&&(dis[x][y]+r[x][y]<dis[x][y+1]))
				dis[x][y+1]=dis[x][y]+r[x][y],modify(t+1,dis[x][y+1]);
			if ((x<xr)&&(dis[x][y]+c[x][y]<dis[x+1][y]))
				dis[x+1][y]=dis[x][y]+c[x][y],modify(t+m,dis[x+1][y]);
			if ((y>yl)&&(dis[x][y]+r[x][y-1]<dis[x][y-1]))
				dis[x][y-1]=dis[x][y]+r[x][y-1],modify(t-1,dis[x][y-1]);
			if ((x>xl)&&(dis[x][y]+c[x-1][y]<dis[x-1][y]))
				dis[x-1][y]=dis[x][y]+c[x-1][y],modify(t-m,dis[x-1][y]);
		}
}

void solve(int xl,int xr,int yl,int yr,int ql,int qr)
{
	if (xr-xl>yr-yl)
		{
			int mid=(xl+xr)>>1;
			for (int i=yl; i<=yr; i++)
				{
					dij(xl,xr,yl,yr,mid,i);
					for (int j=ql; j<=qr; j++)
						upd(Q[j].ans,dis[Q[j].x1][Q[j].y1]+dis[Q[j].x2][Q[j].y2]);
				}
			if (xl<mid)
				{
					int k=ql-1;
					for (int i=ql; i<=qr; i++)
						if ((Q[i].x1<mid)&&(Q[i].x2<mid))
							swap(Q[i],Q[++k]);
					if (ql<=k)  solve(xl,mid-1,yl,yr,ql,k);
				}
			if (xr>mid)
				{
					int k=qr+1;
					for (int i=qr; i>=ql; i--)
						if ((Q[i].x1>mid)&&(Q[i].x2>mid))
							swap(Q[i],Q[--k]);
					if (k<=qr)  solve(mid+1,xr,yl,yr,k,qr);
				}
		}else
		{
			int mid=(yl+yr)>>1;
			for (int i=xl; i<=xr; i++)
				{
					dij(xl,xr,yl,yr,i,mid);
					for (int j=ql; j<=qr; j++)
						upd(Q[j].ans,dis[Q[j].x1][Q[j].y1]+dis[Q[j].x2][Q[j].y2]);
				}
			if (yl<mid)
				{
					int k=ql-1;
					for (int i=ql; i<=qr; i++)
						if ((Q[i].y1<mid)&&(Q[i].y2<mid))
							swap(Q[i],Q[++k]);
					if (ql<=k)  solve(xl,xr,yl,mid-1,ql,k);
				}
			if (yr>mid)
				{
					int k=qr+1;
					for (int i=qr; i>=ql; i--)
						if ((Q[i].y1>mid)&&(Q[i].y2>mid))
							swap(Q[i],Q[--k]);
					if (k<=qr)  solve(xl,xr,mid+1,yr,k,qr);
				}
		}
}

void work()
{
	scanf("%d %d",&n,&m),N=1;
	while (N<n*m)  N<<=1;
	for (int i=1; i<=n; i++)
		for (int j=1; j<m; j++)
			scanf("%d",&r[i][j]);
	for (int i=1; i<n; i++)
		for (int j=1; j<=m; j++)
			scanf("%d",&c[i][j]);
	scanf("%d",&q);
	for (int i=1; i<=q; i++)
		{
			scanf("%d %d %d %d",&Q[i].x1,&Q[i].y1,&Q[i].x2,&Q[i].y2);
			Q[i].id=i,Q[i].ans=oo;
		}
	build(),solve(1,n,1,m,1,q);
	sort(Q+1,Q+q+1,cmpid);
	for (int i=1; i<=q; i++)
		printf("%d\n",Q[i].ans);
}

int main()
{
	freopen("184.in","r",stdin);
	freopen("184.out","w",stdout);
	work();
	return 0;
}
