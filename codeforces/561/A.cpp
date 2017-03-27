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
	if (n==1)  putchar('B');
	if (n==2)  putchar('D');
	if (n==3)  putchar('B');
	if (n==4)  putchar('D');
	if (n==5)  putchar('E');
	if (n==6)  putchar('B');
	if (n==7)  putchar('C');
	if (n==8)  putchar('C');
	if (n==9)  putchar('E');
	if (n==10)  putchar('D');
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
