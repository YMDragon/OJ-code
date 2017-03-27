#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int k,n,w;

void work()
{
	scanf("%d %d %d",&k,&n,&w);
	printf("%d",max(0,w*(w+1)/2*k-n));
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
