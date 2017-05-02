#include <algorithm>
#include <cstring>
#include "spots.h"
#define ls  (x<<1)
#define rs  (ls|1)
using namespace std;

const int MX=int(1e9-1);
struct node{int x,y,id;}a[500010];
int n,D,d,l[1<<20],r[1<<20],L[1<<20],R[1<<20],cnt[20];
int y[20][500010],id[20][500010];

bool cmp(node x,node y){return x.x<y.x;}

void merge(int x,int dep)
{
	l[x]=l[ls],r[x]=(r[rs]>=0)?r[rs]:r[ls];
	L[x]=L[ls],R[x]=(R[rs]>=0)?R[rs]:R[ls];
	if (L[x]>R[x])  return;
	int i=L[ls],j=L[rs],k=L[x];
	for (; i<=R[ls]&&j<=R[rs]; )
		if (y[dep+1][i]<y[dep+1][j])
			y[dep][k]=y[dep+1][i],id[dep][k++]=id[dep+1][i++];
		else  y[dep][k]=y[dep+1][j],id[dep][k++]=id[dep+1][j++];
	for (; i<=R[ls]; )  y[dep][k]=y[dep+1][i],id[dep][k++]=id[dep+1][i++];
	for (; j<=R[rs]; )  y[dep][k]=y[dep+1][j],id[dep][k++]=id[dep+1][j++];
}

void ask(int x,int dep,int xL,int xR,int yL,int yR)
{
	if ((r[x]==-1)||(dep>D))  return;
	if ((xL<=l[x])&&(r[x]<=xR))
		{
			if ((y[dep][R[x]]<yL)||(y[dep][L[x]]>yR))  return;
			int *y_=y[dep],*id_=id[dep],i=1,j=1;
			for (; L[x]+i<=R[x]+1; i<<=1)  if (y_[L[x]+i-1]>=yL)  break;
			if (L[x]+i>R[x]+1)  i=R[x]-L[x]+1;
			for (j=i; j; j>>=1)  if (y_[L[x]+i-j]>=yL)  i-=j;
			for (j=L[x]+i; j<=R[x]; j++)
				if (y_[j]<=yR)  report(id_[j]);  else  break;
		}else
		{
			if (xL<=r[ls])  ask(ls,dep+1,xL,xR,yL,yR);
			if (l[rs]<=xR)  ask(rs,dep+1,xL,xR,yL,yR);
		}
}

void spots_init(vector< pair<int, int> > p) {
	n=p.size();
	memset(r,-1,sizeof(r)),memset(R,-1,sizeof(R));
	for (int i=0; i<n; i++)
		a[i].x=p[i].first,a[i].y=p[i].second,a[i].id=i;
	sort(a,a+n,cmp);
	for (D=1,d=0; D<n; D<<=1,d++);
	for (int i=0; i<n; i++)
		l[i+D]=r[i+D]=a[i].x,L[i+D]=R[i+D]=i,id[d][i]=a[i].id,y[d][i]=a[i].y;
	for (int i=D-1,j=d-1; i; i--)
		{
			merge(i,j);
			if (i==(1<<j))  j--;
		}
}

void spots(int x1, int y1, int x2, int y2) {
	ask(1,0,x1,x2,y1,y2);
}
