#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int a,b,ans1,ans2;

void work()
{
	scanf("%d %d",&a,&b);
	ans1=min(a,b),ans2=((a+b)-2*ans1)/2;
	printf("%d %d",ans1,ans2);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
