#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n;
char ch[1010],ans[1010];

void work()
{
	scanf("%d\n%s",&n,ch);
	for (int i=0; i<n; i++)  ans[i]=ch[i];
	for (int i=0; i<n; i++)
		{
			while (ch[0]!='0')
				for (int j=0; j<n; j++)
					ch[j]=(ch[j]-48+1)%10+48;
			for (int j=0,flag=0; j<n; j++)
				if (flag)  ans[j]=ch[j];
				else  if (ch[j]<ans[j])  ans[j]=ch[j],flag=1;
				else  if (ch[j]>ans[j])  break;
			char c=ch[0];
			for (int j=1; j<n; j++)  ch[j-1]=ch[j];
			ch[n-1]=c;
		}
	printf("%s",ans);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
