#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long LL;
struct node{LL l,r;}a[200010];
int h,q,tot;
LL ans;

bool cmp(node x,node y){return x.l<y.l;}

void work()
{
	scanf("%d %d",&h,&q);
	for (int i=1; i<=q; i++)
		{
			int I,ans;  LL l,r;
			scanf("%d %lld %lld %d",&I,&l,&r,&ans);
			if (ans)
				{
					if (l!=(1LL<<(I-1)))  a[++tot]=(node){1LL<<(h-1),(l<<(h-I))-1};
					if (r!=(1LL<<I)-1)  a[++tot]=(node){(r+1)<<(h-I),(1LL<<h)-1};
				}else
				a[++tot]=(node){l<<(h-I),((r+1)<<(h-I))-1};
		}
	sort(a+1,a+tot+1,cmp);
	a[tot+1]=(node){1LL<<h,1LL<<h};
	LL r=(1LL<<(h-1))-1;
	for (int i=1; i<=tot+1; i++)
		{
			if (a[i].l-r>2)  {printf("Data not sufficient!");  return;}
			if (a[i].l-r==2)
				{
					if (!ans)  ans=r+1;
					else  {printf("Data not sufficient!");  return;}
				}
			r=max(r,a[i].r);
		}
	if (!ans)  printf("Game cheated!");
	else  printf("%lld",ans);
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
