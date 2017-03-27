#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

char a[6][4]={{'j','o','l','t'},{'f','l','a','r'},{'u','m','b','r'}
							,{'l','e','a','f'},{'g','l','a','c'},{'s','y','l','v'}};
int n,b[6];

void work()
{
	scanf("%d\n",&n);
	if (n==6)  {printf("espeon");  return;}
	if (n==8)  {printf("vaporeon");  return;}
	for (int i=0; i<6; i++)  b[i]=1;
	for (int i=0; i<4; i++)
		{
			char ch=getchar();
			while (((ch<'a')||(ch>'z'))&&(ch!='.'))  ch=getchar();
			if (ch=='.')  continue;
			for (int j=0; j<6; j++)
				b[j]&=(ch==a[j][i]);
		}
	for (int i=0; i<6; i++)
		if (b[i])
			for (int j=0; j<4; j++)
				printf("%c",a[i][j]);
	printf("eon");
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
