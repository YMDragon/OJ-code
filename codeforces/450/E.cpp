#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define LL  long long
#define oo  (1<<30)
using namespace std;

const int N=100000;
int n,m,prime[N+10],b[N+10],c[N+10],ans;

void pack(int x,int y){b[x]=y,b[y]=x,ans++;}

void work()
{
	scanf("%d",&n);
	for (int i=2; i<=n/2; i++)
		{
			if (!b[i])  prime[++m]=i;
			for (int j=1; j<=m&&i*prime[j]<=n/2; j++)
				{
					b[i*prime[j]]=1;
					if (i%prime[j]==0)  break;
				}
		}
	memset(b,0,sizeof(b));
	for (int i=m; i>=1; i--)
		{
			int cnt=0,x=prime[i];
			for (int j=x; j<=n; j+=x)
				if (!b[j])  c[++cnt]=j;
			if (cnt&1)
				{
					pack(c[1],c[3]);
					for (int j=4; j<=cnt; j+=2)
						pack(c[j],c[j+1]);
				}else
				for (int j=1; j<=cnt; j+=2)
					pack(c[j],c[j+1]);
		}
	printf("%d\n",ans);
	for (int i=1; i<=n; i++)
		if (i<b[i])  printf("%d %d\n",i,b[i]);
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
