#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <complex>
#include <cstdio>
#include <cmath>
using namespace std;

const double pi=acos(-1);
struct comp{double a,b;}A[1<<15],B[1<<15],C[1<<15];
struct edge{int s,t,d,n;double p[20002],S[20002];}e[105];
int n,m,x,t,dis[55];
double f[55][20002],g[105][20002];

comp operator + (comp x,comp y){return (comp){x.a+y.a,x.b+y.b};}
comp operator - (comp x,comp y){return (comp){x.a-y.a,x.b-y.b};}
comp operator * (comp x,comp y){return (comp){x.a*y.a-x.b*y.b,x.a*y.b+x.b*y.a};}
comp operator / (comp x,double y){return (comp){x.a/y,x.b/y};}

int gi()
{
	int w=0;  char ch=getchar();
	while ((ch<'0')||('9'<ch))  ch=getchar();
	while (('0'<=ch)&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return w;
}

void FFT(comp *a,int n,int op)
{
	for (int i=0,j,t,p; i<n; i++)
		{
			t=i,p=0;
			for (j=1; j<n; j<<=1)  p<<=1,p|=(t&1),t>>=1;
			if (p<i)  swap(a[i],a[p]);
		}
	for (int len=2; len<=n; len<<=1)
		{
			comp w=(comp){cos(2*pi*op/len),sin(2*pi*op/len)};
			for (int i=0; i<n; i+=len)
				{
					comp W=(comp){1,0};
					for (int j=0; j<(len>>1); j++)
						{
							comp u=a[i+j],v=a[i+j+(len>>1)];
							a[i+j]=u+W*v,a[i+j+(len>>1)]=u-W*v,W=W*w;
						}
				}
		}
	if (op==-1)  for (int i=0; i<n; i++)  a[i]=a[i]/n;
}

void trans(int id,int l,int r)
{
	int mid=(l+r)>>1,N=1;
	while (N<=r-mid-1+r-l)  N<<=1;
	for (int i=mid+1; i<=r; i++)  A[i-mid-1]=(comp){f[e[id].t][i],0};
	for (int i=1; i<=r-l; i++)  B[r-l-i]=(comp){e[id].p[i],0};
	FFT(A,N,1),FFT(B,N,1);
	for (int i=0; i<N; i++)  C[i]=A[i]*B[i];
	FFT(C,N,-1);
	for (int i=l; i<=mid; i++)  g[id][i]+=C[r-mid-l-1+i].a;
	for (int i=0; i<N; i++)  A[i]=B[i]=(comp){0,0};
}

void solve(int l,int r)
{
	if (l==r)
		{
			for (int i=1; i<=m; i++)
				f[e[i].s][l]=min(f[e[i].s][l],g[i][l]+e[i].d);
			return;
		}
	int mid=(l+r)>>1;
	solve(mid+1,r);
	for (int i=1; i<=m; i++)  trans(i,l,r);
	solve(l,mid);
}

void work()
{
	n=gi(),m=gi(),t=gi(),x=gi();
	for (int i=1; i<=m; i++)
		{
			e[i].s=gi(),e[i].t=gi(),e[i].d=gi();
			for (int j=1; j<=t; j++)  e[i].p[j]=gi()/1e5;
			for (int j=t; j; j--)  e[i].S[j]=e[i].S[j+1]+e[i].p[j];
		}
	for (int i=1; i<n; i++)
		for (int j=0; j<=t; j++)
			f[i][j]=1e20;
	for (int i=1; i<n; i++)  dis[i]=1<<30;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			dis[e[j].s]=min(dis[e[j].s],dis[e[j].t]+e[j].d);
	for (int i=1; i<=n; i++)  f[i][t+1]=dis[i]+x;
	for (int i=1; i<=m; i++)
		for (int j=0; j<=t; j++)
			g[i][j]=e[i].S[t-j+1]*f[e[i].t][t+1];
	solve(0,t);
	printf("%lf",f[1][0]);
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
