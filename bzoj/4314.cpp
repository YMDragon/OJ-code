#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

const int mo=int(1e9+7);
int n,k,ans;
map <int,int> M[1010][1010];
map <int,int>::iterator it;

int gcd(int a,int b){return b?gcd(b,a%b):a;}

int ksm(int a,int b)
{
	int x=a;  a=1;
	while (b)
		{
			if (b&1)  a=1LL*a*x%mo;
			x=1LL*x*x%mo,b>>=1;
		}
	return a;
}

int f(int k,int a,int m)
{
	if (k==0)  return 1;
	it=M[k][a].find(m);
	if (it!=M[k][a].end())  return (*it).second;
	int g=gcd(a,m),res=0;
	res=1LL*f(k-1,1,g)*g%mo*(n/m)%mo;
	(res+=mo-1LL*(k-1)*f(k-1,(a+1)%m,m)%mo)%=mo;
	return M[k][a][m]=res;
}

void work()
{
	scanf("%d %d",&n,&k);
	ans=f(k,1,n);
	for (int i=1; i<=k; i++)
		ans=1LL*ans*ksm(i,mo-2)%mo;
	printf("%d",ans);
}

int main()
{
	freopen("4314.in","r",stdin);
	freopen("4314.out","w",stdout);
	work();
	return 0;
}
