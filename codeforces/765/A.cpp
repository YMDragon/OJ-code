#include <bits/stdc++.h>
using namespace std;

int n;
char S[4],ch[10];

void work()
{
	scanf("%d",&n);
	if (!(n&1))  puts("home");
	else  puts("contest");
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
