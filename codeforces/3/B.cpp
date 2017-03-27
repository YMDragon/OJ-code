#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define oo  (1<<30)
#define LL  long long
using namespace std;

struct node{int p,id;}a[100010],b[100010];

int n,v,suma[100010],sumb[100010],ans,tota,totb;

bool cmp(node x,node y){return x.p>y.p;}

void work()
{
  scanf("%d %d",&n,&v);
  int t,p;
  for (int i=1; i<=n; i++)
    {
      scanf("%d %d",&t,&p);
      if (t==1)  a[++tota]=(node){p,i};  else  b[++totb]=(node){p,i};
    }
  sort(a+1,a+tota+1,cmp);
  sort(b+1,b+totb+1,cmp);
  for (int i=1; i<=tota; i++)  suma[i]=suma[i-1]+a[i].p;
  for (int i=1; i<=totb; i++)  sumb[i]=sumb[i-1]+b[i].p;
  for (int i=0; i<=totb; i++)
    {
      t=min(v-2*i,tota);
      if (t<0)  break;
      if (sumb[i]+suma[t]>ans)
    ans=sumb[i]+suma[t],p=i;
    }
  printf("%d\n",ans);
  if (ans==0)  return;
  for (int i=1; i<=min(v-2*p,tota); i++)
    printf("%d ",a[i].id);
  for (int i=1; i<=p; i++)
    printf("%d ",b[i].id);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
  work();
  return 0;
}
