#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;

LL n,k,d1,d2,a,b,ans;

void work()
{
	scanf("%lld %lld %lld %lld",&n,&k,&d1,&d2),ans=0;
	a=k+2*d1+d2,b=k-d1-2*d2;
	if ((n>=a)&&((n-a)%3==0)&&(b>=0)&&(b%3==0))  ans++;
	a=k+2*max(d1,d2)-min(d1,d2),b=k-d1-d2;
	if ((n>=a)&&((n-a)%3==0)&&(b>=0)&&(b%3==0))  ans++;
	a=k+d1+d2,b=k-2*max(d1,d2)+min(d1,d2);
	if ((n>=a)&&((n-a)%3==0)&&(b>=0)&&(b%3==0))  ans++;
	a=k+d1+2*d2,b=k-2*d1-d2;
	if ((n>=a)&&((n-a)%3==0)&&(b>=0)&&(b%3==0))  ans++;
	if (ans)  printf("yes\n");  else  printf("no\n");
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)
		work();
	return 0;
} 
