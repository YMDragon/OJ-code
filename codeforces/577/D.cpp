#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,p[100010],b[100010];

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&p[i]);
	for (int i=1; i<=n; i++)
		if (p[i]==i)
			{
				printf("YES\n");
				for (int j=1; j<=n; j++)
					if (i!=j)  printf("%d %d\n",i,j);
				return;
			}
	for (int i=1; i<=n; i++)
		if (p[p[i]]==i)
			{
				for (int j=1; j<=n; j++)
					if (!b[j])
						{
							int len=1,x=p[j];  b[j]=1;
							while (x!=j)  len++,x=p[x],b[x]=1;
							if (len&1)  {printf("NO");  return;}
						}
				printf("YES\n");
				printf("%d %d\n",i,p[i]),b[i]=0,b[p[i]]=0;
				for (int j=1; j<=n; j++)
					if (b[j])
						{
							int x=j;
							do{
								printf("%d %d\n",i,x);
								printf("%d %d\n",p[i],p[x]);
								b[x]=b[p[x]]=0,x=p[p[x]];
							}while (x!=j);
						}
				return;
			}
	printf("NO");
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
