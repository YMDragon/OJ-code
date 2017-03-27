#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

typedef pair<int,int>  PII;
struct edge{int a,b,id,x,y;}e[100010];
int n,m,tot;
vector <PII> V;

bool cmpa(edge x,edge y){return (x.a<y.a)||((x.a==y.a)&&(x.b>y.b));}
bool cmpid(edge x,edge y){return x.id<y.id;}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=m; i++)  scanf("%d %d",&e[i].a,&e[i].b),e[i].id=i;
	sort(e+1,e+m+1,cmpa),tot=1;
	for (int i=1; i<=m; i++)
		if (e[i].b)
			{
				e[i].x=1,e[i].y=++tot;
				for (int j=2; j<tot&&V.size()<m; j++)  V.push_back(make_pair(j,tot));
			}else
			{
				if (!V.size())  {printf("-1");  return;}
				e[i].x=V[V.size()-1].first,e[i].y=V[V.size()-1].second,V.pop_back();
			}
	sort(e+1,e+m+1,cmpid);
	for (int i=1; i<=m; i++)
		printf("%d %d\n",e[i].x,e[i].y);
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
