#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,dfs[200010],bfs[200010],pos[200010],b[200010],s[200010],res[200010];
double ans;

void work()
{
	scanf("%d",&n),ans=1;
	for (int i=1; i<=n; i++)  scanf("%d",&dfs[i]);
	for (int i=1; i<=n; i++)  scanf("%d",&bfs[i]),pos[bfs[i]]=i;
	for (int i=1; i<=n; i++)  dfs[i]=pos[dfs[i]];
	for (int i=1; i<=n; i++)  pos[dfs[i]]=i;
	b[1]=1,res[1]++,res[2]--;
	for (int i=2; i<n; i++)  if (pos[i]>pos[i+1])  b[i]=1;
	for (int i=1; i<n; i++)  s[i]=s[i-1]+b[i];
	for (int i=2,sum; i<n; i++)
		if (dfs[i]<dfs[i+1])
			{
				sum=s[dfs[i+1]-1]-s[dfs[i]-1];
				if (sum)  res[dfs[i]]++,res[dfs[i+1]]--;
			}
	for (int i=1,sum=0; i<n; i++)
		{
			sum+=res[i];
			if (sum)  ans+=b[i];  else  ans+=0.5;
		}
	printf("%.3lf\n",ans);
}

int main()
{
	freopen("122.in","r",stdin);
	freopen("122.out","w",stdout);
	work();
	return 0;
}
