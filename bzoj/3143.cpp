#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const long double eps=1e-20;
struct edge{int s,t,n;}e[500010];
int n,m,map[505][505],d[505],h[505];
long double w[505],a[505][505],v[505],ans;

bool cmp(long double x,long double y){return x>y;}

void gause()
{
	for (int i=1; i<=n; i++)
		{
			if (a[i][i]==0)
				for (int j=i+1; j<=n; j++)
					if (a[j][i]!=0)
						{
							for (int k=i+1; k<=n+1; k++)
								swap(a[i][k],a[j][k]);
							break;
						}
			for (int j=i+1; j<=n; j++)
				{
					long double t=a[j][i]/a[i][i];
					for (int k=i; k<=n+1; k++)
						a[j][k]-=t*a[i][k];
				}
		}
	for (int i=n; i>=1; i--)
		{
			for (int j=i+1; j<=n; j++)
				a[i][n+1]-=a[i][j]*v[j];
			v[i]=a[i][n+1]/a[i][i]+eps;
		}
}

void work()
{
	scanf("%d %d",&n,&m),n--;
	for (int i=1,x,y,tot=0; i<=m; i++)
		{
			scanf("%d %d",&x,&y);
			e[++tot]=(edge){x,y,h[x]},h[x]=tot,d[x]++;
			e[++tot]=(edge){y,x,h[y]},h[y]=tot,d[y]++;
		}
	for (int i=1; i<=n; i++)
		{
			a[i][i]=1;
			for (int j=h[i],y; y=e[j].t,j; j=e[j].n)
				if (y<=n)  a[i][y]-=1.0/d[y];
		}
	a[1][n+1]=1;
	gause();
	for (int i=1; i<=2*m; i+=2)
		w[(i+1)/2]=v[e[i].s]/(1.0*d[e[i].s])+v[e[i].t]/(1.0*d[e[i].t]);
	sort(w+1,w+m+1,cmp);
	for (int i=1; i<=m; i++)
		ans+=w[i]*i;
	printf("%.3Lf",ans);
}

int main()
{
	freopen("3143.in","r",stdin);
	freopen("3143.out","w",stdout);
	work();
	return 0;
}
