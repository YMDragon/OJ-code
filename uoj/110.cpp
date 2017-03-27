#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int n,a,b,y[2010];

namespace work1{
  int cnt,f[2010][2010];
  LL ans;

  bool check(LL x)
  {
    cnt++;
    f[0][0]=cnt;
    for (int i=0; i<n; i++)
      for (int j=0; j<b; j++)
	if (f[i][j]==cnt)
	  {
	    LL sum=0;
	    for (int k=i+1; k<=n; k++)
	      {
		sum+=y[k];
		if ((x|sum)==x)  f[k][j+1]=cnt;
	      }
	  }
    for (int i=a; i<=b; i++)
      if (f[n][i]==cnt)  return 1;
    return 0;
  }

  void work()
  {
    for (int i=40; i>=0; i--)
      if (!check(ans+(1LL<<i)-1))  ans+=1LL<<i;
    cout<<ans<<endl;
  }
};

namespace work2{
  int f[2010];
  LL ans;

  bool check(LL x)
  {
    memset(f,127,sizeof(f));
    f[0]=0;
    for (int i=0; i<n; i++)
      if (f[i]<b)
	{
	  LL sum=0;
	  for (int k=i+1; k<=n; k++)
	    {
	      sum+=y[k];
	      if ((x|sum)==x)  f[k]=min(f[k],f[i]+1);
	    }
	}
    return f[n]<=b;
  }

  void work()
  {
    for (int i=40; i>=0; i--)
      if (!check(ans+(1LL<<i)-1))  ans+=1LL<<i;
    cout<<ans<<endl;
  }
};

int init()
{
  int Max=0;
  scanf("%d %d %d",&n,&a,&b);
  for (int i=1; i<=n; i++)  scanf("%d",&y[i]),Max=max(Max,y[i]);
  if (a==1)  return 2;
  return 1;
}

int main()
{
  freopen("110.in","r",stdin);
  freopen("110.out","w",stdout);
  int t=init();
  if (t==1)  work1::work();
  if (t==2)  work2::work();
  return 0;
}
