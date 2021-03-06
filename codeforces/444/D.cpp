#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define LL  long long
#define oo  (1<<30)
#include <vector>
#include <map>
using namespace std;

char ch[50010];
int n,q,tot,tv,h[600010],s[200010],t[200010];
vector <int> V[200010];
map <int,int> M[200010];

int ins(int x){if (!h[x])  h[x]=++tv;  return h[x];}

int getstr()
{
	int w=0;
	char ch=getchar();
	while ((ch<'a')||(ch>'z'))  ch=getchar();
	while ((ch>='a')&&(ch<='z'))  w=w*27+ch-'a'+1,ch=getchar();
	return w;
}

bool cmp(int x,int y){return s[x]<s[y];}

int solve(int x,int y)
{
	int s0=min(s[x],s[y]),t0=max(t[x],t[y]);
	return t0-s0+1;
}

void work()
{
	scanf("%s %d\n",ch+1,&q),n=strlen(ch+1);
	for (int i=1; i<=n; i++)
		for (int j=1,k,ha=0; k=i+j-1,j<=4&&k<=n; j++)
			s[++tot]=i,t[tot]=k,V[ins(ha=ha*27+ch[k]-'a'+1)].push_back(tot);
	for (int i=1; i<=q; i++)
		{
			int a=getstr(),b=getstr(),ha=h[a],hb=h[b];
			if ((!ha)||(!hb))  {printf("-1\n");  continue;}
			int Min=min(ha,hb),Max=max(ha,hb);
			if (M[Min].find(Max)!=M[Min].end())  {printf("%d\n",M[Min][Max]);  continue;}
			int ans=oo;
			for (int j=0; j<int(V[ha].size()); j++)
				{
					int p=lower_bound(V[hb].begin(),V[hb].end(),V[ha][j])-V[hb].begin();
					for (int k=max(0,p-1),l=min(int(V[hb].size()),p+1); k<l; k++)
						ans=min(ans,solve(V[ha][j],V[hb][k]));
				}
			M[Min][Max]=ans;
			printf("%d\n",ans);
		}
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	work();
	return 0;
}
