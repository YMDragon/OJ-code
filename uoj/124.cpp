#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=int(1e9+7);
struct matrix{int a[2][2];}A,B;
int ln,lm,a,b,c,d;
char n[1000010],m[1000010];

matrix operator * (matrix a,matrix b)
{
	matrix c=(matrix){{{0,0},{0,1}}};
	c.a[0][0]=1LL*a.a[0][0]*b.a[0][0]%mo;
	c.a[1][0]=(1LL*a.a[1][0]*b.a[0][0]+b.a[1][0])%mo;
	return c;
}

matrix qpow(matrix a,int b)
{
	matrix x=a;  a=(matrix){{{1,0},{0,1}}};
	while (b)
		{
			if (b&1)  a=a*x;
			x=x*x,b>>=1;
		}
	return a;
}

matrix qpow(matrix a,char *n,int l)
{
	matrix x=a;  a=(matrix){{{1,0},{0,1}}};
	for (int i=l; i; i--)
		a=a*qpow(x,n[i]-'0'),x=qpow(x,10);
	return a;
}

void work()
{
	scanf("%s %s %d %d %d %d",n+1,m+1,&a,&b,&c,&d);
	ln=strlen(n+1),lm=strlen(m+1);
	for (int i=ln; i; i--)  if (n[i]=='0')  n[i]='9';  else  {n[i]--;  break;}
	for (int i=lm; i; i--)  if (m[i]=='0')  m[i]='9';  else  {m[i]--;  break;}
	A=(matrix){{{a,0},{b,1}}},B=(matrix){{{c,0},{d,1}}};
	A=qpow(A,m,lm),A=qpow(A*B,n,ln)*A;
	printf("%d",(A.a[0][0]+A.a[1][0])%mo);
}

int main()
{
	freopen("124.in","r",stdin);
	freopen("124.out","w",stdout);
	work();
	return 0;
}
