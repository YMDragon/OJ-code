#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int k,ans[515][515];

void solve(int xl,int xr,int yl,int yr,int p)
{
	if (xl==xr)  {ans[xl][yl]=p;  return;}
	int xmid=(xl+xr)>>1,ymid=(yl+yr)>>1;
	solve(xl,xmid,yl,ymid,p),solve(xl,xmid,ymid+1,yr,p);
	solve(xmid+1,xr,yl,ymid,p),solve(xmid+1,xr,ymid+1,yr,-p);
}

void work()
{
	scanf("%d",&k);
	solve(1,1<<k,1,1<<k,1);
	for (int i=1; i<=(1<<k); i++)
		{
			for (int j=1; j<=(1<<k); j++)
				putchar(ans[i][j]==1?'+':'*');
			puts("");
		}
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
