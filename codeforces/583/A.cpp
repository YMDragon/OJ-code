#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,s[55],h[55];

void work()
{
	scanf("%d",&n);
	for (int i=1,x,y; i<=n*n; i++)
		{
			scanf("%d %d",&x,&y);
			if (!(s[x]+h[y]))
				s[x]=h[y]=1,printf("%d ",i);
		}
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
