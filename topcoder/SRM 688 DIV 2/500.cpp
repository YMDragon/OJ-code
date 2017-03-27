#include <bits/stdc++.h>
using namespace std;

class ParenthesesDiv2Medium{
	int n,f[55][55],g[55][55];
	vector <int> ans;

	int calc(char a,char b)
	{
		return (a!='(')+(b!=')');
	}

public:
	vector <int> correct(string s)
	{
		n=s.size();
		for (int len=2; len<=n; len++)
			for (int l=0,r=len-1; r<n; l++,r++)
				{
					int t1=calc(s[l],s[r])+f[l+1][r-1];
					int t2=calc(s[l],s[l+1])+f[l+2][r];
					int t3=calc(s[r-1],s[r])+f[l][r-2];
					if ((t1<=t2)&&(t1<=t3))  f[l][r]=t1,g[l][r]=1;
					else  if (t2<=t3)  f[l][r]=t2,g[l][r]=2;
					else  f[l][r]=t3,g[l][r]=3;
				}
		for (int l=0,r=n-1; l<r; )
			{
				if (g[l][r]==1)
					{
						if (s[l]!='(')  ans.push_back(l);
						if (s[r]!=')')  ans.push_back(r);
						l++,r--;
					}else  if (g[l][r]==2)
					{
						if (s[l]!='(')  ans.push_back(l);
						if (s[l+1]!=')')  ans.push_back(l+1);
						l+=2;
					}else
					{
						if (s[r-1]!='(')  ans.push_back(r-1);
						if (s[r]!=')')  ans.push_back(r);
						r-=2;
					}
			}
		sort(ans.begin(),ans.end());
		return ans;
	}
}Main;

int main()
{
	freopen("500.in","r",stdin);
	freopen("500.out","w",stdout);
	string s;
	cin>>s;
	vector <int> ans=Main.correct(s);
	for (int i=0; i<ans.size(); i++)
		printf("%d ",ans[i]);
	return 0;
}
