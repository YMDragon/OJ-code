#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,a[100010],b[100010],ans;

void upd(int x,int s)
{
	a[x]++,b[x]+=s;
}

void up(int x,int s)
{
	for (; x<=100000; x<<=1,s++)
		upd(x,s);
}

void work()
{
	scanf("%d",&n);
	for (int i=1,x,t,tag; i<=n; i++)
		{
			scanf("%d",&x);
			up(x,0),t=0;
			while (x>1)
				{
					tag=x&1,x>>=1,t++;
					if (tag)  up(x,t);  else  upd(x,t);
				}
		}
	ans=1<<30;
	for (int i=1; i<=100000; i++)
		if (a[i]==n)  ans=min(ans,b[i]);
	printf("%d",ans);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;											
}
