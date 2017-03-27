#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const int mo=int(1e9+7);
struct node{int x,ls,rs;}t[4000010];
int n,nn,tot,a[100010],rt[100010];
LL sum,ans,Min,cnt;

void ask(int y,int x,int k,int s)
{
	if ((!y)||(s>Min))  return;
	if (k<0)
		{
			if (s<Min)  Min=s,cnt=0;
			if (s==Min)  cnt+=1LL*t[x].x*t[y].x;
			return;
		}
	if (t[x].ls)  ask(t[y].ls,t[x].ls,k-1,s);
	else  ask(t[y].ls,t[x].rs,k-1,s|(1<<k));
	if (t[x].rs)  ask(t[y].rs,t[x].rs,k-1,s);
	else  ask(t[y].rs,t[x].ls,k-1,s|(1<<k));
}

void work()
{
	scanf("%d",&n),ans=1;
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	sort(a+1,a+n+1),nn=0;
	for (int i=1,s; i<=n; i++)
		{
			s=1;
			while ((i<n)&&(a[i]==a[i+1]))  i++,s++;
			for (int j=1; j<=s-2; j++)  ans=ans*s%mo;
			a[++nn]=a[i],t[rt[nn]=++tot]=(node){s,0,0};
		}
	n=nn;
	for (int j=0,k=1; j<30; j++,k<<=1)
		{
			nn=0;
			for (int i=1,x,y; i<=n; i++)
				if ((i<n)&&((a[i]^a[i+1])<2*k))
					{
						if (t[rt[i]].x>t[rt[i+1]].x)  x=i,y=i+1;  else  x=i+1,y=i;
						a[++nn]=a[x];
						Min=1<<30,ask(rt[y],rt[x],j-1,k);
						t[++tot]=(node){t[rt[i]].x+t[rt[i+1]].x,rt[i],rt[i+1]};
						rt[nn]=tot,i++;
						sum+=Min,ans=ans*cnt%mo;
					}else
					{
						nn++,a[nn]=a[i],t[++tot].x=t[rt[i]].x;
						if (a[i]&k)  t[tot].rs=rt[i];  else  t[tot].ls=rt[i];
						rt[nn]=tot;
					}
			if ((n=nn)==1)  break;
		}
	printf("%lld\n%lld",sum,ans);
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
