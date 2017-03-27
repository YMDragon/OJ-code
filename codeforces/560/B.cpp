#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,a1,b1,a2,b2;

bool h(int a1,int b1,int a2,int b2)
{
	int a=a1+a2,b=max(b1,b2);
	return (a<=n)&&(b<=m);
}

bool s(int a1,int b1,int a2,int b2)
{
	int a=max(a1,a2),b=b1+b2;
	return (a<=n)&&(b<=m);
}

void work()
{
	scanf("%d %d %d %d %d %d",&n,&m,&a1,&b1,&a2,&b2);
	if ((h(a1,b1,a2,b2))||(s(a1,b1,a2,b2)))  {printf("YES");  return;}
	if ((h(a1,b1,b2,a2))||(s(a1,b1,b2,a2)))  {printf("YES");  return;}
	if ((h(b1,a1,a2,b2))||(s(b1,a1,a2,b2)))  {printf("YES");  return;}
	if ((h(b1,a1,b2,a2))||(s(b1,a1,b2,a2)))  {printf("YES");  return;}
	printf("NO");
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
