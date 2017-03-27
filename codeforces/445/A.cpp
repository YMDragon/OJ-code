#include <cstdlib>
#include <cstdio>
using namespace std;

int n,m;

void work()
{
	scanf("%d %d",&n,&m);
	char ch;
	for (int i=1; i<=n; i++)
		{
			while (getchar()!='\n')  ;
			for (int j=1; j<=m; j++)
				{
					ch=getchar();
					printf("%c",(ch=='-')?'-':((i+j)%2)?'W':'B');
				}
			printf("\n");
		}
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
