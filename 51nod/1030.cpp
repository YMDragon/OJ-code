#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define RG  register
using namespace std;

const double pi=acos(-1);
struct comp{double r,i;}A[1<<20],B[1<<20],C[1<<20],Zero;
struct node{int len1,len2;};
int n,a[100010],s1[1<<20],s2[1<<20];
char s[100010];

comp operator + (comp x,comp y){return (comp){x.r+y.r,x.i+y.i};}
comp operator - (comp x,comp y){return (comp){x.r-y.r,x.i-y.i};}
comp operator * (comp x,comp y){return (comp){x.r*y.r-x.i*y.i,x.r*y.i+x.i*y.r};}
comp operator / (comp x,double y){return (comp){x.r/y,x.i/y};}

void DFT(comp *a,int n,int op)
{
	for (int i=1,p,q,t; i<n; i++)
		{
			for (p=i,q=0,t=1; t<n; q<<=1,q|=p&1,p>>=1,t<<=1);
			if (i<q)  swap(a[i],a[q]);
		}
	for (RG int len=2,i,j; len<=n; len<<=1)
		{
			comp w=(comp){cos(2*op*pi/len),sin(2*op*pi/len)};
			for (i=0; i<n; i+=len)
				{
					comp W=(comp){1,0};
					for (j=0; j<(len>>1); j++)
						{
							comp u=a[i+j],v=a[i+j+(len>>1)]*W;
							a[i+j]=u+v,a[i+j+(len>>1)]=u-v,W=W*w;
						}
				}
		}
	if (op==-1)
		for (int i=0; i<n; i++)  a[i]=a[i]/n;
}

node solve(int l,int r)
{
	int L=7*l,R=7*r;
	if (r-l<=500)
		{
			int len1=1,len2=1;
			s2[L]=1;
			for (int i=r-1,j; i>=l; i--)
				{
					s1[L]+=a[i];
					for (j=L; s1[j]>=10; s1[j+1]+=s1[j]/10,s1[j]%=10,j++);
					if (j-L>=len1)  len1=j-L+1;
					if (i!=l)
						{
							for (j=0; j<len1; j++)  s1[j+L]*=36;
							for (j=L; s1[j]||j-L<len1; s1[j+1]+=s1[j]/10,s1[j]%=10,j++);
							len1=j-L;
						}
					for (j=0; j<len2; j++)  s2[j+L]*=36;
					for (j=L; s2[j]||j-L<len2; s2[j+1]+=s2[j]/10,s2[j]%=10,j++);
					len2=j-L;
				}
			return (node){len1,len2};
		}
	int mid=(l+r)>>1,Mid=7*mid,N=1,len1,len2;
	node x=solve(l,mid),y=solve(mid,r);
	while ((N<x.len2+y.len1-1)||(N<x.len2+y.len2-1))  N<<=1;
	for (int i=0; i<x.len2; i++)  A[i]=(comp){s2[i+L],0};
	for (int i=x.len2; i<N; i++)  A[i]=Zero;
	for (int i=0; i<y.len1; i++)  B[i]=(comp){s1[i+Mid],0};
	for (int i=y.len1; i<N; i++)  B[i]=Zero;
	for (int i=0; i<y.len2; i++)  C[i]=(comp){s2[i+Mid],0};
	for (int i=y.len2; i<N; i++)  C[i]=Zero;
	DFT(A,N,1),DFT(B,N,1),DFT(C,N,1);
	for (int i=0; i<N; i++)
		{
			B[i]=A[i]*B[i];
			C[i]=A[i]*C[i];
		}
	DFT(B,N,-1),DFT(C,N,-1);
	for (int i=L; i<Mid; i++)  s1[i]+=int(B[i-L].r+0.5),B[i-L+1].r+=s1[i]/10,s1[i]%=10;
	for (int i=Mid; i-L<N; i++)  s1[i]=int(B[i-L].r+0.5),B[i-L+1].r+=s1[i]/10,s1[i]%=10;
	for (int i=N+L; i<R; i++)  s1[i]=0;
	for (int i=L; i-L<N; i++)  s2[i]=int(C[i-L].r+0.5),C[i-L+1].r+=s2[i]/10,s2[i]%=10;
	for (int i=N+L; i<R; i++)  s2[i]=0;
	for (len1=R-1; !s1[len1]&&len1>L; len1--);
	for (len2=R-1; !s2[len2]&&len2>L; len2--);
	return (node){len1-L+1,len2-L+1};
}

void work()
{
	scanf("%s",s),n=strlen(s);
	for (int i=0; i<n; i++)
		if (('0'<=s[i])&&(s[i]<='9'))  a[n-i-1]=s[i]-'0';
		else  a[n-i-1]=s[i]-'A'+10;
	node x=solve(0,n);
	for (int i=x.len1-1; i>=0; i--)
		putchar(s1[i]+'0');
}

int main()
{
	freopen("1030.in","r",stdin);
	freopen("1030.out","w",stdout);
	work();
	return 0;
}
