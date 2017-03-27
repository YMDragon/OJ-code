#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

typedef int arr[200010];
const double pi=acos(-1);
struct edge{int s,t,d,ty,n;}e[500010];
struct complex{
	double x,y;
	complex () : x(0),y(0) {}
	complex (double _x,double _y) : x(_x),y(_y) {}
}A[200010],B[200010],C[200010];
int n,tot,Tot,maxdis[2],ans;
arr h,fa,siz,a,dis[2],mul,prime;
queue <int> Q,P[2];

complex operator + (complex x,complex y){return complex(x.x+y.x,x.y+y.y);}
complex operator - (complex x,complex y){return complex(x.x-y.x,x.y-y.y);}
complex operator * (complex x,complex y){return complex(x.x*y.x-x.y*y.y,x.x*y.y+x.y*y.x);}
complex operator / (complex x,double y){return complex(x.x/y,x.y/y);}

void addedge(int x,int y,int d)
{
	e[++tot]=(edge){x,y,d,0,h[x]},h[x]=tot;
	e[++tot]=(edge){y,x,d,0,h[y]},h[y]=tot;
}

void build(int x,int f)
{
	int m=0,hx=h[x];
	for (int i=hx; i; i=e[i].n)
		if (f!=e[i].t)  m++;
	if (!m)
		{
			h[x]=0;
			if (fa[x])  addedge(fa[x],x,1);
			return;
		}
	Q.push(x),h[x]=0;
	for (int i=1,y; i<m; i++)
		{
			y=Q.front(),Q.pop();
			addedge(y,++Tot,0),addedge(y,++Tot,0);
			Q.push(Tot-1),Q.push(Tot);
		}
	if (fa[x])  addedge(fa[x],x,1);
	for (int i=hx; i; i=e[i].n)
		if (f!=e[i].t)  fa[e[i].t]=Q.front(),Q.pop();
	for (int i=hx; i; i=e[i].n)
		if (f!=e[i].t)  build(e[i].t,x);
}

void FFT(int n,complex *a,int op)
{
	int logn=log2(n);
	for (int i=0; i<n; i++)
		{
			int p=i,q=0;
			for (int j=1; j<=logn; j++)  q<<=1,q|=p&1,p>>=1;
			if (q>i)  swap(a[q],a[i]);
		}
	for (int len=2; len<=n; len<<=1)
		{
			complex w=complex(cos(2*pi*op/len),sin(2*pi*op/len));
			for (int i=0; i<n; i+=len)
				{
					complex W=complex(1,0);
					for (int j=0; j<(len>>1); j++)
						{
							complex u=a[i+j],v=a[i+j+(len>>1)];
							a[i+j]=u+W*v,a[i+j+(len>>1)]=u-W*v,W=W*w;
						}
				}
		}
	if (op==-1)  for (int i=0; i<n; i++)  a[i]=a[i]/n;
}

void FFT(int n,int m,int *a,int *b,int *c)
{
	int N=(n+1)+(m+1)-1,x;
	for (x=N,N=1; x; x>>=1,N<<=1);
	for (int i=0; i<N; i++)  if (i<=n)  A[i]=complex(a[i],0);  else  A[i]=complex(0,0);
	for (int i=0; i<N; i++)  if (i<=m)  B[i]=complex(b[i],0);  else  B[i]=complex(0,0);
	FFT(N,A,1),FFT(N,B,1);
	for (int i=0; i<N; i++)  C[i]=A[i]*B[i];
	FFT(N,C,-1);
	for (int i=0; i<N; i++)  c[i]=C[i].x+0.5;
}

void dfs2(int x,int f)
{
	fa[x]=f,siz[x]=1;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (((i^f)!=1)&&(!e[i].ty))  dfs2(y,i),siz[x]+=siz[y];
}

void dfs3(int x,int f,int dep,int ty)
{
	if (x<=n) dis[ty][dep]++,maxdis[ty]=max(maxdis[ty],dep);
	P[ty].push(x);
	for (int i=h[x]; i; i=e[i].n)
		if ((e[i].t!=f)&&(!e[i].ty))
			dfs3(e[i].t,x,dep+e[i].d,ty);
}

void dfs(int l,int r)
{
	int n=r-l+1,x=0,y=n+1,N=0,M=0,d,mid;
	if (n<=2)  return;
	dfs2(a[l],0);
	for (int i=l; i<=r; i++)
		if (max(siz[a[i]],n-siz[a[i]])<y)  x=a[i],y=max(siz[a[i]],n-siz[a[i]]);
	e[fa[x]].ty=1,e[fa[x]^1].ty=1,d=e[fa[x]].d;
	dfs3(x,0,0,0),dfs3(e[fa[x]].s,0,0,1);
	N=maxdis[0],M=maxdis[1];
	FFT(N,M,dis[0],dis[1],mul);
	for (int i=0; i<=N+M; i++)
		if (prime[i+d])  ans+=mul[i];
	for (int i=0; i<=N; i++)  dis[0][i]=0;
	for (int i=0; i<=M; i++)  dis[1][i]=0;
	maxdis[0]=maxdis[1]=0;
	for (int i=l; i<=r; i++)
		if (!P[0].empty())  a[i]=P[0].front(),P[0].pop();
		else  a[i]=P[1].front(),P[1].pop();
	mid=l+siz[x],dfs(l,mid-1),dfs(mid,r);
}

void work()
{
	scanf("%d",&n),Tot=n,tot=1;
	for (int i=1,x,y; i<n; i++)
		{
			scanf("%d %d",&x,&y);
			addedge(x,y,0);
		}
	build(1,0);
	for (int i=1; i<=Tot; i++)  a[i]=i;
	for (int i=2; i<=n; i++)
		{
			prime[i]=1;
			for (int j=2; j<=sqrt(i); j++)
				if (i%j==0)  {prime[i]=0;  break;}
		}
	dfs(1,Tot);
	printf("%.10lf",ans/(0.5*n*(n-1)));
}

int main()
{
	freopen("PRIMEDST.in","r",stdin);
	freopen("PRIMEDST.out","w",stdout);
	work();
	return 0;
}
