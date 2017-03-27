#include <bits/stdc++.h>
using namespace std;

typedef long long  LL;
int n=18,pre=40000,Q[40010];
LL ans;
bool a[160010];

void work()
{
	a[0]=1,Q[0]=1;
	for (int i=1; i<=pre; i++)
		{
			for (int j=4*i; j>=4; j--)  a[j]^=a[j-1]^a[j-2]^a[j-3]^a[j-4];
			a[3]^=a[2]^a[1]^a[0],a[2]^=a[1]^a[0],a[1]^=a[0];
			for (int j=4*i; j>=0; j--)  Q[i]+=a[j];
		}
	for (LL i=1,t=10,x,res,p,q; i<=n; i++,t*=10)
		{
			x=t,res=1,p=0,q=1;
			while (x)
				{
					if (x&1)  p|=q,q<<=1;
					else  if ((p&(q>>1))||(x==t))  q<<=1;
					else  res*=Q[p],p=0,q=1;
					x>>=1;
				}
			res*=Q[p];
			printf("%lld %lld\n",t,res);
			ans+=res;
		}
	printf("%lld\n",ans);
}

int main()
{
	work();
	return 0;
}
