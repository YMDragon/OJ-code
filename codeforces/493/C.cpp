#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,a[200010],b[200010],sa,sb;

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	scanf("%d",&m);
	for (int i=1; i<=m; i++)  scanf("%d",&b[i]);
	sort(a+1,a+n+1),sort(b+1,b+m+1);
	sa=3*n,sb=3*m,a[n+1]=1<<30,b[m+1]=1<<30;
	for (int i=0,j=0; i<n||j<m; )
		{
			int t=min(a[i+1],b[j+1]);
			while (a[i+1]==t)  i++;
			while (b[j+1]==t)  j++;
			if ((2*i+3*(n-i))-(2*j+3*(m-j))>sa-sb)  sa=2*i+3*(n-i),sb=2*j+3*(m-j);
		}
	printf("%d:%d",sa,sb);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
