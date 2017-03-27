#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int a,b,c,x,y,z;

void work()
{
	scanf("%d %d %d %d %d %d",&a,&b,&c,&x,&y,&z);
	a/=((a-=x)>0)+1,b/=((b-=y)>0)+1,c/=((c-=z)>0)+1;
	puts((a+b+c)>=0?"Yes":"No");
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
