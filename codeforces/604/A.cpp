#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int m[6],w[6],hs,hu,ans;

void work()
{
	for (int i=1; i<=5; i++)  scanf("%d",&m[i]);
	for (int i=1; i<=5; i++)  scanf("%d",&w[i]);
	scanf("%d %d",&hs,&hu);
	for (int i=1; i<=5; i++)
		ans+=max(150*i,(500-m[i]*2)*i-50*w[i]);
	ans+=100*hs-50*hu;
	printf("%d",ans);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
