#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct node{int a,b;}a[5010];
int n;

bool cmp(node x,node y){return ((x.a<y.a)||((x.a==y.a)&&(x.b<y.b)));}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d %d",&a[i].a,&a[i].b);
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for (int i=1; i<=n; i++)
		if (a[i].b>=ans)  ans=a[i].b;  else  ans=a[i].a;
	printf("%d",ans);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
} 
