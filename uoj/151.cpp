#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,a[20],ans;

int getint()
{
  int w=0,q=1;  char ch=getchar();
  while (((ch<'0')||('9'<ch))&&(ch!='-'))  ch=getchar();
  if (ch=='-')  q=0,ch=getchar();
  while (('0'<=ch)&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
  return q?w:-w;
}

void printint(int x)
{
  if (x>9)  printint(x/10);
  putchar(x%10+'0');
}

void dfs3(int x,int k)
{
  if (x>=ans)  return;
  if (k>14)  {ans=x;  return;}
  if (!a[k])  return dfs3(x,k+1);
  if ((k==0)&&(a[1]))  a[0]--,a[1]--,dfs3(x+1,k),a[0]++,a[1]++;
  if (k>2)
    {
      for (int i=k; i<=15; i++)
				if (!a[i])
					{
						for (int j=k; j<i; j++)  a[j]++;
						break;
					}else
					{
						a[i]--;
						if (i-k>=4)  dfs3(x+1,k);
					}
      for (int i=k; i<=15; i++)
				if (a[i]<2)
					{
						for (int j=k; j<i; j++)  a[j]+=2;
						break;
					}else
					{
						a[i]-=2;
						if (i-k>=2)  dfs3(x+1,k);
					}
      for (int i=k; i<=15; i++)
				if (a[i]<3)
					{
						for (int j=k; j<i; j++)  a[j]+=3;
						break;
					}else
					{
						a[i]-=3;
						if (i-k>=1)  dfs3(x+1,k);
					}
    }
  if (a[k]>=2)  a[k]-=2,dfs3(x+1,k),a[k]+=2;
  else  if (a[k])  a[k]--,dfs3(x+1,k),a[k]++;
}

void dfs2(int x,int k)
{
  if (x>=ans)  return;
  if (k>14)  return dfs3(x,0);
  if (a[k]>=3)
    {
      a[k]-=3;
      for (int j=0; j<=14; j++)
				if (a[j]>=2)  a[j]-=2,dfs2(x+1,k),a[j]+=2;
      for (int j=0; j<=14; j++)
				if (a[j])  a[j]--,dfs2(x+1,k),a[j]++;
      dfs2(x+1,k);
      a[k]+=3;
    }
  dfs2(x,k+1);
}

void dfs1(int x,int k)
{
  if (x>=ans)  return;
  if (k>14)  return dfs2(x,2);
  if (a[k]==4)
    {
      a[k]-=4;
      for (int i=0; i<=14; i++)
				if (a[i]>=2)
					{
						a[i]-=2;
						for (int j=i; j<=14; j++)
							if (a[j]>=2)
								a[j]-=2,dfs1(x+1,k),a[j]+=2;
						a[i]+=2;
					}
      for (int i=0; i<=14; i++)
				if (a[i])
					{
						a[i]--;
						for (int j=i; j<=14; j++)
							if (a[j])
								a[j]--,dfs1(x+1,k),a[j]++;
						a[i]++;
					}
      a[k]+=4;
    }
  dfs1(x,k+1);
}

void work()
{
  memset(a,0,sizeof(a));
  ans=n;
  for (int i=1,x,y; i<=n; i++)
    {
      x=getint(),y=getint();
      if (x==1)  x=14;
      if ((x==0)&&(y==1))  x=1;
      a[x]++;
    }
  dfs1(0,2);
  printint(ans),putchar('\n');
}

int main()
{
	freopen("151.in","r",stdin);
	freoepn("151.out","w",stdout);
  int t;
  t=getint(),n=getint();
  while (t--)  work();
  return 0;
}
