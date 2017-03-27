#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int n=12345;
LL s[12345],ans;

void work()
{
	for (int i=1; i<n; i++)  s[i]=s[i-1]+1LL*i*(i+1)/2;
	for (int i=1; i<=n/3; i++)  ans+=i*s[n-3*i+1];
	printf("%lld\n",ans);
}

int main()
{
	work();
	return 0;
}
