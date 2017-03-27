#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define LL  long long
#define oo  (1<<30)
using namespace std;

int n,m;

void work()
{
	scanf("%d %d",&n,&m);
	if (min(n,m)&1)  printf("Akshat");  else  printf("Malvika");
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
