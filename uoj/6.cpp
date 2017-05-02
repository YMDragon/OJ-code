#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int x,a,b,c,d,n,m,q,t[25000010];
short p[25000010][2];

void work()
{
	scanf("%d %d %d %d %d %d %d %d",&x,&a,&b,&c,&d,&n,&m,&q);
	for (int i=1; i<=n*m; i++)  t[i]=i;
	for (int i=1; i<=n*m; i++)
		{
			x=(1LL*a*x%d*x+1LL*b*x+c)%d;
			swap(t[i],t[x%i+1]);
		}
	for (int i=1,u,v; i<=q; i++)
		scanf("%d %d",&u,&v),swap(t[u],t[v]);
	for (int i=1; i<=n*m; i++)
		p[t[i]][0]=(i-1)/m+1,p[t[i]][1]=(i-1)%m+1;
	for (int i=1; i<=n*m; i++)
		if (p[i][0])
			{
				printf("%d ",i);
				if ((p[i][0]!=n)&&(p[i][1]!=0))
					for (int j=p[i][0]+1; j<=n&&p[t[(j-1)*m+p[i][1]-1]][0]; j++)
						for (int k=p[i][1]-1; k&&p[t[(j-1)*m+k]][0]; k--)
							p[t[(j-1)*m+k]][0]=0;
				if ((p[i][0]!=1)&&(p[i][1]!=m))
					for (int j=p[i][0]-1; j&&p[t[(j-1)*m+p[i][1]+1]][0]; j--)
						for (int k=p[i][1]+1; k<=m&&p[t[(j-1)*m+k]][0]; k++)
							p[t[(j-1)*m+k]][0]=0;
			}
}

int main()
{
	freopen("6.in","r",stdin);
	freopen("6.out","w",stdout);
	work();
	return 0;
}
