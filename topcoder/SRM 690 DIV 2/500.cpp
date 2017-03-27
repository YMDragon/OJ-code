#include <bits/stdc++.h>
using namespace std;

class GerrymanderEasy{
public:
	double getmax(vector <int> A, vector <int> B, int K)
	{
		double ans=0;
		for (int i=1; i<A.size(); i++)  A[i]+=A[i-1];
		for (int i=1; i<B.size(); i++)  B[i]+=B[i-1];
		for (int i=0; i+K<=A.size(); i++)
			for (int j=i+K-1; j<A.size(); j++)
				{
					int sa=A[j]-(i?A[i-1]:0),sb=B[j]-(i?B[i-1]:0);
					ans=max(ans,1.0*sb/sa);
				}
		return ans;
	}
}Main;

int main()
{
	freopen("500.in","r",stdin);
	freopen("500.out","w",stdout);
	vector <int> A,B;
	int K,n;
	scanf("%d",&n);
	for (int i=1,x; i<=n; i++)  scanf("%d",&x),A.push_back(x);
	for (int i=1,x; i<=n; i++)  scanf("%d",&x),B.push_back(x);
	scanf("%d",&K);
	printf("%f",Main.getmax(A,B,K));
	return 0;
}
