#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

typedef long long  LL;
struct node{int s,h,f,d,vis,k;}t[1000010];
struct edge{int s,t,d,n;}e[2000010];
queue <int> Q,P;
int n;

void bfs1()
{
	int x,y;
	Q.push(1),t[1].f=0,t[1].vis=1;
	while (!Q.empty())
		{
			x=Q.front(),Q.pop();
			for (int i=t[x].h; i&&(y=e[i].t); i=e[i].n,t[x].k++)
				if (!t[y].vis)
					Q.push(y),t[y].f=x,t[y].d=e[i].d,t[y].vis=1;
			if (t[x].k==1)  P.push(x);
		}
}

void bfs2()
{
	int x,f;
	while (!P.empty())
		{
			x=P.front(),P.pop(),t[x].s++,f=t[x].f,t[f].k--;
			if (f)
				{
					t[f].s+=t[x].s;
					if (t[f].k==1)  P.push(f),t[f].vis=2;
				}
		}
}

LL nabs(int n){return n>0?(1LL*n):(1LL*(-n));}

void work()
{
	int x,y,z;
	scanf("%d",&n);
	for (int i=1; i<n; i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			e[i]=(edge){x,y,z,t[x].h},t[x].h=i;
			e[i+n]=(edge){y,x,z,t[y].h},t[y].h=i+n;
		}
	bfs1();
	bfs2();
	LL ans=0;
	for (int i=2; i<=n; i++)
		ans+=1LL*t[i].d*nabs(n-(t[i].s<<1));
	printf("%lld",ans);
}

int main()
{
	freopen("2435.in","r",stdin);
	freopen("2435.out","w",stdout);
	work();
	return 0;
}
