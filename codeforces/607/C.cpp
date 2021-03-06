#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int seed=173,mo=int(1e9+7);
int n;
char a[1000010],b[1000010];

void work()
{
	scanf("%d\n%s\n%s",&n,a+1,b+1),n--;
	for (int i=1; i<=n; i++)
		if (a[i]=='N')  a[i]='S';
		else  if (a[i]=='S')  a[i]='N';
		else  if (a[i]=='E')  a[i]='W';
		else  a[i]='E';
	for (int i=n,hs1=0,hs2=0,p=1; i; i--)
		{
			hs1=(hs1+1LL*p*a[i])%mo,p=1LL*p*seed%mo;
			hs2=(1LL*hs2*seed+b[i])%mo;
			if (hs1==hs2)  {printf("NO");  return;}
		}
	printf("YES");
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
