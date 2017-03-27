#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	freopen("1192.in","r",stdin);
	freopen("1192.out","w",stdout);
	int n,ans;
	scanf("%d",&n);
	ans=int(log2(n))+1;
	printf("%d",ans);
	return 0;
} 
