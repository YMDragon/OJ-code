#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int n,p[305],a[305][305],f[305],g[305];
vector <int> V[305];

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",&p[i]),f[i]=i;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			{
				char ch=getchar();
				while ((ch!='0')&&(ch!='1'))  ch=getchar();
				a[i][j]=ch-'0';
				if ((a[i][j])&&(find(i)!=find(j)))  f[f[i]]=f[j];
			}
	for (int i=1; i<=n; i++)
		V[find(i)].push_back(p[i]),g[i]=V[find(i)].size();
	for (int i=1; i<=n; i++)
		sort(V[i].begin(),V[i].end());
	for (int i=1; i<=n; i++)
		printf("%d ",V[find(i)][g[i]-1]);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
