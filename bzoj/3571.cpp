#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define oo  (1<<30)
using namespace std;

typedef int arr[75];
struct node{int A,B;};
int n,a[75][75],b[75][75],g[75][75];
arr visx,visy,matx,maty,dx,dy;
queue <int> Q;

bool find(int x)
{
	visx[x]=1;
	for (int y=1; y<=n; y++)
		if ((!visy[y])&&(dx[x]+dy[y]==g[x][y]))
			{
				visy[y]=1;
				if ((!maty[y])||(find(maty[y])))
					{
						maty[y]=x;
						return 1;
					}
			}
	return 0;
}

node KM()
{
	memset(maty,0,sizeof(maty));
	memset(dx,0,sizeof(dx)),memset(dy,0,sizeof(dy));
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			dx[i]=max(dx[i],g[i][j]);
	for (int i=1; i<=n; i++)
		for (;;)
			{
				memset(visx,0,sizeof(visx));
				memset(visy,0,sizeof(visy));
				if (find(i))  break;
				int delta=1<<30;
				for (int i=1; i<=n; i++)
					if (visx[i])
						for (int j=1; j<=n; j++)
							if (!visy[j])
								delta=min(delta,dx[i]+dy[j]-g[i][j]);
				for (int i=1; i<=n; i++)
					{
						if (visx[i])  dx[i]-=delta;
						if (visy[i])  dy[i]+=delta;
					}
			}
	node res=(node){0,0};
	for (int i=1; i<=n; i++)
		res.A+=a[maty[i]][i],res.B+=b[maty[i]][i];
	return res;
}

int work(node x,node y)
{
	int A=y.B-x.B,B=x.A-y.A,C=-(A*x.A+B*x.B);
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
			g[i][j]=A*a[i][j]+B*b[i][j];
  node mid=KM();
	if (A*mid.A+B*mid.B+C<=0)
    return min(x.A*x.B,y.A*y.B);
  return min(work(x,mid),work(mid,y));
}

void work()
{
  node x,y;
  scanf("%d",&n);
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
      scanf("%d",&a[i][j]);
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
      scanf("%d",&b[i][j]);
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
      g[i][j]=-a[i][j];
  x=KM();
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
      g[i][j]=-b[i][j];
  y=KM();
  printf("%d\n",work(x,y));
}

int main()
{
  freopen("3571.in","r",stdin);
  freopen("3571.out","w",stdout);
  int t;
  scanf("%d",&t);
  while (t--)  work();
  return 0;
}
