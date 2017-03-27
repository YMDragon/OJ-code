#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,t,x;
char ch1[100010],ch2[100010];

char isnot(char x,char y)
{
	if ((x!='a')&&(y!='a'))  return 'a';
	if ((x!='b')&&(y!='b'))  return 'b';
	return 'c';
}

void work()
{
	scanf("%d %d\n%s\n%s",&n,&t,ch1+1,ch2+1);
	for (int i=1; i<=n; i++)  x+=(ch1[i]!=ch2[i]);
	if (x>2*t)  {printf("-1");  return;}
	if (x>=t)
		{
			for (int i=1,p=0; i<=n; i++)
				if (ch1[i]==ch2[i])  putchar(ch1[i]);
				else
					{
						p++;
						if (p<=x-t)  putchar(ch1[i]);
						else  if (p<=2*(x-t))  putchar(ch2[i]);
						else  putchar(isnot(ch1[i],ch2[i]));
					}
		}else
		{
			for (int i=1,p=0; i<=n; i++)
				if (ch1[i]==ch2[i])
					{
						p++;
						if (p<=t-x)  putchar(isnot(ch1[i],ch2[i]));
						else  putchar(ch1[i]);
					}else  putchar(isnot(ch1[i],ch2[i]));
		}
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
