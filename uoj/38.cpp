#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define Ls(N)  (n<<1)
#define Rs(n)  (Ls(n)|1)
using namespace std;

typedef long long  LL;
const int prime[60]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281},mo=19961993,N=100000,M=1000000;
int n,t[4*N],Pow[60][N+10],inv[60],Pi;
LL has[M+10],bit[4*N],Bit;

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

void ask(int n,int l,int r,int L,int R)
{
	if ((L<=l)&&(r<=R))  Pi=1LL*Pi*t[n]%mo,Bit|=bit[n];
	else
		{
			int mid=(l+r)>>1;
			if (L<=mid)  ask(Ls(n),l,mid,L,R);
			if (mid<R)  ask(Rs(n),mid+1,r,L,R);
		}
}

int ask(int l,int r)
{
	Pi=1,Bit=0;
	ask(1,1,N,l,r);
	for (int i=0; i<60; i++)
		if (Bit&(1LL<<i))
			Pi=1LL*Pi*inv[i]%mo*(prime[i]-1)%mo;
	return Pi;
}

void modify(int n,int l,int r,int x,int k)
{
	if (l==r)  t[n]=k,bit[n]=has[k];
	else
		{
			int mid=(l+r)>>1;
			x<=mid?modify(Ls(n),l,mid,x,k):modify(Rs(n),mid+1,r,x,k);
			t[n]=1LL*t[Ls(n)]*t[Rs(n)]%mo,bit[n]=bit[Ls(n)]|bit[Rs(n)];
		}
}

void work()
{
	scanf("%d",&n);
	for (int i=0; i<60; i++)
		{
			Pow[i][0]=1,inv[i]=qpow(prime[i],mo-2);
			for (int j=1; j<=N; j++)  Pow[i][j]=1LL*Pow[i][j-1]*prime[i]%mo;
		}
	for (int i=2,j=0; i<=M; i++)
		{
			if (i==prime[j])  has[i]=1LL<<j,j++;
			for (int k=0; k<j&&i*prime[k]<=M; k++)
				{
					has[i*prime[k]]=has[i];
					has[i*prime[k]]|=(1LL<<k);
					if (i%prime[k]==0)  break;
				}
		}
	for (int i=1; i<=N; i++)  modify(1,1,N,i,3);
	for (int i=1,a,b,c; i<=n; i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			if (a==0)  printf("%d\n",ask(b,c));
			else  modify(1,1,N,b,c);
		}
}

int main()
{
	freopen("38.in","r",stdin);
	freopen("38.out","w",stdout);
	work();
	return 0;
}
