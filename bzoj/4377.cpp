#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct node{int l,r;}c[3000000];
int n,a,b,p,m,tot,ans;
char ch[1000010];

bool cmp(node x,node y){return (x.l<y.l)||((x.l==y.l)&&(x.r<y.r));}

void work()
{
	scanf("%d %d %d %d %d\n%s",&n,&a,&b,&p,&m,ch);
	for (int i=0,l,r; i<m; i++)
		{
			if (ch[i]=='0')  l=0,r=p-1;  else  l=p,r=n-1;
			(l+=(n-1LL*a*i%n))%=n,(r+=(n-1LL*a*i%n))%=n;
			if (l<=r)
				{
					if (l!=0)  c[++tot]=(node){0,l-1};
					if (r!=n-1)  c[++tot]=(node){r+1,n-1};
				}else  if (l-r>1)  c[++tot]=(node){r+1,l-1};
		}
	for (int i=n-m+1; i<n; i++)  c[++tot]=(node){(1LL*a*i+b)%n,(1LL*a*i+b)%n};
	sort(c+1,c+tot+1,cmp);
	for (int i=1,r=-1; i<=tot; i++)
		{
			ans+=max(0,c[i].l-r-1),r=max(r,c[i].r);
			if (i==tot)  ans+=n-r-1;
		}
	printf("%d",ans);
}

int main()
{
	freopen("4377.in","r",stdin);
	freopen("4377.out","w",stdout);
	work();
	return 0;
}
