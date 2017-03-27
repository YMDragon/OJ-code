#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const int N=300010;
int n,arr1[2*N],arr2[2*N],c[N],sa[N],rk[N],hei[N],ST1[N][20],Log2[N];
char s[N];
LL a[N],ans[N][2],ST2[N][20][2];

LL getLL()
{
	LL w=0,q=1;  char ch=getchar();
	while (((ch<'0')||(ch>'9'))&&(ch!='-'))  ch=getchar();
	if (ch=='-')  q=0,ch=getchar();
	while (('0'<=ch)&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return q?w:-w;
}

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

int minh(int x,int y){return hei[x]<hei[y]?x:y;}
int get1(int l,int r)
{
	int Loglen=Log2[r-l];
	return minh(ST1[l][Loglen],ST1[r-(1<<Loglen)][Loglen]);
}

LL get2(int l,int r)
{
	int Loglen=Log2[r-l+1];
	return max(ST2[l][Loglen][0],ST2[r-(1<<Loglen)+1][Loglen][0]);
}

LL get3(int l,int r)
{
	int Loglen=Log2[r-l+1];
	return min(ST2[l][Loglen][1],ST2[r-(1<<Loglen)+1][Loglen][1]);
}

void upd(LL &x,LL y){if (x<y)  x=y;}

void dfs(int l,int r)
{
	if (r-l+1==1)  return;
	int x=get1(l,r);
	ans[hei[x]][0]+=1LL*(x-l+1)*(r-x);
	upd(ans[hei[x]][1],get2(l,x)*get2(x+1,r));
	upd(ans[hei[x]][1],get3(l,x)*get3(x+1,r));
	dfs(l,x),dfs(x+1,r);
}

void work()
{
	scanf("%d\n",&n);
	scanf("%s",s+1);
	Suffix_Array();
	for (int i=1; i<=n; i++)  a[i]=getLL(),ans[i-1][1]=-(1LL<<60);
	for (int i=1; i<=n; i++)
		ST1[i][0]=i,ST2[i][0][0]=a[sa[i]],ST2[i][0][1]=a[sa[i]],hei[i]=hei[i+1];
	for (int j=1; j<20; j++)
		for (int i=1; i+(1<<j)<=n+1; i++)
			{
				ST1[i][j]=minh(ST1[i][j-1],ST1[i+(1<<(j-1))][j-1]);
				ST2[i][j][0]=max(ST2[i][j-1][0],ST2[i+(1<<(j-1))][j-1][0]);
				ST2[i][j][1]=min(ST2[i][j-1][1],ST2[i+(1<<(j-1))][j-1][1]);
			}
	Log2[0]=-1;
	for (int i=1; i<=n; i++)  Log2[i]=Log2[i/2]+1;
	dfs(1,n);
	for (int i=n-2; i>=0; i--)  ans[i][0]+=ans[i+1][0],upd(ans[i][1],ans[i+1][1]);
	for (int i=0; i<n; i++)
		if (ans[i][0])  printf("%lld %lld\n",ans[i][0],ans[i][1]);
		else  printf("0 0\n");
}

int main()
{
	freopen("4199.in","r",stdin);
	freopen("4199.out","w",stdout);
	work();
	return 0;
}
