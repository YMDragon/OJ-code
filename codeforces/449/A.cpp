#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;

LL solve(int n,int m,int k)
{
	LL res=0;
	int t=int(sqrt(n));
	for (int i=0; i<=min(t,k); i++)
		res=max(res,1LL*(n/(i+1))*(m/(k-i+1)));
	for (int j=1; j<=t; j++)
		{
			int i=min(n/j-1,k);
			res=max(res,1LL*(n/(i+1))*(m/(k-i+1)));
		}
	return res?res:-1;
}

void work()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	printf("%lld",max(solve(n,m,k),solve(m,n,k)));
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
