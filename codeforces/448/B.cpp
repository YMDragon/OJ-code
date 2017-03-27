#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define LL  long long
#define oo  (1<<30)
using namespace std;

char s[100010],t[100010];
int n,m,a[26];

void work()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	for (int i=1,j=1; i<=n; i++)
		{
			if ((j<=m)&&(s[i]==t[j]))  j++;
			if (j>m)  {printf("automaton");  return;}
		}
	for (int i=1; i<=n; i++)  a[s[i]-'a']++;
	for (int i=1; i<=m; i++)  a[t[i]-'a']--;
	int k=2;
	for (int i=0; i<26&&k; i++)
		if (a[i]<0)  k=0;  else  if (a[i]>0)  k=1;
	if (k==2)  printf("array");
	if (k==1)  printf("both");
	if (k==0)  printf("need tree");
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
