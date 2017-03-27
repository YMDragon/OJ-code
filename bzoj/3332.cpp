#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct edge{int s,t,n;}e[300010],E[2010];
int n,m,f[1010][1010],h[1010],ufs[1010],tmp[2][1010];

int gi()
{
	int w=0,q=1;  char ch=getchar();
	while (((ch<'0')||('9'<ch))&&(ch!='-'))  ch=getchar();
	if (ch=='-')  q=0,ch=getchar();
	while (('0'<=ch)&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return q?w:-w;
}

bool cmp(edge x,edge y){return x.n>y.n;}
int find(int x){return ufs[x]==x?x:ufs[x]=find(ufs[x]);}

void dfs(int x,int ty)
{
	tmp[ty][++tmp[ty][0]]=x;
	for (int i=h[x]; i; i=e[i].n)  dfs(e[i].t,ty);
}

bool work()
{
	n=gi(),m=gi();
	for (int i=1; i<=m; i++)  e[i]=(edge){gi(),gi(),0};
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			f[i][j]=gi();
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			if (f[i][j]!=f[j][i])
				return 0;
	for (int i=1; i<=m; i++)  e[i].n=f[e[i].s][e[i].t];
	sort(e+1,e+m+1,cmp);
	for (int i=1; i<=n; i++)  h[i]=0,ufs[i]=i;
	for (int i=1,x,y,tot=0; i<=m; i++)
		if ((x=find(e[i].s))!=(y=find(e[i].t)))
			{
				tmp[0][0]=tmp[1][0]=0;
				dfs(x,0),dfs(y,1);
				for (int j=1; j<=tmp[0][0]; j++)
					for (int k=1; k<=tmp[1][0]; k++)
						if (f[tmp[0][j]][tmp[1][k]]!=e[i].n)
							return 0;
				e[++tot]=(edge){x,y,h[x]},h[x]=tot;
				ufs[y]=x;
			}
	for (int i=1; i<=n; i++)
		if (ufs[i]==i)
			for (int j=i+1; j<=n; j++)
				if (ufs[j]==j)
					{
						tmp[0][0]=tmp[1][0]=0;
						dfs(i,0),dfs(j,1);
						for (int k=1; k<=tmp[0][0]; k++)
							for (int l=1; l<=tmp[1][0]; l++)
								if (f[tmp[0][k]][tmp[1][l]]!=-1)
									return 0;
					}			
	return 1;
}

int main()
{
	freopen("3332.in","r",stdin);
	freopen("3332.out","w",stdout);
	int t;
	scanf("%d",&t);
	for (int i=1; i<=t; i++)
		printf("Case #%d: %s\n",i,work()?"Yes":"No");
	return 0;
}
