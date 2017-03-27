#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

typedef long long  LL;
typedef pair<LL,int> PLI;
int n,l[100010],r[100010],vis[100010];
LL m[100010],ans;
priority_queue <PLI> Q;

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		{
			scanf("%lld",&m[i]),Q.push(make_pair(m[i],i));
			l[i]=(i==1?n:i-1),r[i]=(i==n?1:i+1);
		}
	for (int i=0,x; i<n/3; )
		{
			x=Q.top().second,Q.pop();
			if (!vis[x])
				{
					ans+=m[x],i++;
					m[x]=m[l[x]]+m[r[x]]-m[x];
					vis[l[x]]=vis[r[x]]=1;
					l[x]=l[l[x]],r[x]=r[r[x]];
					r[l[x]]=l[r[x]]=x;
					Q.push(make_pair(m[x],x));
				}
		}
	printf("%lld",ans);
}

int main()
{
	freopen("1380.in","r",stdin);
	freopen("1380.out","w",stdout);
	work();
	return 0;
}
