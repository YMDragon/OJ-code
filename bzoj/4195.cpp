#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct query{int i,j,e;}q[100010];
struct node{int x,l;}a[200010];
int n,m,ufs[200010];

bool cmp(node x,node y){return x.x<y.x;}

int find(int x){return (ufs[x]==x)?x:ufs[x]=find(ufs[x]);}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		{
			scanf("%d %d %d",&q[i].i,&q[i].j,&q[i].e);
			a[i]=(node){q[i].i,i},a[i+n]=(node){q[i].j,i+n};
		}
	sort(a+1,a+2*n+1,cmp),m=1;
	for (int i=1; i<=2*n; i++)
		{
			if (a[i].x!=a[i-1].x)  m++;
			if (a[i].l<=n)  q[a[i].l].i=m;  else  q[a[i].l-n].j=m;
		}
	for (int i=1; i<=m; i++)  ufs[i]=i;
	for (int i=1; i<=n; i++)
		if (q[i].e)
			{
				int x=q[i].i,y=q[i].j;
				if ((x=find(x))!=(y=find(y)))  ufs[y]=x;
			}
	for (int i=1; i<=n; i++)
		if (!q[i].e)
			{
				int x=q[i].i,y=q[i].j;
				if (find(x)==find(y))  {printf("NO\n");  return;}
			}
	printf("YES\n");
}

int main()
{
	freopen("4195.in","r",stdin);
	freopen("4195.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
