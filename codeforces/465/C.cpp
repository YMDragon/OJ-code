#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,p;
char ch[1010];

void work()
{
	scanf("%d %d\n%s",&n,&p,ch+1);
	for (int i=n; i>=1; i--)
		for (int j=ch[i]+1; j<='a'+p-1; j++)
			if ((j!=ch[i-1])&&((i==1)||(j!=ch[i-2])))
				{
					ch[i]=j;
					for (int ii=i+1; ii<=n; ii++)
						for (ch[ii]='a'; ch[ii]<='a'+p-1; ch[ii]++)
							if ((ch[ii]!=ch[ii-1])&&(ch[ii]!=ch[ii-2]))  break;
					for (int ii=1; ii<=n; ii++)  printf("%c",ch[ii]);
					return;
				}
	printf("NO");
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
