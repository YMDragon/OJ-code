#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct node{int x,a;}a[105];
int n,ans;

bool cmp(node x,node y){return x.x<y.x;}

void work()
{
	scanf("%d",&n);
	int l=0,r=0;
	for (int i=1; i<=n; i++)
		{
			scanf("%d %d",&a[i].x,&a[i].a);
			if (a[i].x>0)  r++;  else  l++;
		}
	sort(a+1,a+n+1,cmp);
	if (l>r)
		for (int i=l-r; i<=n; i++)  ans+=a[i].a;
	else
		for (int i=1; i<=2*l+1; i++)  ans+=a[i].a;
	printf("%d",ans);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
