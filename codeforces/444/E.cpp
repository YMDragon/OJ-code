#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define LL  long long
#define oo  (1<<30)
using namespace std;

struct edge{int s,t,d;}e[3010];
int n,sum,p[3010],s[3010],x[3010];

bool cmp(edge x,edge y){return x.d<y.d;}
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<n; i++)  scanf("%d %d %d",&e[i].s,&e[i].t,&e[i].d);
	sort(e+1,e+n,cmp);
	for (int i=1; i<=n; i++)
		scanf("%d",&x[i]),sum+=x[i],p[i]=i,s[i]=1;
	for (int i=1,a,b; i<n; i++)
		{
			a=find(e[i].s),b=find(e[i].t);
			p[b]=a,s[a]+=s[b],x[a]+=x[b];
			if (s[a]>sum-x[a])  {printf("%d",e[i].d);  return;}
		}
	printf("0");
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
