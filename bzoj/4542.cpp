#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

typedef long long  LL;
typedef pair<int,int>  PII;
typedef long double  LDB;

const int siz=100;
struct Pair{int x,y;}a[100010];
int n,m,p,tot,hs[100010],b[100010];
LL dotsum[1010][1010],sqrsum[100010];
char ch[100010];
vector <int> V[100010];

int gi()
{
	int w=0,q=1;  char ch=getchar();
	while (((ch<'0')||('9'<ch))&&(ch!='-'))  ch=getchar();
	if (ch=='-')  q=0,ch=getchar();
	while (('0'<=ch)&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return q?w:-w;
}

void pi(LL x)
{
	if (x<0)  putchar('-'),x=-x;
	if (x>9)  pi(x/10);
	putchar(x%10+'0');
}

bool cmp(Pair x,Pair y){return (x.x<y.x);}

int ask(int x,int k)
{
	if (V[k][0]>x)  return 0;
	int l=0,r=V[k].size(),mid;
	for (; r-l>1; V[k][mid=(l+r)>>1]<=x?l=mid:r=mid);
	return l+1;
}

void p25()
{
	for (int i=1; i<=n; i++)
		if ((ch[i]-'0')%p==0)
			V[0].push_back(i);
	sqrsum[0]=V[0][0];
	for (int i=1; i<V[0].size(); i++)  sqrsum[i]=sqrsum[i-1]+V[0][i];
	m=gi();
	V[0].push_back(n+1);
	for (int i=1,l,r,x,y; i<=m; i++)
		{
			l=gi(),r=gi();
			x=lower_bound(V[0].begin(),V[0].end(),l)-V[0].begin();
			y=upper_bound(V[0].begin(),V[0].end(),r)-V[0].begin()-1;
			pi(sqrsum[y]-(x?sqrsum[x-1]:0)-1LL*(l-1)*(y-x+1)),putchar('\n');
		}
}

void work()
{
	scanf("%d\n%s",&p,ch+1),n=strlen(ch+1);
	if (10%p==0)  return p25();
	for (int i=1; i<=n; i++)  hs[i]=(10LL*hs[i-1]+ch[i]-'0')%p;
	for (int i=n,t=1; i; i--)  hs[i]=1LL*hs[i]*t%p,t=10LL*t%p;
	for (int i=0; i<=n; i++)  a[i]=(Pair){hs[i],i};
	sort(a,a+n+1,cmp),a[n+1].x=p;
	for (int i=0,t=0; i<=n; i++)
		if (a[i].x==a[i+1].x)  hs[a[i].y]=t;
		else  hs[a[i].y]=t,t++;
	for (int i=0; i<=n; i++)
		V[hs[i]].push_back(i),sqrsum[i]=sqrsum[i-1]+(2*V[hs[i]].size()-1);
	for (int i=0; i<=n/siz; i++)
		{
			LL sum=0;
			memset(b,0,sizeof(b));
			for (int j=0; j<=i*siz; j++)
				b[hs[j]]++;
			for (int j=0; j<=n; j++)
				{
					sum+=b[hs[j]];
					if (j%siz==0)  dotsum[i][j/siz]=sum;
				}
		}
	m=gi();
	for (int i=1,l,r,L,R; i<=m; i++)
		{
			l=gi()-2,r=gi();
			if (l==-1)  {pi((sqrsum[r]-(r+1))/2),putchar('\n');  continue;}
			L=l/siz,R=r/siz;
			LL ans=(sqrsum[r]+sqrsum[l]-(r-l))/2-dotsum[L][R];
			for (int j=L*siz+1; j<=l; j++)
				ans-=ask(R*siz,hs[j]);
			for (int j=R*siz+1; j<=r; j++)
				ans-=ask(l,hs[j]);
			pi(ans),putchar('\n');
		}
}

int main()
{
	freopen("4542.in","r",stdin);
	freopen("4542.out","w",stdout);
	work();
	return 0;
}
