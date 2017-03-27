#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define pb  push_back
using namespace std;

typedef int  arr[1010];

struct node{int t,id;};
int na,nb,m,tot,ans,color[100010];
arr da,db,lmat,rmat,vis,a;
vector <node> e[1010];

bool cmpb(node x,node y){return db[x.t]>db[y.t];}
bool cmpa(int x,int y){return da[x]>da[y];}

bool dfs(int x)
{
	if (vis[x]==tot)  return 0;
	vis[x]=tot;
	for (int i=0,y; i<e[x].size(); i++)
		{
			y=e[x][i].t;
			if ((!rmat[y])||(dfs(rmat[y])))  {lmat[x]=y,rmat[y]=x;  return 1;}
		}
	return 0;
}

void work()
{
	scanf("%d %d %d",&na,&nb,&m);
	if (m==0)  {printf("0");  return;}
	for (int i=1,s,t; i<=m; i++)
		scanf("%d %d",&s,&t),e[s].pb((node){t,i}),da[s]++,db[t]++;
	for (int i=1; i<=na; i++)
		sort(e[i].begin(),e[i].end(),cmpb),a[i]=i;
	sort(a+1,a+na+1,cmpa);
	for (int t=m; ; )
		{
			ans++;
			memset(lmat,0,sizeof(lmat)),memset(rmat,0,sizeof(rmat));
			for (int i=1; i<=na; i++)
				if (tot++,dfs(a[i]))  t--;
			for (int i=1; i<=na; i++)
				for (int j=0; j<e[a[i]].size(); j++)
					if (lmat[a[i]]==e[a[i]][j].t)
						{color[e[a[i]][j].id]=ans,e[a[i]].erase(e[a[i]].begin()+j);  break;}
			if (!t)  break;
		}
	printf("%d\n",ans);
	for (int i=1; i<=m; i++)  printf("%d ",color[i]);
}

int main()
{
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
	work();
	return 0;
}
