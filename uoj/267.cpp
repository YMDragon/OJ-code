#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int n,m,N,a[10010];
LL x,y,c[1000010];

LL gL()
{
	LL w=0;  int q=1;  char ch=getchar();
	while (((ch<'0')||('9'<ch))&&(ch!='-'))  ch=getchar();
	if (ch=='-')  q=0,ch=getchar();
	while (('0'<=ch)&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return q?w:-w;
}

void pi(int x)
{
	if (x<0)  putchar('-'),x=-x;
	if (x>9)  pi(x/10);
	putchar(x%10+'0');
}

void work()
{
	n=gL();
	for (int i=0; i<n; i++)  a[i]=gL();
	m=gL();
	for (int i=0; i<m; i++)  c[i]=gL();
	x=y=1,a[n]=m;
	for (N=0; N<n; N++)
		if ((x*=a[N])>=m)
			break;
	swap(a[N],a[n]);
	for (int i=0; i<=N; i++)
		if (a[i]!=1)
			{
				for (int j=m-1,k=j/y%a[i],l=j%y; j>=0; j--,l--)
					{
						if (k)  c[j]-=c[j-y];
						if (l==0)  k=(k?k-1:a[i]-1),l=y;
					}
				y*=a[i];
			}
	swap(a[N],a[n]);
	pi(n),puts("");
	for (int i=0; i<n; i++)  pi(a[i]),putchar(' ');  puts("");
	pi(m),puts("");
	for (int i=0; i<m; i++)  pi(c[i]),putchar(' ');  puts("");
}

int main()
{
	freopen("267.in","r",stdin);
	freopen("267.out","w",stdout);
	work();
	return 0;
}
