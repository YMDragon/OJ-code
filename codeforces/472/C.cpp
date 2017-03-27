#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

string a[100010][2],l;
int n,p[100010];

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		{
			cin>>a[i][0]>>a[i][1];
			if (a[i][0]>a[i][1])  swap(a[i][0],a[i][1]);
		}
	for (int i=1; i<=n; i++)
		scanf("%d",&p[i]);
	for (int i,j=1; i=p[j],j<=n; j++)
		{
			if (a[i][0]>l)  l=a[i][0];
			else  if (a[i][1]>l)  l=a[i][1];
			else  {printf("NO");  return;}
		}
	printf("YES");
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
