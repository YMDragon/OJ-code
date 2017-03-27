#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,x,y;

bool ok(int v)
{
	int f1,f2,both;
	f1=v-v/x,f2=v-v/y,both=v-v/x-v/y+v/x/y;
	return ((f1>=x)&&(f2>=y)&&(both>=x+y));
}

void work()
{
	scanf("%d %d %d %d",&n,&m,&x,&y);
	int l=0,r=2*(n+m),mid;
	while (r-l>1)
		if (ok(mid=(l+r)>>1))  r=mid;  else  l=mid;
	printf("%d",r);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
