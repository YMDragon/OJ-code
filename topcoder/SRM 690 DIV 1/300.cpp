#include <bits/stdc++.h>
using namespace std;

class WolfCardGame{
	vector <int> ans;

public:
	vector <int> createAnswer(int N, int K)
	{
		for (int i=2; i<=7; i++)
			if (N%i)
				{
					for (int j=1; j<=K; j++)
						if (i*j<=100)
							ans.push_back(i*j);
					if (i*K<=100)  return ans;
				}
		ans.push_back(1);
		return ans;
	}
}Main;

int main()
{
	freopen("300.in","r",stdin);
	freopen("300.out","w",stdout);
	int N,K;  vector <int> ans;
	cin>>N>>K;
	ans=Main.createAnswer(N,K);
	for (int i=0; i<ans.size(); i++)  cout<<ans[i]<<' ';
	return 0;
}
