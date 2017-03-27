#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

struct edge{int s,t,n;}e[100010];
int n,m,h[100010],r[100010],ans[100010];
set <int> S;

void work()
{
	scanf("%d %d",&n,&m),memset(h,0,sizeof(h)),memset(r,0,sizeof(r));;
	for (int i=1,x,y; i<=m; i++)
		{
			scanf("%d %d",&x,&y);
			e[i]=(edge){y,x,h[y]},h[y]=i,r[x]++;
		}
	for (int i=1; i<=n; i++)  if (!r[i])  S.insert(i);
	for (int i=1; i<=n; i++)
		{
			if (!S.size())  {printf("Impossible!\n");  return;}
			set <int>::iterator x=S.end();
			x--,S.erase(x),ans[i]=*x;
			for (int j=h[*x]; j; j=e[j].n)
				if (!(--r[e[j].t]))  S.insert(e[j].t);
		}
	for (int i=n; i; i--)
		printf("%d ",ans[i]);
	printf("\n");
}

int main()
{
	freopen("4010.in","r",stdin);
	freopen("4010.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
