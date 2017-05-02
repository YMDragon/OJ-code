#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,l,r,R,a[100010],b[100010],g[100010],q[100010];

void work()
{
	scanf("%d",&n),l=1,r=0,R=1;
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	b[n]=a[n],g[n]=n;
	for (int i=n-1; i; i--)
		if (a[i]<b[i+1])  b[i]=a[i],g[i]=i;
		else  b[i]=b[i+1],g[i]=g[i+1];
	while ((R<=n)||(l<=r))
		{
			if ((l>r)||((R<=n)&&(b[R]<q[l])&&(b[R]<q[r])))
				{
					printf("%d ",b[R]);
					for (int i=R; i<g[R]; i++)  q[++r]=a[i];
					R=g[R]+1;
				}else  if (q[l]<q[r])  printf("%d ",q[l++]);
			else  printf("%d ",q[r--]);
		}
	puts("");
}

int main()
{
	freopen("174.in","r",stdin);
	freopen("174.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
