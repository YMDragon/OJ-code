#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

const int oo=(1<<30);
struct point{int x,n;}p[5010];
struct edge{int s,t,n;}e[10010];
int h[5010],f[20],head[5010],vis[5010],match[5010];
int a,b,c,tot,ans;

void addedge(int x,int y)
{
	e[++tot]=(edge){x,y,head[x]},head[x]=tot;
}

int find(int x,int tim)
{
	for (int i=head[x],y; y=e[i].t,i; i=e[i].n)
		if (vis[y]!=tim)
			{
				vis[y]=tim;
				if ((!match[y])||(find(match[y],tim)))
					{match[y]=x;  return 1;}
			}
	return 0;
}

void dfs(int x,int res)
{
	if (res>=ans)  return;
	if (x>a)
		{
			memset(head,0,4*(b+1)),tot=0;
			for (int i=1; i<=b; i++)
				for (int j=1; j<=c; j++)
					for (int x=h[(i-1)*c+j]; x; x=p[x].n)
						if (!f[p[x].x])  {addedge(i,j);  break;}
			memset(match,0,4*(c+1)),memset(vis,0,4*(c+1));
			for (int i=1,tim=0; i<=b; i++)
				if ((res+=find(i,++tim))>=ans)  return;
			ans=res;
			return;
		}
	f[x]=0,dfs(x+1,res);
	f[x]=1,dfs(x+1,res+1);
}

void work()
{
	int x,tot=0;
	scanf("%d %d %d",&a,&b,&c);
	memset(h,0,sizeof(h));
	if ((a<=b)&&(a<=c))
		{
			for (int i=1; i<=a; i++)
				for (int j=1; j<=b; j++)
					for (int k=1; k<=c; k++)
						{
							scanf("%d",&x);
							if (x)  p[++tot]=(point){i,h[(j-1)*c+k]},h[(j-1)*c+k]=tot;
						}
		}else
		if ((b<=a)&&(b<=c))
			{
				swap(a,b);
				for (int i=1; i<=b; i++)
					for (int j=1; j<=a; j++)
						for (int k=1; k<=c; k++)
							{
								scanf("%d",&x);
								if (x)  p[++tot]=(point){j,h[(i-1)*c+k]},h[(i-1)*c+k]=tot;
							}
			}else
			{
				swap(a,c);
				for (int i=1; i<=c; i++)
					for (int j=1; j<=b; j++)
						for (int k=1; k<=a; k++)
							{
								scanf("%d",&x);
								if (x)  p[++tot]=(point){k,h[(j-1)*c+k]},h[(j-1)*c+k]=tot;
							}
			}
	ans=a;
	dfs(1,0);
	printf("%d\n",ans);
	cerr<<clock()<<endl;
}

int main()
{
	freopen("3140.in","r",stdin);
	freopen("3140.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
