#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define get(_)  (c[i]==1?_:f(c[i],_))
using namespace std;

typedef long long  LL;
LL n=LL(1e15),m,ans,A[1005];
int P,prime[3000000],F[1010][10010],a[32000000],c[32000000];
bool b[32000000];

LL f(int i,LL j)
{
	if (i==1)  return j;
	if ((i<=1000)&&(j<=10000)&&(F[i][j]))  return F[i][j];
	LL res=0,t=get(j),t2;
	for (int k=1,x=i; x; k*=a[i])
		if (x%a[i]==0)
			res+=k*(t-(t2=get(j/k/a[i]))),x/=a[i],t=t2;
		else
			{
				res+=k*t;
				break;
			}
	if ((i<=1000)&&(j<=10000))  F[i][j]=res;
	return res;
}

void work()
{
	for (int i=1e7; i; i/=10)  while ((m+i)*(m+i)<=n)  m+=i;
	b[1]=1;
	for (int i=2; i<=m; i++)
		{
			if (b[i])  continue;
			a[i]=i;
			for (int j=2*i; j<=m; j+=i)  b[j]=1,a[j]=i;
		}
	for (int i=2; i<=m; i++)
		{
			c[i]=i;
			while (c[i]%a[i]==0)  c[i]/=a[i];
		}
	puts("prepare fin.");
	for (int i=1; i<=m; i++)  ans+=f(i,n/i);
	ans*=2;
	puts("calc fin.");
	for (int i=m; i; i--)
		{
			LL s=1LL*(m/i)*(m/i);
			for (int j=2*i; j<=m; j+=i)  s-=(j<=1000)?A[j]:a[j];
			ans-=i*s;
			if (i<=1000)  A[i]=s;  else  a[i]=s;
		}
	printf("%lld\n",ans);
}

int main()
{
	work();
	return 0;
}
