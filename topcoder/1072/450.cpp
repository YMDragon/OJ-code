#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define Ls(n)  (n<<1)
#define Rs(n)  (Ls(n)|1)
#define lowbit(x)  (x&-x)
#define mp  make_pair
#define pb  push_back
using namespace std;

class Drbalance{
	int sum[55],len,ans;
public:
	int lesscng(string s,int k)
	{
		len=s.length();
		for (int i=0; i<len; i++)  sum[i]=sum[i-1]+((s[i]=='+')?1:-1);
		for (int i=0; i<len; i++)
			if (s[i]=='-')
				{
					int t=0;
					for (int j=i; j<len; j++)
							if (sum[j]<0)  t++;
					if (t>k)
						{
							for (int j=i; j<len; j++)  sum[j]+=2;
							ans++;
						}
					if (sum[i]<0)  k--;
				}
		return ans;
	}
}Main;

int main()
{
	freopen("450.in","r",stdin);
	freopen("450.out","w",stdout);
	string s;  int k;
	cin>>s>>k;
	printf("%d",Main.lesscng(s,k));
	return 0;
}
