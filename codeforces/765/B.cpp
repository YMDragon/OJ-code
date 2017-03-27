#include <bits/stdc++.h>
using namespace std;

int n,p[26];
char ch[505];

void work()
{
	scanf("%s",ch),n=strlen(ch);
	for (int i=0,tot=0; i<n; i++)
		{
			if (!p[ch[i]-'a'])  p[ch[i]-'a']=++tot;
			if (ch[i]-'a'!=p[ch[i]-'a']-1)  {puts("NO");  return;}
		}
	puts("YES");
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
