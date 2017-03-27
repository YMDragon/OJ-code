#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int n,k,a[100010],ans,sum;
vector <int> b;

void work()
{
	scanf("%d %d",&n,&k);
	for (int i=1; i<=n; i++)
		{
			scanf("%d",&a[i]);
			if (a[i]%10)  b.push_back(10-a[i]%10);
			ans+=a[i]/10,sum+=a[i];
		}
	if (sum+k>=n*100)  {printf("%d",n*10);  return;}
	sort(b.begin(),b.end());
	for (int i=0; i<b.size()&&k; i++)
		if (b[i]<=k)  ans++,k-=b[i];
	ans+=k/10;
	printf("%d",ans);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
