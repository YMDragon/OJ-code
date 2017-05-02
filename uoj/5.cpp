#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=int(1e9+7);
struct edge{int s,t,n;}e[1000010];
int n,m,next[1000010],h[1000010],b[1000010],ans;
char S[1000010];

void dfs(int x)
{
	if (x)
		{
			int l=0,r=m+1,mid;
			for (; r-l>1; b[mid=(l+r)>>1]<=x/2?l=mid:r=mid);
			ans=(1LL*ans*(l+1)%mo);
			b[++m]=x;
		}
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		dfs(y);
	if (m)  m--;
}

void work()
{
	scanf("%s",S+1),n=strlen(S+1),ans=1;
	next[1]=0;
	for (int i=2,j=1; i<=n; i++)
		{
			while ((j>1)&&(S[i]!=S[j]))  j=next[j-1]+1;
			if (S[i]==S[j])  j++;
			next[i]=j-1;
		}
	for (int i=0; i<=n; i++)  h[i]=0;
	for (int i=1; i<=n; i++)
		e[i]=(edge){next[i],i,h[next[i]]},h[next[i]]=i;
	dfs(0);
	printf("%d\n",ans);
}

int main()
{
	freopen("5.in","r",stdin);
	freopen("5.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
