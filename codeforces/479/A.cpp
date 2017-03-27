#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int a,b,c;

void work()
{
	scanf("%d %d %d",&a,&b,&c);
	printf("%d",max(max(a+b+c,a*b*c),max(a*(b+c),(a+b)*c)));
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
