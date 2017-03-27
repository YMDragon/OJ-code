#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,a[30],b[30];
char s[200010];

void work()
{
	scanf("%s",s+1),n=strlen(s+1);
	for (int i=1; i<=n; i++)  a[s[i]-'a']++;
	for (int i=0; i<26; i++)  if (a[i]&1)  b[++m]=i;
	for (int i=1,j=m; i<j; i++,j--)  a[b[i]]++,a[b[j]]--;
	int t=(m&1)?b[m/2+1]:-1;
	for (int i=0; i<26; i++)
		for (int j=1; j<=a[i]/2; j++)
			putchar(i+'a');
	if (t!=-1)  putchar(t+'a');
	for (int i=25; i>=0; i--)
		for (int j=1; j<=a[i]/2; j++)
			putchar(i+'a');
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
