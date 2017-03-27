#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,a[100010],b[1000010],l[1000010],r[1000010],ans;

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		{
			scanf("%d",&a[i]),b[a[i]]++;
			if (!l[a[i]])  l[a[i]]=i;
			r[a[i]]=max(r[a[i]],i);
		}
	for (int i=1; i<=1e6; i++)
		if ((b[ans]<b[i])||((b[ans]==b[i])&&(r[ans]-l[ans]>r[i]-l[i])))
			ans=i;
	printf("%d %d\n",l[ans],r[ans]);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
