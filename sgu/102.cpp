#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,ans=0;

int gcd(int a,int b){return b?gcd(b,a%b):a;}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		if (gcd(i,n)==1)  ans++;
	printf("%d",ans);
}

int main()
{
	freopen("102.in","r",stdin);
	freopen("102.out","w",stdout);
	work();
	return 0;
}
