#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int n,a[200010],b[200010],ma,mb,last;
LL sum;

void work()
{
	scanf("%d",&n);
	for (int i=1,x; i<=n; i++)
		{
			scanf("%d",&x);
			sum+=x;
			if (x>0)  a[++ma]=x,last=1;  else  b[++mb]=-x,last=0;
		}
	if (sum!=0)
		if (sum>0)  printf("first");  else  printf("second");
	else
		{
			for (int i=1; i<=ma&&i<=mb; i++)
				if (a[i]!=b[i])
					{if (a[i]>b[i])  printf("first");  else  printf("second");  return;}
			if (ma!=mb)
				if (ma>mb)  printf("first");  else  printf("second");
			else
				if (last)  printf("first");  else  printf("second");
		}
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
