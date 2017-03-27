#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,ans;
char s[100010];

void work()
{
	scanf("%d\n%s",&n,s+1);
	for (int i=1; i<=n; i++)  if (s[i]!=s[i+1])  ans++;
	printf("%d",min(n,ans+2));
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
