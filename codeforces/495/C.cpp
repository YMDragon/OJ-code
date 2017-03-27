#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

char ch[100010];
int len,n,a,b;

void work()
{
	scanf("%s",ch+1),len=strlen(ch+1);
	for (int i=1; i<=len; i++)
		{
			if (a<0)  a=-(1<<30);
			if (ch[i]=='(')  a++;  else  {a--;  if (ch[i]=='#')  n++;}
		}
	for (int i=len; ch[i]!='#'; i--)
		{
			if (b<0)  b=-(1<<30);
			if (ch[i]=='(')  b--;  else  b++;
		}
	if ((a>=0)&&(b>=0))
		{

			for (int i=1; i<n; i++)  printf("1\n");
			printf("%d\n",1+a);
		}else  printf("-1");
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
