#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct node{int p,l,h;}a[10010];
int n,m,k,cnt,x[10010],y[10010],f[2][1010],ans;

bool cmp(node x,node y){return x.p<y.p;}
void modify(int &x,int y){if (x==-1)  x=y;  else  x=min(x,y);}

void work()
{
	scanf("%d %d %d",&n,&m,&k);
	for (int i=0; i<n; i++)
		scanf("%d %d",&x[i],&y[i]);
	for (int i=1; i<=k; i++)
		scanf("%d %d %d",&a[i].p,&a[i].l,&a[i].h);
	sort(a+1,a+k+1,cmp);
	for (int i=0,l=1,t; i<n; i++)
		{
			if ((l<=k)&&(i==a[l].p))
				{
					for (int j=1; j<=a[l].l; j++)  f[cnt][j]=-1;
					for (int j=a[l].h; j<=m; j++)  f[cnt][j]=-1;
					l++;
				}
			for (int j=1; j<=m; j++)  f[cnt^1][j]=-1;
			t=1;
			for (int j=1; j<=m; j++)
				{
					if (f[cnt][j]!=-1)  modify(f[cnt^1][min(j+x[i],m)],f[cnt][j]+1),t=0;
					if ((f[cnt][j]!=-1)&&(j>y[i]))  modify(f[cnt^1][j-y[i]],f[cnt][j]),t=0;
					if (f[cnt^1][j]!=-1)  modify(f[cnt^1][min(j+x[i],m)],f[cnt^1][j]+1),t=0;
				}
			if (t)  {printf("0\n%d",l-2);  return;}
			cnt^=1;
		}
	ans=-1;
	for (int i=1; i<=m; i++)
		if (f[cnt][i]!=-1)  modify(ans,f[cnt][i]);
	printf("1\n%d",ans);
}

int main()
{
	freopen("17.in","r",stdin);
	freopen("17.out","w",stdout);
	work();
	return 0;
}
