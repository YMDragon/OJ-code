#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#define Ls(n)  (n<<1)
#define Rs(n)  (Ls(n)+1)
using namespace std;

map <int,int> vis,ft;
vector <int> V[2000000];
int n;

struct node{
	int a[31];
	
	void clear(){memset(a,0,sizeof(a));}
	
	void insert(int x)
	{
		for (int i=30; i>=0; i--)
			if (x&(1<<i))
				{
					if (a[i])  x^=a[i];
					else  {a[i]=x;  break;}
				}
	}

	int query()
	{
		int res=0;
		for (int i=30; i>=0; i--)
			res=max(res,res^a[i]);
		return res;
	}
};

void modify(int n,int l,int r,int L,int R,int x)
{
	if ((L<=l)&&(r<=R))  V[n].push_back(x);
	else
		{
			int mid=(l+r)>>1;
			if (L<=mid)  modify(Ls(n),l,mid,L,R,x);
			if (mid<R)  modify(Rs(n),mid+1,r,L,R,x);
		}
}

void dfs(int n,int l,int r,node x)
{
	for (int i=0; i<V[n].size(); i++)  x.insert(V[n][i]);
	if (l==r)  printf("%d\n",x.query());
	else
		{
			int mid=(l+r)>>1;
			dfs(Ls(n),l,mid,x),dfs(Rs(n),mid+1,r,x);
		}
}

void work()
{
	scanf("%d",&n);
	for (int i=1,x; i<=n; i++)
		{
			scanf("%d",&x);
			if (x>0)  {if (vis[x]==0)  ft[x]=i;  vis[x]++;}
			else  {vis[-x]--;  if (vis[-x]==0)  modify(1,1,n,ft[-x],i-1,-x);}
		}
	for (map <int,int>::iterator i=vis.begin(); i!=vis.end(); i++)
		if (i->second>0)  modify(1,1,n,ft[i->first],n,i->first);
	node x;
	x.clear();
	dfs(1,1,n,x);
}

int main()
{
	freopen("4184.in","r",stdin);
	freopen("4181.out","w",stdout);
	work();
	return 0;
}
