#include <bits/stdc++.h>
using namespace std;

class Plusonegame{
public:
	string getorder(string s)
	{
		int a[10],b=0;  string ans;
		for (int i=0; i<10; i++)  a[i]=0;
		for (int i=0; i<s.length(); i++)
			if (('0'<=s[i])&&(s[i]<='9'))
				a[s[i]-'0']++;
			else  b++;
		for (int i=0; i<10; i++)
			{
				if ((i)&&(b))  b--,ans+='+';
				for (int j=0; j<a[i]; j++)  ans+=char(i+'0');
			}
		while (b)  b--,ans+='+';
		return ans;
	}
}Main;

int main()
{
	freopen("300.in","r",stdin);
	freopen("300.out","w",stdout);
	string s;
	cin>>s;
	cout<<Main.getorder(s);
	return 0;
}
