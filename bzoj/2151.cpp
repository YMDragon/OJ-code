#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#define mp  make_pair
using namespace std;

typedef pair <int,int>  PII;
const int N=200010;
int n,m,a[N],next[N],pre[N],mk[N],ans;
priority_queue <PII> Q;

void del(int x)
{
	mk[x]=1,next[pre[x]]=next[x],pre[next[x]]=pre[x];
}

void work()
{
	scanf("%d %d",&n,&m);
	if (m>n/2)  printf("Error!"),exit(0);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	for (int i=1; i<=n; i++)  next[i]=i+1,pre[i]=i-1;
	next[n]=1,pre[1]=n;
	for (int i=1; i<=n; i++)  Q.push(mp(a[i],i));
	while (m--)
		{
			int x;
			do  x=Q.top().second,Q.pop();  while (mk[x]);
			ans+=a[x];
			a[x]=a[pre[x]]+a[next[x]]-a[x];
			del(pre[x]),del(next[x]);
			Q.push(mp(a[x],x));
		}
	printf("%d",ans);
}

int main()
{
	freopen("2151.in","r",stdin);
	freopen("2151.out","w",stdout);
	work();
	return 0;
}
