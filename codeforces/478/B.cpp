#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m;

void work()
{
	scanf("%d %d",&n,&m);
	int x=n%m,y=n/m;
	cout<<1LL*x*(y+1)*y/2+1LL*(m-x)*y*(y-1)/2<<' '<<1LL*(n-m+1)*(n-m)/2;
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
