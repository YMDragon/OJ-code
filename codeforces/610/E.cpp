#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define Ls(n)  (n<<1)
#define Rs(n)  (Ls(n)|1)
using namespace std;

struct node{int s[10][10],l,r,t;}t[800010];
int n,m,k;
char ch[200010];

void update(int n)
{
	for (int i=0; i<k; i++)
		for (int j=0; j<k; j++)
			t[n].s[i][j]=t[Ls(n)].s[i][j]+t[Rs(n)].s[i][j];
	t[n].s[t[Ls(n)].r][t[Rs(n)].l]++;
	t[n].l=t[Ls(n)].l,t[n].r=t[Rs(n)].r;
}

void push_down(int n)
{
	if (t[n].t!=-1)
		{
			int k=t[n].t;
			memset(t[Ls(n)].s,0,sizeof(t[Ls(n)].s));
			t[Ls(n)].l=t[Ls(n)].r=t[Ls(n)].t=t[n].t;
			t[Ls(n)].s[k][k]=(t[n].s[k][k]+1)/2;
			memset(t[Rs(n)].s,0,sizeof(t[Rs(n)]).s);
			t[Rs(n)].l=t[Rs(n)].r=t[Rs(n)].t=t[n].t;
			t[Rs(n)].s[k][k]=t[n].s[k][k]/2;
			t[n].t=-1;
		}
}

void build(int n,int l,int r)
{
	int mid=(l+r)>>1;
	t[n].t=-1,t[n].l=ch[l]-'a',t[n].r=ch[r]-'a';
	if (l!=r)  build(Ls(n),l,mid),build(Rs(n),mid+1,r),update(n);
}

void modify(int n,int l,int r,int L,int R,int k)
{
	if ((L<=l)&&(r<=R))
		memset(t[n].s,0,sizeof(t[n].s)),t[n].l=t[n].r=t[n].t=k,t[n].s[k][k]=r-l+1;
	else
		{
			int mid=(l+r)>>1;
			push_down(n);
			if (L<=mid)  modify(Ls(n),l,mid,L,R,k);
			if (mid<R)  modify(Rs(n),mid+1,r,L,R,k);
			update(n);
		}
}

void work()
{
	scanf("%d %d %d\n%s",&n,&m,&k,ch+1);
	build(1,1,n);
	for (int i=1,ty,l,r,ans; i<=m; i++)
		{
			scanf("%d",&ty);
			if (ty==1)
				{
					scanf("%d %d %c",&l,&r,&ch[0]);
					modify(1,1,n,l,r,ch[0]-'a');
				}else
				{
					scanf("%s",ch+1),ans=n;
					for (int i=1; i<=k; i++)
						for (int j=i+1; j<=k; j++)
							ans-=t[1].s[ch[i]-'a'][ch[j]-'a'];
					printf("%d\n",ans);
				}
		}
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
