#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

const int mo=1e9+7;
struct edge{int s,t,n;}e[200010];
int n,m,s,t,h[100010],f[100010],r[100010],rd[100010],ans;
queue <int> Q;

int ksm(int a,int b)
{
	int x=a;  a=1;
	while (b)
		{
			if (b&1)  a=1LL*a*x%mo;
			x=1LL*x*x%mo,b>>=1;
		}
	return a;
}

void work()
{
	scanf("%d %d %d %d",&n,&m,&s,&t),rd[t]++;
	for (int i=1,x,y; i<=m; i++)
		{
			scanf("%d %d",&x,&y);
			e[i]=(edge){x,y,h[x]},h[x]=i,r[y]++,rd[y]++;
		}
	ans=1;
	for (int i=2; i<=n; i++)  ans=1LL*ans*rd[i]%mo;
	if (t!=1)  f[t]=1;
	Q.push(1);
	for (int i=1,x; i<=n; i++)
		{
			if (Q.empty())  {printf("0");  return;}
			x=Q.front(),Q.pop();
			f[x]=1LL*f[x]*ksm(rd[x],mo-2)%mo;
			for (int j=h[x],y; y=e[j].t,j; j=e[j].n)
				{
					f[y]=(f[y]+f[x])%mo;
					if (!(--r[y]))  Q.push(y);
				}
		}
	printf("%d",(ans-1LL*ans*f[s]%mo+mo)%mo);
}

int main()
{
	freopen("4011.in","r",stdin);
	freopen("4011.out","w",stdout);
	work();
	return 0;
}
