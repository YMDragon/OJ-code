#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,f[100010],g[100010],siz[100010];

int find(int x)
{
	if (f[x]==x)  return x;
	int t=find(f[x]);
	g[x]+=g[f[x]],f[x]=t;
	return t;
}

int get(int x)
{
	find(x);
	return g[x];
}

bool work()
{
	scanf("%d %d",&n,&m);
	if ((n==0)&&(m==0))  return 0;
	for (int i=1; i<=n; i++)
		f[i]=i,g[i]=0,siz[i]=1;
	for (int i=1,x,y,w,fx,fy,gx,gy; i<=m; i++)
		{
			char ch;
			scanf("\n%c %d %d",&ch,&x,&y);
			if (ch=='!')
				{
					scanf("%d",&w);
					if ((fx=find(x))!=(fy=find(y)))
						{
							if (siz[fx]<siz[fy])  swap(x,y),swap(fx,fy),w*=-1;
							gx=get(x),gy=get(y);
							f[fy]=fx,g[fy]=-gy-w+gx,siz[fx]+=siz[fy];
						}
				}else
				{
					if ((fx=find(x))==(fy=find(y)))
						{
							gx=get(x),gy=get(y);
							printf("%d\n",gx-gy);
						}else  puts("UNKNOWN");
				}
		}
	return 1;
}

int main()
{
	freopen("4690.in","r",stdin);
	freopen("4690.out","w",stdout);
	while (work())  ;
	return 0;
}
