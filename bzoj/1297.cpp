#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define p(x,y)  ((x)*n+(y))
using namespace std;

const int mo=2009;
struct matrix{int a[101][101];}a,b,Zero;
int n,t;
char ch;

matrix mul(matrix a,matrix b,int t=10*n)
{
	matrix c=Zero;
	for (int k=0; k<10*n; k++)
		for (int i=0; i<t; i++)
			for (int j=0; j<10*n; j++)
				c.a[i][j]+=a.a[i][k]*b.a[k][j];
	for (int i=0; i<t; i++)
		for (int j=0; j<10*n; j++)
			c.a[i][j]%=mo;
	return c;
}

void work()
{
	scanf("%d %d",&n,&t);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			{
				do  ch=getchar();  while ((ch<'0')||('9'<ch));
				if (ch!='0')  b.a[p(ch-'1',i)][p(0,j)]=1;
			}
	for (int i=0; i<9; i++)
		for (int j=0; j<n; j++)
			b.a[p(i,j)][p(i+1,j)]=1;
	a.a[0][p(0,0)]=1;
	while (t)
		{
			if (t&1)  a=mul(a,b,1);
			b=mul(b,b),t>>=1;
		}
	printf("%d",a.a[0][p(0,n-1)]);
}

int main()
{
	freopen("1297.in","r",stdin);
	freopen("1297.out","w",stdout);
	work();
	return 0;
}
