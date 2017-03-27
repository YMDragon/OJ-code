#include <bits/stdc++.h>
using namespace std;

class WolfHockeyTeamHard{
	const int mo=int(1e9+7);
	int ans,fac[1000010],inv[1000010];

	int C(int n,int m){return 1LL*fac[n]*inv[m]%mo*inv[n-m]%mo;}
	int f(int i,int j){return (C(j+1,i)-C(j+1,i-1)+mo)%mo;}

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

public:
	int count(int N, int K)
	{
		if (N==1)  return (K^1)*2;
		fac[0]=1;
		for (int i=1; i<=2*N; i++)  fac[i]=1LL*fac[i-1]*i%mo;
		inv[2*N]=ksm(fac[2*N],mo-2);
		for (int i=2*N; i; i--)  inv[i-1]=1LL*inv[i]*i%mo;
		for (int i=max(K,N-1); i<=2*N-2; i++)
			ans=(ans+f(i-N+1,i-1))%mo;
		for (int i=max(K,N); i<=2*N-2; i++)
			ans=(ans+f(i-N,i-1))%mo;
		for (int i=1; i<=N; i++)  ans=1LL*ans*i%mo;
		return ans*2%mo;
	}
}Main;

int main()
{
	freopen("900.in","r",stdin);
	freopen("900.out","w",stdout);
	int N,K;
	cin>>N>>K;
	cout<<Main.count(N,K);
	return 0;
}
