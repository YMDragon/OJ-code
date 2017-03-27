#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
typedef unsigned long long  ULL;
const int mo[5]={0,73013,85669,97777,2147483647};

int n,m,ans,p[1000010],a[105][5],b[100010][5];
LL c[105];

void read(int &a,int &b,int &c,LL &d)
{
	int t=0;
	char ch=getchar();
	a=b=c=d=0;
	while (((ch<'0')||(ch>'9'))&&(ch!='-'))  ch=getchar();
	if (ch=='-')  t=1,ch=getchar();
	while ((ch>='0')&&(ch<='9'))
		a=(a*10+ch-'0')%mo[1],b=(b*10+ch-'0')%mo[2],c=(c*10+ch-'0')%mo[3],d=(d*10+ch-'0')%mo[4],ch=getchar();
	if (t)  a=mo[1]-a,b=mo[2]-b,c=mo[3]-c,d=mo[4]-d;
}

void work()
{
	scanf("%d %d\n",&n,&m);
	for (int i=0; i<=n; i++)
		read(a[i][1],a[i][2],a[i][3],c[i]);
	for (int j=1; j<=3; j++)
		for (int i=1; i<=mo[j]; i++)
			b[i][j]=1;
	for (int i=1,ok; ok=1,i<=m; i++)
		{
			for (int j=1; j<=3; j++)
				if (i<=mo[j])
					{
						LL x=a[n][j];
						for (int k=n-1; k>=0; k--)
							x=(x*i+a[k][j])%mo[j];
						if (x)  ok=0;
						b[i][j]=x;
					}else  ok&=(b[i%mo[j]][j]==0);
			if (ok)
				{
					ULL x=a[n][4];
					for (int k=n-1; k>=0; k--)
						{
							x=x*i+a[k][4];
							x=(x&mo[4])+(x>>31);
						}
					x%=mo[4];
					if (x)  ok=0;
				}
			if (ok)  p[++ans]=i;
		}
	printf("%d\n",ans);
	for (int i=1; i<=ans; i++)
		printf("%d\n",p[i]);
}

int main()
{
	freopen("20.in","r",stdin);
	freopen("20.out","w",stdout);
	work();
	return 0;
}
