#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=int(1e9+7);
int p,k,vis[1000010],ans;

void work()
{
	scanf("%d %d",&p,&k),ans=1;
	for (int i=1; i<p; i++)
		if (!vis[i])
			{
				ans=1LL*ans*p%mo;
				int x=i;
				while ((!vis[x])&&(x))
					vis[x]=1,x=1LL*x*k%p;
			}
	if (k==1)  ans=1LL*ans*p%mo;
	printf("%d",ans);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
