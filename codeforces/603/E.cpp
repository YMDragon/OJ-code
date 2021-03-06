#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define pb  push_back
using namespace std;

struct edge{int x,y,d,id;}a[300010],b[300010];
int n,m,p,ans[300010],ufs[300010],siz[300010];
vector <int> V[3];

bool cmpd(edge x,edge y){return x.d<y.d;}
int find(int x){return ufs[x]==x?x:find(ufs[x]);}

void merge(int x,int y)
{
	x=find(x),y=find(y);
	if (x==y)  return;
	if (siz[x]<siz[y])  swap(x,y);
	if ((siz[x]&1)&(siz[y]&1))  p-=2,V[0].pb(2);  else  V[0].pb(0);
	ufs[y]=x,siz[x]+=siz[y];
	V[1].pb(x),V[2].pb(y);
}

void back(int size)
{
	int x,y;
	while (V[0].size()>size)
		{
			p+=V[0].back(),x=V[1].back(),y=V[2].back();
			V[0].pop_back(),V[1].pop_back(),V[2].pop_back();
			ufs[y]=y,siz[x]-=siz[y];
		}
}

void solve(int la,int ra,int lb,int rb)
{
	if ((la>ra)||(lb>rb))  return;
	int mida=(la+ra)>>1,midb=0,size=V[0].size();
	for (int i=la; i<=mida; i++)
		if (a[i].id<lb)  merge(a[i].x,a[i].y);
	for (int i=lb; i<=rb; i++)
		if (b[i].id<=mida)
			{
				merge(b[i].x,b[i].y);
				if (!p)  {midb=i;  break;}
			}
	back(size),ans[mida]=b[midb].d;
	if (!midb)
		{
			for (int i=la; i<=mida; i++)
				if (a[i].id<lb)
					merge(a[i].x,a[i].y);
			solve(mida+1,ra,lb,rb);
			back(size);
			return;
		}
	for (int i=lb; i<midb; i++)
		if (b[i].id<la)  merge(b[i].x,b[i].y);
	solve(la,mida-1,midb,rb);
	back(size);
	for (int i=la; i<=mida; i++)
		if (a[i].id<lb)  merge(a[i].x,a[i].y);
	solve(mida+1,ra,lb,midb);
	back(size);
}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=m; i++)
		scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].d),b[i]=a[i],b[i].id=i,ans[i]=-1;
	b[0].d=-1;
	sort(b+1,b+m+1,cmpd),p=n;
	for (int i=1; i<=m; i++)  a[b[i].id].id=i;
	for (int i=1; i<=n; i++)  ufs[i]=i,siz[i]=1;
	solve(1,m,1,m);
	for (int i=1; i<=m; i++)
		printf("%d\n",ans[i]);
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
