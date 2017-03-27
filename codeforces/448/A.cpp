#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define LL  long long
#define oo  (1<<30)
using namespace std;

int a,b,n;

void work()
{
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z),a=(x+y+z+4)/5;
	scanf("%d %d %d",&x,&y,&z),b=(x+y+z+9)/10;
	scanf("%d",&n);
	if (n>=a+b)  printf("YES");  else  printf("NO");
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
