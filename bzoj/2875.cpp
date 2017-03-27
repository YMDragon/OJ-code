#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
struct matrix{LL a[2][2];}A;
LL m,a,c,x0,n;
int g;

LL mul(LL a,LL b){return (a*b-(LL)((long double)a/m*b+1e-3)*m+m)%m;}

matrix operator * (matrix a,matrix b)
{
	matrix c=(matrix){{{0,0},{0,1}}};
	c.a[0][0]=mul(a.a[0][0],b.a[0][0]);
	c.a[1][0]=(mul(a.a[1][0],b.a[0][0])+b.a[1][0])%m;
	return c;
}

matrix qpow(matrix a,LL b)
{
	matrix x=a;  a=(matrix){{{1,0},{0,1}}};
	while (b)
		{
			if (b&1)  a=a*x;
			x=x*x,b>>=1;
		}
	return a;
}

void work()
{
	scanf("%lld %lld %lld %lld %lld %d",&m,&a,&c,&x0,&n,&g);
	A=(matrix){{{a,0},{c,1}}};
	A=qpow(A,n);
	printf("%d\n",(mul(x0,A.a[0][0])+A.a[1][0])%m%g);
}

int main()
{
	freopen("2875.in","r",stdin);
	freopen("2875.out","w",stdout);
	work();
	return 0;
}
