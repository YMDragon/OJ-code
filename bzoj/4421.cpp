#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=int(1e9+7);
int n,m,ans;
char ch[300010];

void work()
{
	scanf("%d %d\n%s",&n,&m,ch+1),ans=1;
	int t=0;
	for (int i=1; i<=n; i++)
		{
			t=(t*10+ch[i]-'0')%m;
			if ((!t)&&(i!=n))  ans=(ans<<1)%mo;
		}
	if (t)  printf("0");  else  printf("%d",ans); 
}

int main()
{
	freopen("4421.in","r",stdin);
	freopen("4421.out","w",stdout);
	work();
	return 0;
}
