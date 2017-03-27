#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const double pi=acos(-1);
struct comp{double l,r;}a[400010],b[400010],c[400010];
int n,m,N;

comp operator + (comp x,comp y){return (comp){x.l+y.l,x.r+y.r};}
comp operator - (comp x,comp y){return (comp){x.l-y.l,x.r-y.r};}
comp operator * (comp x,comp y){return (comp){x.l*y.l-x.r*y.r,x.l*y.r+x.r*y.l};}
comp operator / (comp x,double y){return (comp){x.l/y,x.r/y};}

void FFT(comp *a,int n,int op)
{
	for (int i=0; i<n; i++)
		{
			int t=i,p=0;
			for (int j=1; j<n; j<<=1)  p<<=1,p|=(t&1),t>>=1;
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

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=0,x; i<=n; i++)
		scanf("%d",&x),a[i].l=x;
	for (int i=0,x; i<=m; i++)
		scanf("%d",&x),b[i].l=x;
	n++,m++,N=1;
	for (; N<n+m; N<<=1);
	FFT(a,N,1),FFT(b,N,1);
	for (int i=0; i<N; i++)  c[i]=a[i]*b[i];
	FFT(c,N,-1);
	for (int i=0; i<n+m-1; i++)
		printf("%d ",int(c[i].l+0.5));
}

int main()
{
	freopen("34.in","r",stdin);
	freopen("34.out","w",stdout);
	work();
	return 0;
}
