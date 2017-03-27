#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define LL  long long
#define oo  (1<<30)
using namespace std;

struct node{int n,id;}a[100010];
int n,x,y,p;

bool cmpn(node x,node y){return x.n<y.n;}
bool cmpid(node x,node y){return x.id<y.id;}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i].n),a[i].id=i;
	sort(a+1,a+n+1,cmpn);
	for (int i=1; i<=n; i++)  a[i].n=i;
	sort(a+1,a+n+1,cmpid);
	for (x=1; x<=n; x++)
		if (a[x].n!=x)
			break;
	for (y=n; y>=1; y--)
		if (a[y].n!=y)
			break;
	if (x==n+1)
		printf("yes\n1 1");
	else
		{
			p=1;
			for (int i=x; i<=(x+y)>>1; i++)
				swap(a[i].n,a[y-i+x].n);
			for (int i=x; i<y; i++)
				if (a[i].n!=i)
					{p=0;  break;}
			if (p)  printf("yes\n%d %d",x,y);
			else  printf("no");
		}
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
