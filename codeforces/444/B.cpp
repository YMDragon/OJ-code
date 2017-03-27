#include <algorithm>
#include <cstdlib>
#include <cstdio>
#define LL  long long
using namespace std;

int n,d,a[100010],b[100010],c[100010],p[100010];
LL x;

LL getNextX()
{
	x=(x*37+10007)%1000000007;
	return x;
}
void initAB()
{
	for(int i=0; i<n; i++)  a[i]=i+1;
	for(int i=0; i<n; i++)  swap(a[i],a[getNextX()%(i+1)]);
	for(int i=0; i<n; i++)  if (i<d)  b[i]=1;  else  b[i]=0;
	for(int i=0; i<n; i++)  swap(b[i],b[getNextX()%(i+1)]);
}

void work()
{
	scanf("%d %d %lld",&n,&d,&x);
	initAB();
	for (int i=0; i<n; i++)  c[a[i]]=i;
	for (int i=0; i<n; i++)  if (b[i])  p[++p[0]]=i;
	int s=300;
	for (int i=0; i<n; i++)
		{
			int j;
			for (j=n; j>=n-s; j--)
				if ((j>0)&&(i>=c[j])&&(b[i-c[j]]))
					{printf("%d\n",j);  break;};
			if (j<n-s)
				{
					int Max=0;
					for (j=1; j<=p[0]&&p[j]<=i; j++)
						Max=max(Max,a[i-p[j]]);
					printf("%d\n",Max);
				}
		}
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
