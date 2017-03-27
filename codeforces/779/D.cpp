#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,a[200010],b[200010];
char t[200010],p[200010];

bool check(int mid)
{
	int j=1;
	for (int i=1; i<=n; i++)
		if ((t[i]==p[j])&&(b[i]>mid))
			j++;
	return (j>m);
}

void work()
{
	scanf("%s",t+1),n=strlen(t+1);
	scanf("%s",p+1),m=strlen(p+1);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]),b[a[i]]=i;
	int l=0,r=n,mid;
	for (; r-l>1; check(mid=(l+r)>>1)?l=mid:r=mid);
	printf("%d",l);
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
