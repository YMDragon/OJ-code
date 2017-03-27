#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n=30,g[31];
double ans;

void work()
{
	for (int i=0; i<=n; i++)
		{
			for (int j=1; j<i; j++)  g[i]+=g[j];
			g[i]++;
		}
	for (int i=1; i<=n; i++)
		{
			double s=0;
			for (int j=0; j<=i-2; j++)  s+=g[j];
			ans+=s/i;
		}
	printf("%.2lf\n",ans+0.005);
}

int main()
{
	work();
	return 0;
}
