#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define LL  long long
#define oo  (1<<30)
using namespace std;

int n,a[5010];

int f(int s,int t,int c)
{
	if (s>t)  return 0;
	int Min=t;
	for (int i=s; i<t; i++)
		if (a[i]<a[Min])  Min=i;
	return min(t-s+1,f(s,Min-1,a[Min])+f(Min+1,t,a[Min])+a[Min]-c);
}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	printf("%d",f(1,n,0));
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
} 
