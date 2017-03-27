#include <cstdlib>
#include <cstdio>
#define LL  long long
#define mo  1LL*1000000007
using namespace std;

LL x,y,n,ans;

void work()
{
	scanf("%lld %lld %lld",&x,&y,&n);
	n=(n-1)%6;
	switch (n)
		{
		case 0:{ans=x;  break;}
		case 1:{ans=y;  break;}
		case 2:{ans=-x+y;  break;}
		case 3:{ans=-x;  break;}
		case 4:{ans=-y;  break;}
		case 5:{ans=x-y;  break;}
		}
	while (ans<0)  ans+=mo;
	ans%=mo;
	printf("%lld",ans);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
