#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

const int mo=500500507;
int n=500500,m,p[500510],b[100000000],ans;
set <int> S;

void work()
{
	b[1]=1,ans=1;
	for (int i=2; m<n; i++)
		{
			if (!b[i])  p[++m]=i,S.insert(i);
			for (int j=1; j<=m&&i*p[j]<=1e7; j++)
				{
					b[i*p[j]]=1;
					if (i%p[j]==0)  break;
				}
		}
	for (int i=1; i<=n; i++)
		{
			int x=*S.begin();
			S.erase(S.begin());
			ans=1LL*ans*x%mo;
			if (1LL*x*x<p[m])  S.insert(x*x);
		}
	printf("%d\n",ans);
}

int main()
{
	work();
	return 0;
}
