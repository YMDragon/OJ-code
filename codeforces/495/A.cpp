#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,x,y,a[10]={2,7,2,3,3,4,2,5,1,2};

void work()
{
	scanf("%d",&n);
	x=n/10,y=n%10;
	printf("%d",a[x]*a[y]);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
