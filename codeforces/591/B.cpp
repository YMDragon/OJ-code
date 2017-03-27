#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,a[26],b[26];
char ch[200010];

void work()
{
	scanf("%d %d\n",&n,&m);
	scanf("%s\n",ch+1);
	for (int i=0; i<26; i++)  a[i]=b[i]=i;
	for (int i=1; i<=m; i++)
		{
			char ch1,ch2;
			scanf("%c %c\n",&ch1,&ch2);
			swap(a[b[ch1-'a']],a[b[ch2-'a']]),swap(b[ch1-'a'],b[ch2-'a']);
		}
	for (int i=1; i<=n; i++)  printf("%c",a[ch[i]-'a']+'a');
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
