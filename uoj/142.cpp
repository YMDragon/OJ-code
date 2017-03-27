#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

int n,m,k,a[400010],pre[400010],ans;
queue <int> Q;

void add(int x,int y)
{
	if ((a[x]==-1)||((y!=-1)&&(pre[y]==x)))  return;
	if (a[x]==1)  ans=0;
	if (a[x]==0)  Q.push(x),pre[x]=y,a[x]=1;
}

void bfs(int s)
{
	while (!Q.empty())  Q.pop();
	add(s,-1);
	while ((!Q.empty())&&(ans))
		{
			int p=Q.front(),x=p/m+1,y=p%m+1;  Q.pop();
			if (x!=1)  add(p-m,p);
			if (x!=n)  add(p+m,p);
			if (y!=1)  add(p-1,p);  else  add(p+m-1,p);
			if (y!=m)  add(p+1,p);  else  add(p-m+1,p);
		}
}

void work()
{
	scanf("%d %d %d",&n,&m,&k);
	if (1LL*n*m>4*k)
		{
			for (int i=1,x,y; i<=k; i++)  scanf("%d %d",&x,&y);
			printf("No\n");
			return;
		}
	memset(a,0,sizeof(a)),memset(pre,0,sizeof(pre));
	for (int i=1,x,y; i<=k; i++)
		scanf("%d %d",&x,&y),a[(x-1)*m+y-1]=-1;
	ans=1;
	for (int i=0,tag=1; i<n*m&&ans; i++)
		if (!a[i])
			{
				if (tag)  bfs(i),tag=0;
				else  ans=0;
			}
	puts(ans?"Yes":"No");
}

int main()
{
	freopen("142.in","r",stdin);
	freopen("142.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
