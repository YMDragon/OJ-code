#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

multiset <int,greater<int> > S;
int n,a[505];

void work()
{
	scanf("%d",&n);
	for (int i=1,x; i<=n*n; i++)
		scanf("%d",&x),S.insert(x);
	for (int i=1; i<=n; i++)
		{
			a[i]=*(S.begin());
			for (int j=1; j<=i; j++)
				{
					int g=__gcd(a[i],a[j]);
					S.erase(S.find(g));
					if (i!=j)  S.erase(S.find(g));
				}
			printf("%d ",a[i]);
		}
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
