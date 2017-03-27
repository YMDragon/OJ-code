#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const int N=300010;
int n,arr1[2*N],arr2[2*N],c[N],sa[N],rk[N],hei[N],ST[N][20],Log2[N];
LL ans;
char s[N];

void Suffix_Array()
{
	int m=26,*x=arr1,*y=arr2;
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

void ST_prepare()
{
	for (int i=1; i<=n; i++)  ST[i][0]=hei[i+1],Log2[i]=log2(i);;
	for (int j=1; j<20; j++)
		for (int i=1; i+(1<<(j-1))<=n; i++)
			ST[i][j]=min(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
}

int ST_ask(int l,int r)
{
	int loglen=Log2[r-l+1];
	return min(ST[l][loglen],ST[r+1-(1<<loglen)][loglen]);
}

void solve(int s,int len)
{
	int x=rk[s],l=x,r=x,res=1;
	for (int i=19; i>=0; i--)
		if ((l>(1<<i))&&(ST[l-(1<<i)][i]>=len))  l-=(1<<i);
	res+=x-l;
	for (int i=19; i>=0; i--)
		if ((r+(1<<i)<=n)&&(ST[r][i]>=len))  r+=(1<<i);
	res+=r-x;
	ans=max(ans,1LL*len*res);
}

void Manachar()
{
	int m=2*n+1;
	for (int i=1; i<=n; i++)  arr1[2*i]=s[i],arr1[2*i-1]=0;
	arr1[m]=0;
	for (int i=1,id=0,p=0,j; j=2*id-i,i<=m; i++)
		{
			arr2[i]=(j<0)?1:min(arr2[j],id+p-i);
			while ((arr2[i]<i)&&(i+arr2[i]<=m)&&(arr1[i-arr2[i]]==arr1[i+arr2[i]]))
				{
					if (!((i+arr2[i])&1))  solve((i-arr2[i])/2,arr2[i]+1);
					arr2[i]++;
				}
			if (i+arr2[i]>id+p)  id=i,p=arr2[i];
		}
}


void work()
{
	scanf("%s",s+1),n=strlen(s+1);
	Suffix_Array();
	ST_prepare();
	Manachar();
	printf("%lld",ans);
}

int main()
{
	freopen("103.in","r",stdin);
	freopen("103.out","w",stdout);
	work();
	return 0;
}
