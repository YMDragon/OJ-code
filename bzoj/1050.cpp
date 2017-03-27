#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct edge{int s,t,d;}e[5010];
int n,m,h[505],ufs[505],S,T,p,q;

bool cmpd(edge x,edge y){return x.d<y.d;}
void upd(int pp,int qq){if ((!p)||(1LL*p*qq>1LL*pp*q))  p=pp,q=qq;}
int find(int x){return ufs[x]==x?x:ufs[x]=find(ufs[x]);}
int gcd(int x,int y){return y?gcd(y,x%y):x;}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=m; i++)
		scanf("%d %d %d",&e[i].s,&e[i].t,&e[i].d);
	scanf("%d %d",&S,&T);
	sort(e+1,e+m+1,cmpd);
	for (int i=1; i<=m; i++)
		{
			for (int j=1; j<=n; j++)  ufs[j]=j;
			for (int j=i,x,y; j<=m; j++)
				{
					if ((x=find(e[j].s))!=(y=find(e[j].t)))
						ufs[y]=x;
					if (find(S)==find(T))  {upd(e[j].d,e[i].d);  break;}
				}
		}
	if (p)
		{
			int g=gcd(p,q);  p/=g,q/=g;
			if (q==1)  printf("%d",p);  else  printf("%d/%d",p,q);
		}else  printf("IMPOSSIBLE");
}

int main()
{
	freopen("1050.in","r",stdin);
	freopen("1050.out","w",stdout);
	work();
	return 0;
}
