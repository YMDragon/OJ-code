#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
LL n=600851475143LL;
int ans;

void work()
{
	ans=1;
	for (int i=2; i<=sqrt(n); i++)
		if (!(n%i))
			while (!(n%i))  n/=i,ans=max(ans,i);
	printf("%d\n",max(ans,int(n)));
}

int main()
{
	work();
	return 0;
}
