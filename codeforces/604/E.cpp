#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,k,ans;

int mex(int x,int y)
{
	if ((x!=0)&&(y!=0))  return 0;
	if ((x!=1)&&(y!=1))  return 1;
	if ((x!=2)&&(y!=2))  return 2;
	return 3;
}

int sg1(int x)
{
	if (x&1)  return (x<=3);
	else  return mex(sg1(x-1),sg1(x/2));
}

int sg2(int x)
{
	if (x<=2)  return x;
	else  return (!(x&1));
}

void work()
{
	scanf("%d %d",&n,&k),k&=1;
	for (int i=1,x; i<=n; i++)  scanf("%d",&x),ans^=k?sg1(x):sg2(x);
	puts(ans?"Kevin":"Nicky");
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
