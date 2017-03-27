#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define LL  long long
#define oo  (1<<30)
#include <queue>
using namespace std;

LL h[1010],s[1010],fh[1000010],fs[1000010],ans;
int n,m,k,p;
priority_queue <int> PQ;

void work()
{
	scanf("%d %d %d %d",&n,&m,&k,&p);
	for (int i=1,x; i<=n; i++)
		for (int j=1; j<=m; j++)
			scanf("%d",&x),h[i]+=x,s[j]+=x;
	while (!PQ.empty())  PQ.pop();
	for (int i=1; i<=n; i++)  PQ.push(h[i]);
	for (int i=1,x; i<=k; i++)
		x=PQ.top(),PQ.pop(),fh[i]=fh[i-1]+1LL*x,PQ.push(x-p*m);
	while (!PQ.empty())  PQ.pop();
	for (int i=1; i<=m; i++)  PQ.push(s[i]);
	for (int i=1,x; i<=k; i++)
		x=PQ.top(),PQ.pop(),fs[i]=fs[i-1]+1LL*x,PQ.push(x-p*n);
	ans=fs[k];
	for (int i=0,j; j=k-i,i<=k; i++)
		ans=max(ans,fh[i]+fs[j]-1LL*p*i*j);
	cout<<ans;
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
