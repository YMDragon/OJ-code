#include <cstdlib>
#include <cstdio>
using namespace std;

int n,m,a;

void work()
{
  scanf("%d %d %d",&n,&m,&a);
  printf("%I64d",1LL*((n+a-1)/a)*((m+a-1)/a));
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
  work();
  return 0;
}
