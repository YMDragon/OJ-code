#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define oo  (1<<30)
#define LL  long long
using namespace std;

int a[2][1010][1010],f[2][1010][1010],g[2][1010][1010],n,ans;

int solve(int d)
{
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
      {
        f[d][i][j]=a[d][i][j];
        if ((i==1)&&(j==1))  continue; 
        if (i==1)
          f[d][i][j]+=f[d][i][j-1],g[d][i][j]=0;
        else
          if (j==1)
            f[d][i][j]+=f[d][i-1][j],g[d][i][j]=1;
          else
            if (f[d][i][j-1]<f[d][i-1][j])
              f[d][i][j]+=f[d][i][j-1],g[d][i][j]=0;
            else
              f[d][i][j]+=f[d][i-1][j],g[d][i][j]=1;
          }
  return f[d][n][n];
}

void print(int d,int x,int y)
{
  if ((x==1)&&(y==1))  return;
  if (g[d][x][y])
    {
      print(d,x-1,y);
      printf("D");
    }else
    {
      print(d,x,y-1);
      printf("R");
    }
}

void work()
{
  int x,zx=0;
  scanf("%d",&n);
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
      {
        scanf("%d",&x);
        if (x==0)  {zx=i;  continue;}
        while (x%2==0)  a[0][i][j]++,x/=2;
        while (x%5==0)  a[1][i][j]++,x/=5;
      }
  int ans0=solve(0),ans1=solve(1);
  ans=min(ans0,ans1);
  if ((zx)&&(ans))
    {
      printf("1\n");
      for (int i=1; i<zx; i++)  printf("D");
      for (int i=1; i<n; i++)  printf("R");
      for (int i=zx; i<n; i++)  printf("D");
    }else
    {
      printf("%d\n",ans);
      if (ans0<ans1)  print(0,n,n);  else  print(1,n,n);
    }
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
  work();
  return 0;
}
