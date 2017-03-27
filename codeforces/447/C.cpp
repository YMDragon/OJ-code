#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define LL  long long
#define oo  (1<<30)
using namespace std;

int a[100010],l[100010],r[100010],n,m,ans;

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	l[1]=1;
	for (int i=2; i<=n; i++)
		if (a[i-1]<a[i])  l[i]=l[i-1]+1;  else  l[i]=1;
	r[n]=1;
	for (int i=n-1; i>=1; i--)
		if (a[i]<a[i+1])  r[i]=r[i+1]+1;  else  r[i]=1;
	for (int i=1; i<=n; i++)
		{
			if (a[i-1]+1<a[i+1])
				ans=max(ans,l[i-1]+1+r[i+1]);
			ans=max(ans,1+max(l[i-1],r[i+1]));
		}
	printf("%d",ans);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
