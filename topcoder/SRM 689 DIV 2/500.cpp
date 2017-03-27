#include <bits/stdc++.h>
using namespace std;

class NonDeterministicSubstring{
public:
	long long ways(string A, string B)
	{
		long long ans=0;
		for (int i=0,j,k; i<=int(A.size()-B.size()); i++)
			{
				for (j=0; j<B.size(); )
					if ((B[j]=='?')||(A[i+j]==B[j]))  j++;  else  break;
				if (j==B.size())
					{
						int ok=1;
						for (j=0; j<i; j++)
							{
								for (k=0; k<B.size(); )
									if (A[j+k]==A[i+k])  k++;  else  break;
								if (k==B.size())  ok=0;
							}
						ans+=ok;
					}
			}
		return ans;
	}
}Main;

int main()
{
	freopen("500.in","r",stdin);
	freopen("500.out","w",stdout);
	string a,b;
	cin>>a>>b;
	cout<<Main.ways(a,b);
	return 0;
}
