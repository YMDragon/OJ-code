#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct node{int x,ls,rs;}t[1024];
int n,k,root[55],tot,ans;

int insert(int &x,int k)
{
	if (x==0)  return t[x=++tot].x=k,x;
	if (k<t[x].x)  t[x].ls=insert(t[x].ls,k);
	else  t[x].rs=insert(t[x].rs,k);
	return x;
}

bool same(int x,int y)
{
	if ((x*y==0)&&(x+y!=0))  return 0;
	if ((x==0)&&(y==0))  return 1;
	return same(t[x].ls,t[y].ls)&same(t[x].rs,t[y].rs);
}

void work()
{
	scanf("%d %d",&n,&k);
	for (int i=1,ok; i<=n; i++)
		{
			for (int j=1,x; j<=k; j++)
				scanf("%d",&x),insert(root[i],x);
			ok=1;
			for (int j=1; j<i; j++)
				if (same(root[i],root[j]))
					ok=0;
			ans+=ok;
		}
	printf("%d",ans);
}

int main()
{
	freopen("4610.in","r",stdin);
	freopen("4610.out","w",stdout);
	work();
	return 0;
}
