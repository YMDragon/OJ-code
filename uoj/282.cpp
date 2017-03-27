#include <bits/stdc++.h>
using namespace std;

int n;

void work()
{
	scanf("%d",&n);
	puts(n<=3?"1":"-1");
}

int main()
{
	freopen("282.in","r",stdin);
	freopen("282.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
