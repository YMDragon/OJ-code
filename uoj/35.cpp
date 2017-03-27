#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int N=100010;

char ch[N];
int arr1[2*N],arr2[2*N],c[N],sa[N],rk[N],hei[N];

void Suffix_Array(char *s,int *sa,int *rk,int *hei)
{
	int n=strlen(s+1),m=26,*x=arr1,*y=arr2;
	for (int i=1; i<=n; i++)  c[x[i]=s[i]-'a'+1]++;
	for (int i=1; i<=m; i++)  c[i]+=c[i-1];
	for (int i=1; i<=n; i++)  sa[c[x[i]]--]=i;
	for (int k=1; k<n; k<<=1)
		{
			int yt=0;
			for (int i=n-k+1; i<=n; i++)  y[++yt]=i;
			for (int i=1; i<=n; i++)
				if (sa[i]-k>=1)  y[++yt]=sa[i]-k;
			for (int i=1; i<=m; i++)  c[i]=0;
			for (int i=1; i<=n; i++)  c[x[i]]++;
			for (int i=1; i<=m; i++)  c[i]+=c[i-1];
			for (int i=n; i; i--)  sa[c[x[y[i]]]--]=y[i];
			m=0;
			for (int i=1; i<=n; i++)
				{
					int u=sa[i],v=sa[i-1];
					if ((i==1)||(x[u]!=x[v])||(x[u+k]!=x[v+k]))  m++;
					y[u]=m;
				}
			if (m>=n)  break;
			swap(x,y);
		}
	for (int i=1; i<=n; i++)  rk[sa[i]]=i;
	for (int i=1,h=0; i<=n; i++)
	 	{
	 		h=max(h-1,0);
	 		if (rk[i]==1)  continue;
	 		int j=sa[rk[i]-1];
	 		while ((i+h<=n)&&(j+h<=n)&&(s[i+h]==s[j+h]))  h++;
	 		hei[rk[i]]=h;
	 	}
}

void work()
{
	scanf("%s",ch+1);
	Suffix_Array(ch,sa,rk,hei);
	int n=strlen(ch+1);
	for (int i=1; i<=n; i++)  printf("%d ",sa[i]);
	printf("\n");
	for (int i=2; i<=n; i++)  printf("%d ",hei[i]);
}

int main()
{
	freopen("35.in","r",stdin);
	freopen("35.out","w",stdout);
	work();
	return 0;
}
