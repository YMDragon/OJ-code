#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n;

void work()
{
	scanf("%d",&n);
	if (n%3==0)  printf("%d",n/3*2);
	if (n%3==1)  printf("%d",n/3*2);
	if (n%3==2)  printf("%d",n/3*2+1);
}

int main()
{
	freopen("105.in","r",stdin);
	freopen("105.out","w",stdout);
	work();
	return 0;
} 
