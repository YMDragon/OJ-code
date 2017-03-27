#include <bits/stdc++.h>
using namespace std;

class DoubleString{
public:
	string check(string S)
	{
		if (S.size()%2)  return "not square";
		for (int i=0,j=S.size()/2; j<S.size(); i++,j++)
			if (S[i]!=S[j])
				return "not square";
		return "square";
	}
}Main;

int main()
{
	freopen("250.in","r",stdin);
	freopen("250.out","w",stdout);
	string s;
	cin>>s;
	cout<<Main.check(s);
	return 0;
}
