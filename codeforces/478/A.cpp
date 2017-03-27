#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int sum;

void work()
{
	for (int i=1,x; i<=5; i++)  scanf("%d",&x),sum+=x;
	printf("%d",(sum%5==0)&&(sum>0)?sum/5:-1);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
