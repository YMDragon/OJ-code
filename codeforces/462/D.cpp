#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=1000000007;
int n,p[100010],x[100010],f[100010][2];

void work()
{
	scanf("%d",&n);
	for (int i=2; i<=n; i++)  scanf("%d",&p[i]),p[i]++;
	for (int i=1; i<=n; i++)  scanf("%d",&x[i]),f[i][x[i]]=1;
	for (int i=n; i>1; i--)
		{
			f[p[i]][1]=(1LL*f[p[i]][1]*(f[i][0]+f[i][1])+1LL*f[p[i]][0]*f[i][1])%mo;
			f[p[i]][0]=(1LL*f[p[i]][0]*(f[i][0]+f[i][1]))%mo;
		}
	printf("%d",f[1][1]);
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
} 
