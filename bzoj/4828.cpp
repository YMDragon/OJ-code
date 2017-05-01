#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int n,m,mc,maxc,q,a[105],w[105],C[25],f[105][105],p[26],tot,A[1000000],B[1000000];

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
	if (x<0)  putchar('-');
	if (x>9)  pi(x/10);
	putchar(x%10+'0');
}

void dfs(int x,int s)
{
	if (x>25)  {A[++tot]=s;  return;}
	dfs(x+1,s);
	while (1LL*s*p[x]<=maxc)
		s*=p[x],dfs(x+1,s);
}

void work()
{
	n=gi(),m=gi(),mc=gi();
	for (int i=1; i<=n; i++)  a[i]=gi();
	for (int i=1; i<=n; i++)  w[i]=gi();
	for (int i=1; i<=m; i++)  maxc=max(maxc,C[i]=gi());
	for (int i=0; i<=n; i++)
		for (int j=0; j<=mc; j++)
			f[i][j]=-1;
	f[0][mc]=0;
	for (int i=1; i<=n; i++)
		for (int j=a[i]; j<=mc; j++)
			if (f[i-1][j]>=0)
				{
					f[i][min(mc,j-a[i]+w[i])]=max(f[i][min(mc,j-a[i]+w[i])],f[i-1][j]);
					f[i][j-a[i]]=max(f[i][j-a[i]],f[i-1][j]+1);
					q=max(q,f[i-1][j]+1);
				}
	for (int i=2,Tot=0; i<=100; i++)
		{
			int ok=1;
			for (int j=2; j*j<=i; j++)
				if (i%j==0)  ok=0;
			if (ok)  p[++Tot]=i;
		}
	dfs(1,1);
	sort(A+1,A+tot+1),B[1]=1;
	for (int i=2; i<=tot; i++)
		{
			B[i]=B[i-1]+A[i]-A[i-1];
			for (int _=25; _; _--)
				if (A[i]%p[_]==0)
					{
						for (int j=p[_],t,x; j<=100; j++)
							if (A[i]%j==0)
								{
									t=j+1,x=A[i];
									for (int k=j; x!=1&&k>1; k--)
										while (x%k==0)  x/=k,t++;
									if ((x==1)&&(t<B[i]))  B[i]=t;
								}
						break;
					}
		}
	for (int i=1,c,ans; i<=m; i++)
		{
			c=C[i],ans=0;
			if (c<=q)  {puts("1");  continue;}
			for (int j=1,k=tot; j<=tot&&A[j]<=c; j++)
				{
					while (A[j]+A[k]>c)  k--;
					if (B[j]+B[k]+c-A[j]-A[k]<=q)  {ans=1;  break;}
				}
			pi(ans),puts("");
		}
}

int main()
{
	freopen("4828.in","r",stdin);
	freopen("4828.out","w",stdout);
	work();
	return 0;
}
