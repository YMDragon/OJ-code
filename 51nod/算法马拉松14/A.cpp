#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,s;

void work()
{
	scanf("%d %d",&n,&m),s=0;
	for (int i=1,x; i<=n*m; i++)
		scanf("%d",&x),s+=x;
	puts(s&1?"yadang":"xiawa");
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
