#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

typedef long long  LL;
struct node{LL x;int k;};
int n,k,root;
LL w[100010],ans;
priority_queue <node> Q;

bool operator < (node x,node y){return ((x.x>y.x)||((x.x==y.x)&&(x.k>y.k)));}

void work()
{
	scanf("%d %d",&n,&k);
	for (int i=1; i<=n; i++)  scanf("%lld",&w[i]),Q.push((node){w[i],1});
	while ((n-1)%(k-1)!=0)  n++,Q.push((node){0,1});
	for (int i=1; i<=(n-1)/(k-1); i++)
		{
			node x=Q.top();  Q.pop();
			for (int j=1; j<k; j++)
				{
					node y=Q.top();  Q.pop();
					x.x+=y.x,x.k=max(x.k,y.k);
				}
			x.k++,Q.push(x);
			ans+=x.x;
		}
	printf("%lld\n%d",ans,Q.top().k-1);
}

int main()
{
	freopen("130.in","r",stdin);
	freopen("130.out","w",stdout);
	work();
	return 0;
}
