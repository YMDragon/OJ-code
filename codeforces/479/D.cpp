#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,l,x,y,a[100010],b[200010],c[200010];

int find(int x)
{
	for (int i=1; i<=n; i++)  b[i]=a[i],b[i+n]=a[i]+x;
	sort(b+1,b+2*n+1);
	for (int i=1; i<2*n; i++)
		if (b[i]==b[i+1])  return 1;
	return 0;
}

void work()
{
	scanf("%d %d %d %d",&n,&l,&x,&y);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	int X=find(x),Y=find(y);
	if ((X)&&(Y))  printf("0");
	else  if ((!X)&&(!Y))
		{
			int tot1=0,tot2=0;
			for (int i=1; i<=n; i++)
				{
					if (a[i]-x>=0)  b[++tot1]=a[i]-x;
					if (a[i]+x<=l)  b[++tot1]=a[i]+x;
				}
			b[++tot1]=x;
			for (int i=1; i<=n; i++)
				{
					if (a[i]-y>=0)  c[++tot2]=a[i]-y;
					if (a[i]+y<=l)  c[++tot2]=a[i]+y;
				}
			c[++tot2]=y;
			sort(b+1,b+tot1+1),sort(c+1,c+tot2+1);
			for (int i=1,j=1; i<=tot1; i++)
				{
					while ((b[i]>c[j])&&(j<=tot2))  j++;
					if (b[i]==c[j])  {printf("1\n%d",b[i]);  return;}
				}
			printf("2\n%d %d",x,y);
		}
	else
		{
			if (X)  swap(x,y);
			printf("1\n%d",x);
		}
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
