#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const int mo=998244353,g=3;
int n,m,N,x[50010],y[50010],a,b,c,t,ans,A[1<<17],B[1<<17];

int gi()
{
	int w=0,q=1;  char ch=getchar();
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

int qpow(int a,int b)
{
	int x=a;  a=1;
	while (b)
		{
			if (b&1)  a=1LL*a*x%mo;
			x=1LL*x*x%mo,b>>=1;
		}
	return a;
}

void NTT(int *a,int n,int op)
{
	for (int i=1,j,p,t; i<n; i++)
		{
			for (j=0,p=i,t=1; t<n; j<<=1,j|=p&1,p>>=1,t<<=1);
			if (i<j)  swap(a[i],a[j]);
		}
	int w,W,u,v;
	for (int len=2; len<=n; len<<=1)
		{
			w=qpow(g,(mo-1)/len);
			if (op==-1)  w=qpow(w,mo-2);
			for (int i=0; i<n; i+=len)
				{
					W=1;
					for (int j=0; j<(len>>1); j++)
						{
							u=a[i+j],v=1LL*a[i+j+(len>>1)]*W%mo,W=1LL*W*w%mo;
							a[i+j]=(u+v)%mo,a[i+j+(len>>1)]=(u+mo-v)%mo;
						}
				}
		}
	if (op==-1)
		{
			int inv=qpow(n,mo-2);
			for (int i=0; i<n; i++)  a[i]=1LL*a[i]*inv%mo;
		}
}

void work()
{
	a=n=gi(),m=gi();
	for (int i=0; i<n; i++)  b+=2*(x[i]=gi());
	for (int i=0; i<n; i++)  b-=2*(y[i]=gi());
	if (b<0)  b=-b;
	for (N=1; N<2*n; N<<=1);
	for (int i=0; i<n; i++)  A[i]=x[i],B[i]=y[n-i-1];
	NTT(A,N,1),NTT(B,N,1);
	for (int i=0; i<N; i++)  A[i]=1LL*A[i]*B[i]%mo;
	NTT(A,N,-1);
	c=A[n-1];
	for (int i=0; i<n-1; i++)  c=max(c,A[i]+A[n+i]);
	c=-2*c;
	for (int i=0; i<n; i++)  c+=x[i]*x[i]+y[i]*y[i];
	t=b/(2*a);
	pi(min(a*t*t-b*t,a*(t+1)*(t+1)-b*(t+1))+c);
}

int main()
{
	freopen("4827.in","r",stdin);
	freopen("4827.out","w",stdout);
	work();
	return 0;
}
