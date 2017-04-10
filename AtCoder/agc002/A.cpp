#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int a,b;

void work()
{
	scanf("%d %d",&a,&b);
	if ((a<=0)&&(0<=b))  puts("Zero");
	else  if (a>0)  puts("Positive");
	else  puts(((a^b)&1)?"Positive":"Negative");
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
