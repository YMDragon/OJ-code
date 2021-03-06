#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=int(1e9+7);
struct node{int x,y;}a[2010];
int N,h,w,n,f[2010],A[200010],B[200010];

bool cmp(node x,node y){return (x.x<y.x)||((x.x==y.x)&&(x.y<y.y));}

int ksm(int a,int b)
{
	int x=a;  a=1;
	while (b)
		{
			if (b&1)  a=1LL*a*x%mo;
			x=1LL*x*x%mo,b>>=1;
		}
	return a;
}

int get(int x,int y){return 1LL*A[x+y]*B[x]%mo*B[y]%mo;}

void work()
{
	scanf("%d %d %d",&h,&w,&n),N=h+w;
	for (int i=1; i<=n; i++)  scanf("%d %d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	A[0]=1;
	for (int i=1; i<=N; i++)  A[i]=1LL*A[i-1]*i%mo;
	B[N]=ksm(A[N],mo-2);
	for (int i=N-1; i>=0; i--)  B[i]=1LL*B[i+1]*(i+1)%mo;
	a[++n]=(node){h,w};
	for (int i=1; i<=n; i++)
		{
			f[i]=get(a[i].x-1,a[i].y-1);
			for (int j=1; j<i; j++)
				if (a[j].y<=a[i].y)
					f[i]=(0LL+f[i]-1LL*f[j]*get(a[i].x-a[j].x,a[i].y-a[j].y)%mo+mo)%mo;
		}
	printf("%d",f[n]);
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
