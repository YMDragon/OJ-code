#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

char home[25],away[25];
int n,h[100],a[100];

void work()
{
	scanf("%s\n%s\n%d\n",home,away,&n);
	for (int i=1,t,num; i<=n; i++)
		{
			char ha,yr;
			scanf("%d %c %d %c\n",&t,&ha,&num,&yr);
			if (ha=='h')
				{
					if (yr=='y')  h[num]++;  else  h[num]+=2;
					if (h[num]>=2)  printf("%s %d %d\n",home,num,t),h[num]=-200;
				}else
				{
					if (yr=='y')  a[num]++;  else  a[num]+=2;
					if (a[num]>=2)  printf("%s %d %d\n",away,num,t),a[num]=-200;
				}
		}
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
