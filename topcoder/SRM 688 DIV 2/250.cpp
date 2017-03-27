#include <bits/stdc++.h>
using namespace std;

class ParenthesesDiv2Easy{
public:
	int getDepth(string s)
	{
		int ans=0,dep=0;
		for (int i=0; i<s.size(); i++)
			dep+=(s[i]=='(')?1:-1,ans=max(ans,dep);
		return ans;
	}
}Main;

int main()
{
	freopen("250.in","r",stdin);
	freopen("250.out","w",stdout);
	string s;
	cin>>s;
	printf("%d",Main.getDepth(s));
	return 0;
}
