#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct node{int x,id;}a[505];
int n,ans[505];

bool cmp(node x,node y){return x.x<y.x;}

void work()
{
	scanf("%d",&n);
	for (int i=1,x; i<=n; i++)
		{
			scanf("%d",&x);
			for (int j=0; j<=30; j++)
				a[i].x|=(x&1)<<(30-j),x>>=1;
			a[i].id=i;
		}
	sort(a+1,a+n+1,cmp);
	for (int i=1; i<=n; i++)  printf("%d ",a[i].id);
}

int main()
{
	freopen("143.in","r",stdin);
	freopen("143.out","w",stdout);
	work();
	return 0;
}
