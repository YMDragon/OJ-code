#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

typedef int  arr[100010];
struct edge{int s,t,n;}e[200010];
struct node{int ch[2],siz,tag;}t[3000010];
int n,tot;
arr a,h,f,sg,rt;
vector <int> ans;

void dfs(int x,int fa,int F)
{
	f[x]=fa;
	for (int i=h[x]; i; i=e[i].n)
		if (e[i].t!=F)  dfs(e[i].t,a[x]?fa:x,x);
}

void push_down(int x,int k)
{
	if (t[x].tag)
		{
			if (t[x].tag&(1<<(k-1)))  swap(t[x].ch[0],t[x].ch[1]);
			t[t[x].ch[0]].tag^=t[x].tag,t[t[x].ch[1]].tag^=t[x].tag;
			t[x].tag=0;
		}
}

void insert(int &n,int x,int k)
{
	if (!n)  n=++tot;
	if (!k)  {t[n].siz=1;  return;}
	if (x&(1<<(k-1)))  insert(t[n].ch[1],x,k-1);
	else  insert(t[n].ch[0],x,k-1);
	t[n].siz=t[t[n].ch[0]].siz+t[t[n].ch[1]].siz;
}

 void merge(int &x,int y,int k)
{
	if (!k)  return;
	push_down(x,k),push_down(y,k);
	for (int i=0; i<=1; i++)
		if (t[y].ch[i])
			{
				if (t[x].ch[i])  merge(t[x].ch[i],t[y].ch[i],k-1);
				else  t[x].ch[i]=t[y].ch[i];
			}
	t[x].siz=t[t[x].ch[0]].siz+t[t[x].ch[1]].siz;
}

int mex(int x,int k)
{
	if ((!k)||(!x))  return 0;
	if (t[t[x].ch[0]].siz!=(1<<(k-1)))  return mex(t[x].ch[0],k-1);
	else  return mex(t[x].ch[1],k-1)+(1<<(k-1));
}

void getsg(int x)
{
	int sum=0;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)  getsg(y),sum^=sg[y];
	insert(rt[x],sum,20);
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		{
			t[rt[y]].tag^=sum^sg[y];
			merge(rt[x],rt[y],20);
		}
	sg[x]=mex(rt[x],20);
}

void dfs(int x,int sum)
{
	sum^=sg[x];
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)  sum^=sg[y];
	if (sum==0)  ans.push_back(x);
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)  dfs(y,sum);
}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for (int i=1,u,v,tot=0; i<n; i++)
		{
			scanf("%d %d",&u,&v);
			e[++tot]=(edge){u,v,h[u]},h[u]=tot;
			e[++tot]=(edge){v,u,h[v]},h[v]=tot;
		}
	dfs(1,0,0);
	for (int i=1; i<=n; i++)  h[i]=0;
	for (int i=1,tot=0; i<=n; i++)
		if ((!a[i])&&(f[i]))
			e[++tot]=(edge){f[i],i,h[f[i]]},h[f[i]]=tot;
	int sum=0;
	for (int i=1; i<=n; i++)
		if ((!a[i])&&(!f[i]))
			getsg(i),sum^=sg[i];
	for (int i=1; i<=n; i++)
		if ((!a[i])&&(!f[i]))
			dfs(i,sum);
	if (!ans.size())  printf("-1");
	else
		{
			sort(ans.begin(),ans.end());
			for (int i=0; i<ans.size(); i++)
				printf("%d\n",ans[i]);
		}
}

int main()
{
	freopen("4134.in","r",stdin);
	freopen("4134.out","w",stdout);
	work();
	return 0;
}
