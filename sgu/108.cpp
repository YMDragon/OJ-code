#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct node{int s,id,ans;}a[5010];
int n,m,k;
unsigned int b[350000];

bool cmps(node x,node y){return x.s<y.s;}
bool cmpid(node x,node y){return x.id<y.id;}

void work()
{
	scanf("%d %d",&n,&k);
	for (int i=1; i<=k; i++)
		scanf("%d",&a[i].s),a[i].id=i;
	a[k+1].s=-1;
	sort(a+1,a+k+1,cmps);
	for (int i=1,j=1; i<=n; i++)
		{
			int x=i,sum=i;
			while (x)  sum+=x%10,x/=10;
			if (sum<=n)  b[(sum+29)/30]|=1<<((sum-1)%30);
			if ((b[(i+29)/30]&(1<<((i-1)%30)))==0)
				{
					m++;
					while (m==a[j].s)  a[j++].ans=i;
				}
		}
	printf("%d\n",m);
	sort(a+1,a+k+1,cmpid);
	for (int i=1; i<=k; i++)
		printf("%d ",a[i].ans);
}

int main()
{
	freopen("108.in","r",stdin);
	freopen("108.out","w",stdout);
	work();
	return 0;
}
