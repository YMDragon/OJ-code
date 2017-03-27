#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const int mo=1000000009;
struct point{int x,y;}w[10010];
int n,m,t,ans,g[10010],l[1200010],r[1200010],f[1200010];

bool cmp(point x,point y){return ((x.y<y.y)||((x.y==y.y)&&(x.x<y.x)));}
int p(int x,int y){return (x-1)*m+y;}

void solve(int x1,int x2,int y)
{
	for (int i=x1; i<=x2; i++)
		g[i]=f[p(i,y)];
	for (int i=x2; i>=x1+2; i--)
		if (g[i]>1)
			for (int j=i-2; j>=x1; j--)
				{
					int k=min(g[i]-1,g[j]),p=(1LL*k*(k+1)/2+max(0,g[i]-k-1)*g[j])%mo;
					ans=(ans+1LL*p*(j-x1)*(x2-i))%mo;
				}
}

void work()
{
	scanf("%d %d %d",&n,&m,&t);
	for (int i=1; i<=t; i++)  scanf("%d %d",&w[i].x,&w[i].y),f[p(w[i].x,w[i].y)]=-1;
	w[t+1]=(point){1,m+1};
	sort(w+1,w+t+1,cmp);
	for (int i=1; i<=n; i++)
		for (int j=1,q; q=p(i,j),j<=m; j++)
			if (f[q]==0)  l[q]=(j==1)?1:l[q-1]+1;
	for (int i=1; i<=n; i++)
		for (int j=m,q; q=p(i,j),j>=1; j--)
			if (f[q]==0)  r[q]=(j==m)?1:r[q+1]+1;
	for (int i=1; i<=n; i++)
		for (int j=1,q; q=p(i,j),j<=m; j++)
			f[q]=min(l[q],r[q])-1;
	for (int i=1; i<=t+1; i++)
		{
			if (w[i].y!=w[i-1].y)
				{
					for (int j=w[i-1].y+1; j<w[i].y; j++)
						solve(1,n,j);
					solve(1,w[i].x-1,w[i].y);
				}
			if (w[i].y==w[i+1].y)  solve(w[i].x+1,w[i+1].x-1,w[i].y);
			else  solve(w[i].x+1,n,w[i].y);
		}
	printf("%d",ans);
}

int main()
{
	freopen("2727.in","r",stdin);
	freopen("2727.out","w",stdout);
	work();
	return 0;
}
