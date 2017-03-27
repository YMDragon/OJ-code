#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=int(1e9+7),phi=int(1e9+6);
int n,d,ans,jc[1010],jcn[1010];

int ksm(int a,int b,int mo)
{
	int x=a;  a=1;
	while (b)
		{
			if (b&1)  a=1LL*a*x%mo;
			x=1LL*x*x%mo,b>>=1;
		}
	return a;
}

int C(int n,int m)
{
	return 1LL*jc[m]*jcn[n]%mo*jcn[m-n]%mo;
}

void prepare()
{
	jc[0]=1;
	for (int i=1; i<=1000; i++)  jc[i]=1LL*jc[i-1]*i%mo;
	jcn[1000]=ksm(jc[1000],mo-2,mo);
	for (int i=1000; i>=1; i--)  jcn[i-1]=1LL*jcn[i]*i%mo;
}

void work()
{
	cin>>n>>d,ans=0;
	for (int i=0,tp=1; i<=n; i++)
		{
			ans+=1LL*tp*C(i,n)*ksm(2,1LL*ksm(d+1,n-i,phi)*ksm(d,i,phi)%phi,mo)%mo;
			ans-=1LL*tp*C(i,n)*ksm(2,1LL*ksm(d,n-i,phi)*ksm(d-1,i,phi)%phi,mo)%mo;
			if (ans>=mo)  ans-=mo;
			if (ans<0)  ans+=mo;
			tp*=-1;
		}
	cout<<ans<<endl;
}

int main()
{
	freopen("CNTDSETS.in","r",stdin);
	freopen("CNTDSETS.out","w",stdout);
	int t;
	scanf("%d",&t),prepare();
	while (t--)  work();
	return 0;
}
