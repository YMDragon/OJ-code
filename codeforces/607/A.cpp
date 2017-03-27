#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct node{int a,b;}a[100010];
int n,f[100010],ans;

bool cmp(node x,node y){return x.a<y.a;}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d %d",&a[i].a,&a[i].b);
	sort(a+1,a+n+1,cmp);
	for (int i=1,x; i<=n; i++)
		{
			x=lower_bound(a+1,a+n+1,(node){a[i].a-a[i].b,0},cmp)-a;
			f[i]=x?f[x-1]+1:1,ans=max(ans,f[i]);
		}
	printf("%d",n-ans);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
