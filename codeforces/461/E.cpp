#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const LL oo=1LL<<60;
struct node{int ch[4],par,len,vis;  LL min[4];}t[200010];
LL n;
int len,root,last,tot;
char ch[100010];

void min(int &x,int y){if (x>y)  x=y;}
void min(LL &x,LL y){if (x>y)  x=y;}

void extand(int c)
{
	int p=last,np=++tot;
	t[np].len=t[p].len+1,last=np;
	for (; p&&(!t[p].ch[c]); p=t[p].par)  t[p].ch[c]=np;
	if (!p)  t[np].par=root;
	else
		{
			int q=t[p].ch[c];
			if (t[p].len+1==t[q].len)  t[np].par=q;
			else
				{
					int nq=++tot;
					t[nq]=t[q],t[nq].len=t[p].len+1;
					t[np].par=t[q].par=nq;
					for (; p&&t[p].ch[c]==q; p=t[p].par)  t[p].ch[c]=nq;
				}
		}
}

void dfs(int x)
{
	if ((!x)||(t[x].vis))  return;
	t[x].vis=1;
	for (int i=0; i<4; i++)  dfs(t[x].ch[i]),t[x].min[i]=oo;
	for (int i=0; i<4; i++)
		if (!t[x].ch[i])  t[x].min[i]=1;
		else  for (int j=0; j<4; j++)  min(t[x].min[j],t[t[x].ch[i]].min[j]+1);
}

bool check(LL x)
{
	LL f[4]={1,1,1,1},dp[4][4];
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			dp[i][j]=t[t[root].ch[i]].min[j];
	while (x)
		{
			if (x&1)
				{
					LL nf[4]={oo,oo,oo,oo};
					for (int i=0; i<4; i++)
						for (int j=0; j<4; j++)
							min(nf[j],f[i]+dp[i][j]);
					memcpy(f,nf,sizeof(f));
				}
			LL ndp[4][4];
			for (int i=0; i<4; i++)  for (int j=0; j<4; j++)  ndp[i][j]=oo;
			for (int i=0; i<4; i++)
				for (int j=0; j<4; j++)
					for (int k=0; k<4; k++)
						min(ndp[i][j],dp[i][k]+dp[k][j]);
			memcpy(dp,ndp,sizeof(dp));
			x>>=1;
		}
	for (int i=0; i<4; i++)
		if (f[i]<=n)  return 1;
	return 0;
}

void work()
{
	cin>>n,scanf("%s",ch+1),len=strlen(ch+1);
	root=last=1,tot=1;
	for (int i=1; i<=len; i++)  extand(ch[i]-'A');
	dfs(root);
	LL l=0,r=n+1,mid;
	for (; r-l>1; check(mid=(l+r)>>1)?l=mid:r=mid);
	cout<<r;
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
