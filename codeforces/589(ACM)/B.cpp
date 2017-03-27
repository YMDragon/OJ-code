#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define Ls(n)  (n<<1)
#define Rs(n)  (Ls(n)|1)
#define lowbit(x)  (x&-x)
#define mp  make_pair
#define pb  push_back
#define FILENAME "B" 
using namespace std;

typedef long long  LL;
typedef pair<int,int>  PII;

struct node{int a,b;}a[4010];
int n,b[4010],X,Y;
LL ans;

bool cmp(node x,node y){return x.a>y.a;}
void upd(int x,int y,int h){if (1LL*x*y*h>ans)  ans=1LL*x*y*h,X=x,Y=y;}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		{
			scanf("%d %d",&a[i].a,&a[i].b);
			if (a[i].a<a[i].b)  swap(a[i].a,a[i].b);
		}
	sort(a+1,a+n+1,cmp);
	for (int i=1,j; i<=n; i++)
		{
			for (j=i-1; j&&b[j]<=a[i].b; j--)  b[j+1]=b[j];
			b[++j]=a[i].b;
			for (; j<=i; j++)  upd(a[i].a,b[j],j);
		}
	cout<<ans<<endl<<X<<' '<<Y<<endl;
}

int main()
{
	freopen(FILENAME".in","r",stdin);
	freopen(FILENAME".out","w",stdout);
	work();
	return 0;
}
