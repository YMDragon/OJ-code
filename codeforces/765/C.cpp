#include <bits/stdc++.h>
using namespace std;

int k,a,b,A,B,ans;

void work()
{
	scanf("%d %d %d",&k,&a,&b);
	A=a/k,B=b/k,a%=k,b%=k;
	if ((a)&&(!B))  {puts("-1");  return;}
	if ((b)&&(!A))  {puts("-1");  return;}
	printf("%d\n",A+B);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
