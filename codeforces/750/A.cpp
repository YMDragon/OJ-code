#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,k,ans;

void work()
{
	scanf("%d %d",&n,&k),k=240-k;
	for (int i=1; i<=n; i++)  if (k>=i*5)  k-=i*5,ans++;
	printf("%d",ans);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
