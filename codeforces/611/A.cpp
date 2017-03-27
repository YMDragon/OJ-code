#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int x,month,day,xingqi,ans;
char ch[100],ch2[100];

void work()
{
	scanf("%d of %s\n",&x,ch+1);
	if (ch[strlen(ch+1)]=='k')
		{
			xingqi=5;
			for (int i=1; i<=366; i++)
				{
					if (xingqi==x)  ans++;
					xingqi%=7,xingqi++;
				}
		}else
		{
			if (x<=29)  ans=12;
			if (x==30)  ans=11;
			if (x==31)  ans=7;
		}
	printf("%d",ans);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
