#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
struct edge{int u,v,d,b,s;}e[500010];
struct query{int t,a,b;}q[500010];
int n,m,tot,ufs[300010],siz[300010];
LL ans;

int getint()
{
	int w=0;  char ch=getchar();
	while ((ch<'0')||(ch>'9'))  ch=getchar();
	while ((ch>='0')&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return w;
}

int find(int x){return (ufs[x]==x)?x:find(ufs[x]);}
void updsiz(int x,int y){siz[x]-=y;  if (ufs[x]!=x)  updsiz(ufs[x],y);}

void work()
{
	scanf("%d %d\n",&n,&m);
	for (int i=1; i<=n; i++)  ufs[i]=i,siz[i]=1;
	for (int i=1; i<=m; i++)
		{
			char ch;
			do  ch=getchar();  while ((ch!='A')&&(ch!='D')&&(ch!='R'));
			if (ch=='A')  q[i]=(query){1,getint(),getint()};
			if (ch=='D')  q[i]=(query){2,getint(),0};
			if (ch=='R')  q[i].t=3;
		}
	for (int i=1,tag; i<=m; i++)
		{
			tag=1;
			if (q[i].t==1)
				{
					int u=q[i].a,v=q[i].b;
					e[++tot]=(edge){u,v,i,0,e[tot-1].s};
					if ((u=find(u))!=(v=find(v)))
						{
							e[tot].b++,e[tot].s++,e[tot].u=u,e[tot].v=v;
							if (siz[u]<siz[v])  swap(u,v);
							ufs[v]=u,siz[u]+=siz[v];
							n--,ans+=i;
						}
					if (q[i+1].t==3)  q[i+1]=(query){2,1,0};
				}
			if (q[i].t==2)
				{
					int k=q[i].a;
					if (q[i+1].t==3)
						tag=(e[tot].s==e[tot-k].s);
					else
						for (int j=1; j<=k; j++)
							{
								if (e[tot].b)
									{
										n++,ans-=e[tot].d;
										if (siz[e[tot].u]<siz[e[tot].v])  swap(e[tot].u,e[tot].v);
										ufs[e[tot].v]=e[tot].v,updsiz(e[tot].u,siz[e[tot].v]);
									}
								tot--;
							}
						
				}
			printf("%lld\n",ans*(n==1)*tag);
		}
}

int main()
{
	freopen("14.in","r",stdin);
	freopen("14.out","w",stdout);
	work();
	return 0;
}
