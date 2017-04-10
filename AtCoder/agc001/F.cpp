#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

const int N=500010;
struct edge{int s,t,n;}e[2*N];
int n,k,tot,p[N],q[N],h[N],d[N];
set <int> S;
set <int> ::iterator It;

void work()
{
	scanf("%d %d",&n,&k);
	for (int i=1; i<=n; i++)  scanf("%d",&p[i]),q[p[i]]=i;
	for (int i=1; i<=n; i++)
		{
			if (i>k)  S.erase(p[i-k]);
			It=S.insert(p[i]).first;
			if ((++It)!=S.end())
				e[++tot]=(edge){i,q[*It],h[i]},h[i]=tot,d[q[*It]]++;
		}
	S.clear();
	for (int i=n; i; i--)
		{
			if (i+k<=n)  S.erase(p[i+k]);
			It=S.insert(p[i]).first;
			if ((++It)!=S.end())
				e[++tot]=(edge){i,q[*It],h[i]},h[i]=tot,d[q[*It]]++;
		}
	S.clear();
	for (int i=1; i<=n; i++)  if (!d[i])  S.insert(i);
	for (int i=1; i<=n; i++)
		{
			It=S.begin(),S.erase(It),p[*It]=i;
			for (int j=h[*It]; j; j=e[j].n)
				if (!(--d[e[j].t]))
					S.insert(e[j].t);
		}
	for (int i=1; i<=n; i++)  printf("%d\n",p[i]);
}

int main()
{
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
	work();
	return 0;
}
