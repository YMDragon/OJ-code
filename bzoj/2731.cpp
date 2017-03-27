#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct sjx{int x1,x2,y,l,r;}a[10010];
const int m=2000000;
int n,w[m+10],tot,ltot,last;
double ans;

bool cmp(sjx x,sjx y){return x.y<y.y;}

void work()
{
	scanf("%d",&n);
	for (int i=1,d; i<=n; i++)
		{
			scanf("%d %d %d",&a[i].x1,&a[i].y,&d);
			a[i].x2=a[i].x1+d;
		}
	sort(a+1,a+n+1,cmp);
	for (int h=0,q=1,t; ltot=tot,h<=m; h++)
		{
			for (int i=a[0].r; i; i=a[i].r)
				{
					a[i].x2--;
					w[a[i].x2]--;
					if (w[a[i].x2]==0)  tot--;
					if (a[i].x1==a[i].x2)
						{
							last=(last==i)?a[i].l:last,a[a[i].l].r=a[i].r,a[a[i].r].l=a[i].l;
							t=a[i].l,a[i].l=a[i].r=0,i=t;
						}
				}
			ans+=tot+ltot;
			while ((q<=n)&&(a[q].y==h))
				{
					if (a[q].x1==a[q].x2)  {q++;  continue;}
					a[last].r=q,a[q].l=last,last=q;
					for (int i=a[q].x1; i<a[q].x2; i++)
						{
							if (w[i]==0)  tot++;
							w[i]++;
						}
					q++;
				}
		}
	printf("%.1lf",ans/2);
}

int main()
{
	freopen("2731.in","r",stdin);
	freopen("2731.out","w",stdout);
	work();
	return 0;
}
