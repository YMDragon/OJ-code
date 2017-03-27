#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector <int> V;

void work()
{
	scanf("%d",&n);
	for (int i=1; i*i<=n; i++)
		if (n%i==0)
			{
				for (int j=n/i; j<=n; j+=n/i)
					{
						if ((j+2)%i==0)  V.push_back(j==n?1:j+1);
						if ((j-2)%i==0)  V.push_back(j-1);
					}
			}
	sort(V.begin(),V.end());
	for (int i=0; i<V.size(); i++)
		if ((!i)||(V[i]!=V[i-1]))
			printf("%d\n",V[i]);
}

int main()
{
	freopen("1406.in","r",stdin);
	freopen("1406.out","w",stdout);
	work();
	return 0;
}
