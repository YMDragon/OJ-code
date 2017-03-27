#include <bits/stdc++.h>
using namespace std;

class FourStrings{
	int ans;

	string merge(string a,string b)
	{
		for (int i=0,j,k; i<a.length(); i++)
			{
				for (j=i,k=0; j<a.length()&&k<b.length(); j++,k++)
					if (a[j]!=b[k])  break;
				if (k==b.length())  return a;
				if (j==a.length())  {for (; k<b.length(); k++)  a+=b[k];  return a;}
			}
		return a+b;
	}

	void calc(string a,string b,string c,string d)
	{
		string s;
		s=merge(merge(merge(a,b),c),d);
		ans=min(ans,int(s.length()));
	}

public:
	int shortestLength(string a,string b,string c,string d)
	{
		ans=a.length()+b.length()+c.length()+d.length();
		calc(a,b,c,d),calc(a,b,d,c),calc(a,c,b,d),calc(a,c,d,b),calc(a,d,b,c),calc(a,d,c,b);
		calc(b,a,c,d),calc(b,a,d,c),calc(b,c,a,d),calc(b,c,d,a),calc(b,d,a,c),calc(b,d,c,a);
		calc(c,a,b,d),calc(c,a,d,b),calc(c,b,a,d),calc(c,b,d,a),calc(c,d,a,b),calc(c,d,b,a);
		calc(d,a,b,c),calc(d,a,c,b),calc(d,b,a,c),calc(d,b,c,a),calc(d,c,a,b),calc(d,c,b,a);
		return ans;
	}
}Main;

int main()
{
	freopen("550.in","r",stdin);
	freopen("550.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	printf("%d",Main.shortestLength(a,b,c,d));
	return 0;
}
