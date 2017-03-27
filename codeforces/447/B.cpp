#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define LL  long long
#define oo  (1<<30)
using namespace std;

char ch[1010];
int k,w[30],len,ans,x;

void work()
{
	scanf("%s\n",ch+1),len=strlen(ch+1);
	scanf("%d",&k);
	for (int i=0; i<26; i++)  scanf("%d",&w[i]);
	for (int i=1; i<=len; i++)  ans+=i*w[ch[i]-'a'];
	x=w[0];
	for (int i=1; i<26; i++)  x=max(x,w[i]);
	ans+=(k*len+(1+k)*k/2)*x;
	printf("%d",ans);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
