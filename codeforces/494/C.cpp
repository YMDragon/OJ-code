#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

struct node{int l,r;  double p;}a[5010];
int n,q,st[100010][20],mx[100010];
double ans,f[5010][5010];
bool g[5010][5010];
vector <int> V[100010];

bool cmp(node x,node y){return (x.l<y.l)||((x.l==y.l)&&(x.r>y.r));}

int RMQ(int l,int r)
{
	int t=int(log2(r-l+1));
	return max(st[l][t],st[r-(1<<t)+1][t]);
}

void build(int l,int r)
{
	int p=-1;
	for (int i=l+1; i<=r; i++)
		if ((p==-1)||(a[p].r<a[i].l))
			{
				if (p!=-1)  build(p,i-1);
				V[l].push_back(p=i);
			}
	if (p!=-1)  build(p,r);
}

double dp(int x,int s)
{
	double s1=a[x].p,s2=1-a[x].p;
	if (s<0)  return 0;
	if (s>q)  return 1;
	if (g[x][s])  return f[x][s];
	for (int i=0; i<int(V[x].size()); i++)
		s1*=dp(V[x][i],mx[x]-mx[V[x][i]]+s-1),s2*=dp(V[x][i],mx[x]-mx[V[x][i]]+s);
	if (s==0)  s1=0;
	f[x][s]=s1+s2,g[x][s]=1;
	return f[x][s];
}

void work()
{
	scanf("%d %d",&n,&q);
	for (int i=1; i<=n; i++)
		scanf("%d",&st[i][0]);
	for (int i=1; i<=q; i++)
		scanf("%d %d %lf",&a[i].l,&a[i].r,&a[i].p);
	sort(a+1,a+q+1,cmp);
	for (int i=1; i<20; i++)
		for (int j=1; j<=n; j++)
			if (j+(1<<(i-1))<=n)  st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
			else  st[j][i]=st[j][i-1];
	a[0]=(node){1,n,0};
	for (int i=0; i<=q; i++)
		mx[i]=RMQ(a[i].l,a[i].r);
	build(0,q);
	for (int i=0; i<=q; i++)
		{
			ans+=(dp(0,i)-dp(0,i-1))*(mx[0]+i);
			cerr<<i<<' '<<ans<<endl;
		}
	printf("%.9lf",ans);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
} 
