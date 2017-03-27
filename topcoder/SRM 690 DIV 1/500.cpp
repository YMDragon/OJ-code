#include <bits/stdc++.h>
using namespace std;

class TreeWalker{
	const int mo=int(1e9+7),inv2=(mo+1)/2;
	int f[100010],g[100010],ans;
	vector <int> son[100010];

	void dfs(int x)
	{
		f[x]=mo-1,g[x]=1;
		for (int i=0,y; i<son[x].size(); i++)
			{
				dfs(y=son[x][i]);
				f[x]=(0LL+f[x]+f[y]+mo-1LL*g[y]*g[y]%mo*inv2%mo*inv2%mo)%mo;
				g[x]=(g[x]+1LL*g[y]*inv2)%mo;
			}
		f[x]=(f[x]+1LL*g[x]*g[x])%mo;
	}

public:
	int calc(int N, int A0, int B, int C, int MOD)
	{
		for (int i=1; i<N; i++)
			son[A0%i].push_back(i),A0=(1LL*B*A0+C)%MOD;
		dfs(0);
		ans=f[0];
		for (int i=1; i<N; i++)  ans=2*ans%mo;
		return ans;
	}
}Main;

int main()
{
	freopen("500.in","r",stdin);
	freopen("500.out","w",stdout);
	int N,A0,B,C,MOD;
	cin>>N>>A0>>B>>C>>MOD;
	cout<<Main.calc(N,A0,B,C,MOD);
	return 0;
}
