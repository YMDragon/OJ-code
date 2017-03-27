#include <bits/stdc++.h>
using namespace std;

class WolfHockeyTeamEasy{
	const int mo=int(1e9+7);
	int f[1010][2010],ans;

public:
	int count(int N, int K)
	{
		if (N==1)  return (K^1)*2;
		for (int i=0; i<2*N; i++)  f[0][i]=1;
		for (int i=1; i<=N; i++)
			for (int j=2*i-1; j<2*N; j++)
				f[i][j]=(f[i][j-1]+f[i-1][j-1])%mo;
		for (int i=max(K,N-1); i<=2*N-2; i++)
			ans=(ans+f[i-N+1][i-1])%mo;
		for (int i=max(K,N); i<=2*N-2; i++)
			ans=(ans+f[i-N][i-1])%mo;
		for (int i=1; i<=N; i++)  ans=1LL*ans*i%mo;
		return ans*2%mo;
	}
}Main;

int main()
{
	freopen("1000.in","r",stdin);
	freopen("1000.out","w",stdout);
	int N,K;
	cin>>N>>K;
	cout<<Main.count(N,K);
	return 0;
}
