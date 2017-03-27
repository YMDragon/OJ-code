#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long LL;
const int mo=1000000007;
struct edge{LL ch,n;}t[500010];
struct node{LL k,h,s,b;}a[500010];

int n,ans;

void dfs(LL x,LL k)
{
	a[x].b=k*a[x].k%mo;
	k=k*a[x].s%mo;
	for (int i=a[x].h; i; i=t[i].n)
		dfs(t[i].ch,k);
}

bool cmp(node x,node y){return x.b<y.b;}

void work()
{
	int x,y;
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i].k);
	for (int i=1; i<n; i++)
		{
			scanf("%d %d",&x,&y);
			t[i]=(edge){y,a[x].h},a[x].h=i,a[x].s++;
		}
	dfs(1,1);
	sort(a+1,a+n+1,cmp);
	ans=n-1;
	for (int i=1,t=0; i<=n; i++)
		{
			if (a[i].b!=a[i-1].b)  ans=min(ans,n-t),t=0;
			t++;
		}
	printf("%d",ans);
}

int main()
{
	freopen("3573.in","r",stdin);
	freopen("3573.out","w",stdout);
	work();
	return 0;
} 
