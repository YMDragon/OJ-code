#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

struct node{int t1,t2;}a[150010];
int n;
priority_queue <int> Q;

bool cmp(node x,node y){return x.t2<y.t2;}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d %d",&a[i].t1,&a[i].t2);
	sort(a+1,a+n+1,cmp);
	for (int i=1,sum=0; i<=n; i++)
		{
			Q.push(a[i].t1),sum+=a[i].t1;
			if (sum>a[i].t2)  sum-=Q.top(),Q.pop();
		}
	printf("%d",Q.size());
}

int main()
{
	freopen("1029.in","r",stdin);
	freopen("1029.out","w",stdout);
	work();
	return 0;
}
