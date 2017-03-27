#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,s,ans,t;

void work()
{
	scanf("%d %d",&n,&s);
	for (int i=1,x,y; i<=n; i++)
		{
			scanf("%d %d",&x,&y);
			if (x+(y>0)<=s)  ans=max(ans,y?100-y:0),t=1;
		}
	if (t)  printf("%d",ans);  else  printf("-1");
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
