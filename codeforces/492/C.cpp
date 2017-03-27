#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
struct node{int a,b;}a[100010];
LL n,v,avg,ans;

bool cmp(node x,node y){return x.b<y.b;}

void work()
{
	scanf("%lld %lld %lld",&n,&v,&avg),avg*=n;
	for (int i=1; i<=n; i++)  scanf("%d %d",&a[i].a,&a[i].b),avg-=a[i].a;
	if (avg<=0)  {printf("0");  return;}
	sort(a+1,a+n+1,cmp);
	for (int i=1; i<=n; i++)
		{
			LL t=min(avg,v-a[i].a);
			avg-=t,ans+=t*a[i].b;
		}
	printf("%lld",ans);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
} 
