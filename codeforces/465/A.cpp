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
	for (int i=1; i<=n; i++)
		{
			char ch=getchar();
			while ((ch!='0')&&(ch!='1'))  ch=getchar();
			if (ch=='0')  {printf("%d",i);  return;}
		}
	printf("%d",n);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
