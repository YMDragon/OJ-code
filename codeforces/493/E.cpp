#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
LL a,b,t,c,n,sum,l[1010],ans;

void work()
{
	scanf("%lld %lld %lld",&t,&a,&b);
	if (a==1)
		if (b==1)  if (t==1)  printf("inf");  else  printf("1");  else  printf("0");
	else
		{
			c=b;
			while (c)
				sum+=l[++n]=c%a,c/=a;
			if ((t==1)&&(b>=a)&&(sum==1))  ans++;
			if ((t>1)&&(b==a))  ans++;
			sum=0,c=1;
			for (int i=1; i<=n; i++)
				sum+=l[i]*c,c*=t;
			if (sum==a)  ans++;
			printf("%lld",ans);
		}
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
