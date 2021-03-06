#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,mid,ch[255][2],a[255],siz[255],f[255][2][3],vis[255][2][3];

int dfs(int x)
{
	if (a[x]!=-1)  return siz[x]=0;
	siz[x]=dfs(ch[x][0])+dfs(ch[x][1])+1;
	if (siz[ch[x][1]]&1)  swap(ch[x][0],ch[x][1]);
	return siz[x];
}

bool merge(bool x,bool y,bool p)
{
	if (p)  return x&y;
	else  return x|y;
}

/*int merge(int x,int y,bool p)
	{
	if (p)  return x<y?x:y;
	else  return x>y?x:y;
	}*/

bool dp(int n,int p,int s)
{
	if (a[n]!=-1)  return a[n]>=mid;
	if (siz[n]==1)  return merge(a[ch[n][0]]>=mid,a[ch[n][1]]>=mid,p^(s==2));
	if (vis[n][p][s])  return f[n][p][s];
	vis[n][p][s]=1;
	if (s)
		{
			if (!(siz[ch[n][0]]&1))  //even-even-canskip
				{
					f[n][p][s]=dp(n,!p,0);
					if (siz[ch[n][0]])
						f[n][p][s]=merge(f[n][p][s],merge(dp(ch[n][0],p,siz[ch[n][1]]==0&&s==1?2:1),dp(ch[n][1],!p,0),!p),p);
					if (siz[ch[n][1]])
						f[n][p][s]=merge(f[n][p][s],merge(dp(ch[n][1],p,siz[ch[n][0]]==0&&s==1?2:1),dp(ch[n][0],!p,0),!p),p);
				}else  if (siz[ch[n][1]]&1)  //odd-odd-canskip
				{
					f[n][p][s]=dp(n,!p,0);
					f[n][p][s]=merge(f[n][p][s],merge(dp(ch[n][0],!p,siz[ch[n][1]]==1&&s==1?2:1),dp(ch[n][1],p,0),!p),p);
					f[n][p][s]=merge(f[n][p][s],merge(dp(ch[n][1],!p,siz[ch[n][0]]==1&&s==1?2:1),dp(ch[n][0],p,0),!p),p);
				}else  //odd-even-canskip
				{
					f[n][p][s]=merge(dp(ch[n][1],p,0),dp(ch[n][0],p,siz[ch[n][1]]==0&&s==1?2:1),p);
				}
		}else
		{
			if (!(siz[ch[n][0]]&1)) //even-even-noskip
				f[n][p][s]=merge(dp(ch[n][0],p,0),dp(ch[n][1],p,0),p);
			else if (siz[ch[n][1]]&1)  //odd-odd-noskip
				f[n][p][s]=merge(dp(ch[n][0],p,1),dp(ch[n][1],p,1),p);
			else  //odd-even-noskip
				{
					f[n][p][s]=merge(merge(dp(ch[n][0],p,0),dp(ch[n][1],!p,0),!p),merge(dp(ch[n][1],p,1),dp(ch[n][0],!p,1),!p),p);
				}
		}
	return f[n][p][s];
}

void work()
{
	scanf("%d",&n);
	for (int i=0; i<n; i++)
		{
			scanf("%d",&a[i]);
			if (a[i]==-1)  scanf("%d %d",&ch[i][0],&ch[i][1]);
		}
	dfs(0);
	int l=0,r=1001;
	while (r-l>1)
		{
			memset(vis,0,sizeof(vis)),mid=(l+r)>>1;
			if (dp(0,0,0))  l=mid;  else  r=mid;
		}
	printf("%d\n",l);
	//memset(vis,0,sizeof(vis));
	//printf("%d\n",dp(0,0,0));
}

int main()
{
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
