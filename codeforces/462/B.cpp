#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int n,k,a[26];
LL ans;

bool cmp(int x,int y){return x>y;}

void work()
{
	scanf("%d %d",&n,&k);
	for (int i=1; i<=n; i++)
		{
			char ch=getchar();
			while ((ch<'A')||('Z'<ch))  ch=getchar();
			a[ch-'A']++;
		}
	sort(a,a+26,cmp);
	for (int i=0; i<26&&k>0; i++)
		{
			int t=min(k,a[i]);
			ans+=1LL*t*t,k-=t;
		}
	printf("%I64d",ans);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
