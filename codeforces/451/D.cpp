#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;

char ch[100010];
LL n,f[2][2],ans[2];

void work()
{
	scanf("%s",ch+1),n=strlen(ch+1);
	for (int i=1; i<=n; i++)
		f[ch[i]-'a'][i&1]++;
	for (int i=1; i<=n; i++)
		{
			int x=ch[i]-'a';
			ans[0]+=f[x][0],ans[1]+=f[x][1];
			f[x][1]--;
			swap(f[0][0],f[0][1]),swap(f[1][0],f[1][1]);
		}
	printf("%lld %lld",ans[0],ans[1]);
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
} 
