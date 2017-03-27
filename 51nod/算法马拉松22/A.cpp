#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int n,T,m[1010],a[1010][1010],b[1010];
LL s;

int gi()
{
	int w=0;  char ch=getchar();
	while ((ch<'0')||('9'<ch))  ch=getchar();
	while (('0'<=ch)&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return w;
}

void work()
{
	n=gi();
	for (int i=1; i<=n; i++)
		{
			m[i]=gi();
			for (int j=1; j<=m[i]; j++)
				a[i][j]=gi();
			sort(a[i]+1,a[i]+m[i]+1);
		}
	T=gi();
	for (int i=1,j,l,s1,s2,k,p; i<=T; i++)
		{
			s1=gi(),s2=gi(),k=gi();
			s=1,p=0,k=min(k,m[s2]),j=1,l=1;
			for (; k; )
				{
					while ((j<=m[s1])&&(a[s1][j]<=s))  s+=a[s1][j++];
					while ((l<=m[s2])&&(a[s2][l]<=s))  b[++p]=a[s2][l++];
					s+=b[p--],k--;
				}
			while ((j<=m[s1])&&(a[s1][j]<=s))  s+=a[s1][j++];
			printf("%lld\n",s-1);
		}
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
