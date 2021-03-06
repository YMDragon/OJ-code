#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define Ls(n)  (n<<1)
#define Rs(n)  (Ls(n)|1)
#define lowbit(x)  (x&-x)
#define mp  make_pair
#define pb  push_back
#define FILENAME "D" 
using namespace std;

typedef long long  LL;
typedef pair<int,int>  PII;

int n,t[1010],s[1010],f[1010],ft[1010];

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d %d %d",&t[i],&s[i],&f[i]),ft[i]=fabs(s[i]-f[i])+t[i];
	for (int i=1; i<=n; i++)
		{
			int res=0;
			for (int j=1; j<=n; j++)
				if ((s[i]<f[i])!=(s[j]<f[j]))
					{
						int T=(s[i]<f[i])?(s[j]-s[i]+t[j]+t[i]):(s[i]+t[i]-s[j]+t[j]);
						if ((T>=t[i]*2)&&(T>=t[j]*2)&&(T<=ft[i]*2)&&(T<=ft[j]*2))  res++;
					}else
					{
						int tag=(s[i]<f[i])?(s[i]-t[i]==s[j]-t[j]):(s[i]+t[i]==s[j]+t[j]);
						if ((tag)&&(max(t[i],t[j])<=min(ft[i],ft[j])))
							res++;
					}
			printf("%d ",res-1);
		}
}

int main()
{
	freopen(FILENAME".in","r",stdin);
	freopen(FILENAME".out","w",stdout);
	work();
	return 0;
}
