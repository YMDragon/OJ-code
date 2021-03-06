#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct node{int l,d;}a[100010];
int n,b[205],ans;

bool cmp(node x,node y){return x.l>y.l;}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i].l);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i].d),b[a[i].d]++;
	sort(a+1,a+n+1,cmp);
	ans=1<<30;
	for (int i=1,x=0,y,z,g; i<=n; i++)
		{
			y=a[i].d,b[a[i].d]--,g=1,z=0;
			while (a[i+1].l==a[i].l)  i++,y+=a[i].d,b[a[i].d]--,g++;
			for (int j=1,k=max(0,n-i-g+1); j<=200; j++)
				z+=min(k,b[j])*j,k-=min(k,b[j]);
			ans=min(ans,x+z),x+=y;
		}
	printf("%d",ans);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
