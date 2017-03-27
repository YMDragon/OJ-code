#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
LL n,a,b,a1,b1,s;

void work()
{
	scanf("%I64d %I64d %I64d",&n,&a,&b),n*=6;
	if (a*b>=n)  {printf("%I64d\n%I64d %I64d",a*b,a,b);  return;}
	s=-1;
	for (LL i=1; i<=sqrt(n); i++)
		{
			LL j=(n+i-1)/i;
			if ((i>=a)&&(j>=b)&&((s==-1)||(i*j<s)))  s=i*j,a1=i,b1=j;
			if ((i>=b)&&(j>=a)&&((s==-1)||(i*j<s)))  s=i*j,a1=j,b1=i;
		}
	for (LL k=1; k<=sqrt(n); k++)
		{
			LL i=n/k,j=(n+i-1)/i;
			if ((i>=a)&&(j>=b)&&((s==-1)||(i*j<s)))  s=i*j,a1=i,b1=j;
			if ((i>=b)&&(j>=a)&&((s==-1)||(i*j<s)))  s=i*j,a1=j,b1=i;
		}
	printf("%I64d\n%I64d %I64d",s,a1,b1);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
} 
