#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define LL  long long
#define oo  (1<<30)
using namespace std;

int n,p,hash[305];

void work()
{
	scanf("%d %d",&p,&n);
	for (int i=1,x; i<=n; i++)
		{
			scanf("%d",&x),x%=p;
			if (hash[x])  {printf("%d",i);  return;}
			hash[x]=1;
		}
	printf("-1");
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
