#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,L,R,s;

void work()
{
	scanf("%d",&n),L=-1e9,R=1e9;
	for (int i=1,c,d; i<=n; i++)
		{
			scanf("%d %d",&c,&d);
			if (d==1)  L=max(L,1900-s);
			else  R=min(R,1900-s);
			s+=c;
		}
	if (L>=R)  printf("Impossible");
	else  if (R==1e9)  printf("Infinity");
	else  printf("%d",s+R-1);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
