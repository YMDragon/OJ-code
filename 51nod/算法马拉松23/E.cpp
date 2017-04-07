#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define Ls(n)  (n<<1)
#define Rs(n)  (Ls(n)|1)
using namespace std;

typedef unsigned long long  u64;
const int Size=300,N=131072;
struct query{int l,r,id;}q[50010];
int n,m,a[50010];
u64 ans[50010],t[1<<19][4],res,s[4];

bool cmp(query x,query y)
{
	if (x.l/Size!=y.l/Size)  return x.l<y.l;
	else  if (x.r!=y.r)  return x.r<y.r;
	else  return x.l<y.l;
}

void modify(int x,int i,bool op)
{
	int n=x+N-1;  
	for (; n; n>>=1)
		if (op)
			t[n][0]+=1LL*x*i,t[n][1]+=x,t[n][2]+=i,t[n][3]++;
		else
			t[n][0]-=1LL*x*i,t[n][1]-=x,t[n][2]-=i,t[n][3]--;
}

void askl(int x,bool op)
{
	int n=x+N;
	for (; n>1; n>>=1)
		if (n&1)
			if (op)
				s[0]+=t[n-1][0],s[1]+=t[n-1][1],s[2]+=t[n-1][2],s[3]+=t[n-1][3];
			else
				s[0]-=t[n-1][0],s[1]-=t[n-1][1],s[2]-=t[n-1][2],s[3]-=t[n-1][3];
}

void askr(int x,bool op)
{
	if (x==1)
		{
			if (op)
				s[0]+=t[1][0],s[1]+=t[1][1],s[2]+=t[1][2],s[3]+=t[1][3];
			else
				s[0]-=t[1][0],s[1]-=t[1][1],s[2]-=t[1][2],s[3]-=t[1][3];
			return;
		}
	int n=x+N-2;
	for (; n>1; n>>=1)
		if (!(n&1))
			if (op)
				s[0]+=t[n+1][0],s[1]+=t[n+1][1],s[2]+=t[n+1][2],s[3]+=t[n+1][3];
			else
				s[0]-=t[n+1][0],s[1]-=t[n+1][1],s[2]-=t[n+1][2],s[3]-=t[n+1][3];
}

void clear(int x)
{
	t[x][0]=t[x][1]=t[x][2]=t[x][3]=0;
	if (x<N)
		{
			if (t[x<<1][0])  clear(x<<1);
			if (t[(x<<1)|1][0])  clear((x<<1)|1);
		}
}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	scanf("%d",&m);
	for (int i=1; i<=m; i++)  scanf("%d %d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+m+1,cmp),q[0].l=1;
	for (int id=1; id<=m; id++)
		{
			if ((id==1)||(q[id].l/Size!=q[id-1].l/Size))
				{
					clear(1),res=0;
					for (int i=q[id].l; i<=q[id].r; i++)
						{
							s[0]=s[1]=s[2]=s[3]=0;
							askl(a[i],1),askr(a[i],0);
							res+=s[0]-s[1]*i-s[2]*a[i]+s[3]*a[i]*i;
							modify(a[i],i,1);
						}
				}else
				{
					for (int i=q[id-1].l; i<q[id].l; i++)
						{
							s[0]=s[1]=s[2]=s[3]=0;
							askl(a[i],0),askr(a[i],1);
							res-=s[0]-s[1]*i-s[2]*a[i]+s[3]*a[i]*i;
							modify(a[i],i,0);
						}
					for (int i=q[id-1].l-1; i>=q[id].l; i--)
						{
							s[0]=s[1]=s[2]=s[3]=0;
							askl(a[i],0),askr(a[i],1);
							res+=s[0]-s[1]*i-s[2]*a[i]+s[3]*a[i]*i;
							modify(a[i],i,1);
						}
					for (int i=q[id-1].r+1; i<=q[id].r; i++)
						{
							s[0]=s[1]=s[2]=s[3]=0;
							askl(a[i],1),askr(a[i],0);
							res+=s[0]-s[1]*i-s[2]*a[i]+s[3]*a[i]*i;
							modify(a[i],i,1);
						}
				}
			ans[q[id].id]=res;
		}
	for (int i=1; i<=m; i++)  printf("%llu\n",ans[i]);
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
