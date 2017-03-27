#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define NO  printf("NO"),exit(0)
using namespace std;

struct edge{int s,t,d,n;}e[2000000],E[4010];
int n,tot,a[2010][2010],bcj[2010],h[2010];

bool cmp(edge x,edge y){return x.d<y.d;}
int find(int x){return bcj[x]=(bcj[x]!=x?find(bcj[x]):x);}

int getint()
{
	int w=0,q=1;  char ch=getchar();
	while (((ch<'0')||(ch>'9'))&&(ch!='-'))  ch=getchar();
	if (ch=='-')  q=0,ch=getchar();
	while ((ch>='0')&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return q?w:-w;
}

void dfs(int s,int x,int f,int d)
{
	if (a[s][x]!=d)  NO;
	for (int i=h[x],y; y=E[i].t,i; i=E[i].n)
		if (y!=f)  dfs(s,y,x,d+E[i].d);
}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			a[i][j]=getint();
	for (int i=1; i<=n; i++)
		{
			if (a[i][i])  NO;
			for (int j=i+1; j<=n; j++)
				{
					if ((a[i][j]!=a[j][i])||(!a[i][j]))  NO;
					e[++tot]=(edge){i,j,a[i][j],0};
				}
			bcj[i]=i;
		}
	sort(e+1,e+tot+1,cmp);
	for (int i=1,x,y,cnt=0; i<=tot; i++)
		if ((x=find(e[i].s))!=(y=find(e[i].t)))
			{
				bcj[y]=x;
				E[++cnt]=(edge){e[i].s,e[i].t,e[i].d,h[e[i].s]},h[e[i].s]=cnt;
				E[++cnt]=(edge){e[i].t,e[i].s,e[i].d,h[e[i].t]},h[e[i].t]=cnt;
			}
	for (int i=1; i<=n; i++)
		dfs(i,i,0,0);
	printf("YES");
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
