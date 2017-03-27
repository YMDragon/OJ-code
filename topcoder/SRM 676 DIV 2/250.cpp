#include <bits/stdc++.h>
using namespace std;

class PalindromePrime{
	int ans;

	bool palindrome(int x)
	{
		if (x<10)  return 1;
		if (x<100)  return x%11==0;
		if (x<1000)  return (x%10)==(x/100);
		return 0;
	}

public:
	int count(int L,int R)
	{
		for (int i=max(2,L); i<=R; i++)
			{
				int t=1;
				for (int j=2; j<=sqrt(i)&&t; j++)
					if (i%j==0)  t=0;
				if ((t)&&(palindrome(i)))  ans++;
			}
		return ans;
	}
}Main;

int main()
{
	freopen("250.in","r",stdin);
	freopen("250.out","w",stdout);
	int L,R;
	scanf("%d %d",&L,&R);
	printf("%d",Main.count(L,R));
	return 0;
}
