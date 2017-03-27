#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,x;
char ch[10];

void work()
{
	scanf("%d",&n);
	for (int i=1,t; i<=n; i++)
		{
			scanf("%d %s",&t,ch);
			if (ch[0]=='N')
				{
					if ((x-=t)<0)  printf("NO"),exit(0);
				}else  if (ch[0]=='S')
				{
					if ((x+=t)>20000)  printf("NO"),exit(0);
				}else
				if ((x==0)||(x==20000))  printf("NO"),exit(0);
		}
	if (x==0)  printf("YES");  else  printf("NO");
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
