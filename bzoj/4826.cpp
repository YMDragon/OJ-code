#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define Ls(n)  (n<<1)
#define Rs(n)  (Ls(n)|1)
using namespace std;

typedef long long  LL;
typedef pair <int,int>  PII;
int n,m,p1,p2,k[200010],a[200010];
LL ans[200010],t[800010],t2[800010];
vector <PII> L[200010],R[200010];

int gi()
{
	int w=0,q=1;  char ch=getchar();
	while (((ch<'0')||('9'<ch))&&(ch!='-'))  ch=getchar();
	if (ch=='-')  q=0,ch=getchar();
	while (('0'<=ch)&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return q?w:-w;
}

void pi(LL x)
{
	if (x<0)  putchar('-'),x=-x;
	if (x>9)  pi(x/10);
	putchar(x%10+'0');
}

void clear(int n,int l,int r)
{
	t[n]=t2[n]=0;
	if (l!=r)
		{
			int mid=(l+r)>>1;
			clear(Ls(n),l,mid),clear(Rs(n),mid+1,r);
		}
}

void modify(int n,int l,int r,int L,int R,int k1,int k2)
{
	if ((L<=l)&&(r<=R))
		t[n]+=k1,t2[n]+=k2;
	else
		{
			int mid=(l+r)>>1;
			if (L<=mid)  modify(Ls(n),l,mid,L,R,k1,k2);
			if (mid<R)  modify(Rs(n),mid+1,r,L,R,k1,k2);
		}
}

LL ask(int n,int l,int r,int x)
{
	LL res=t[n]*x+t2[n];
	if (l!=r)
		{
			int mid=(l+r)>>1;
			res+=(x<=mid?ask(Ls(n),l,mid,x):ask(Rs(n),mid+1,r,x));
		}
	return res;
}

void work()
{
	n=gi(),m=gi(),p1=gi(),p2=gi();
	for (int i=1; i<=n; i++)  k[i]=gi();
	for (int i=1,l,r; i<=m; i++)
		{
			l=gi(),r=gi();
			L[r].push_back(make_pair(l,i));
			R[l].push_back(make_pair(r,i));
		}
	for (int i=1,top=0; i<=n; i++)
		{
			while ((top)&&(k[a[top]]<k[i]))
				modify(1,1,n,1,a[top],0,p1-p2),top--;
			if (top)  modify(1,1,n,1,a[top],0,p2*(i-a[top]-1));
			modify(1,1,n,a[top]+1,i,-p2,p2*i);
			a[++top]=i;
			for (int j=0; j<L[i].size(); j++)
				ans[L[i][j].second]+=ask(1,1,n,L[i][j].first);
		}
	clear(1,1,n),a[0]=n+1;
	for (int i=n,top=0; i; i--)
		{
			while ((top)&&(k[a[top]]<k[i]))
				modify(1,1,n,a[top],n,0,p1-p2),top--;
			if (top)  modify(1,1,n,a[top],n,0,p2*(a[top]-i-1));
			modify(1,1,n,i,a[top]-1,p2,-p2*i);
			a[++top]=i;
			for (int j=0; j<R[i].size(); j++)
				ans[R[i][j].second]+=ask(1,1,n,R[i][j].first);
		}
	for (int i=1; i<=m; i++)  pi(ans[i]),puts("");
}

int main()
{
	freopen("4826.in","r",stdin);
	freopen("4826.out","w",stdout);
	work();
	return 0;
}
