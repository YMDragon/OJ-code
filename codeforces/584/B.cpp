#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=int(1e9+7);
int n,ans;

int ksm(int a,int b){return b?(1LL*ksm(1LL*a*a%mo,b/2)*((b&1)?a:1)%mo):1;}

void work()
{
	scanf("%d",&n);
	printf("%d",(ksm(27,n)-ksm(7,n)+mo)%mo);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
