#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <map>
using namespace std;

typedef long long  LL;
const int mo1=int(1e9+7),mo2=int(1e9-63),mo3=998244353;
struct edge{int s,t,w,n;}e[200010];
struct hash{int x,y,z;}a[100010];
int n,h[100010],fac[100010][100];
bitset <100000000> b;
map <int,int> M;
LL ans;

int gcd(int a,int b){return b?gcd(b,a%b):a;}

int ksm(int a,int b,int mo)
{
	int x=a;  a=1;
	while (b)
    {
			if (b&1)  a=1LL*a*x%mo;
			x=1LL*x*x%mo,b>>=1;
    }
	return a;
}

bool Miller_Rabin(int n)
{
	if(n==2)  return 1;
	if((n<2)||(!(n&1)))  return 0;
	int m=n-1,k=0;
	while(!(m&1))  k++,m>>=1;
	for (int i=0; i<10; i++)
    {
			int a=rand()%(n-1)+1,x=ksm(a,m,n),y=0;
			for (int j=0; j<k; j++)
        {
					y=1LL*x*x%n;
					if ((y==1)&&(x!=1)&&(x!=n-1))  return 0;
					x=y;
        }
			if (y!=1)  return 0;
    }
	return 1;
}

int pollard_rho(int n,int c)
{
	int i=1,k=2,x=rand()%(n-1)+1,y=x;
	while (1)
    {
			i++,x=(1LL*x*x+c)%n;
			int d=gcd((y-x+n)%n,n);
			if ((1<d)&&(d<n))  return d;
			if (y==x)  return n;
			if (i==k)  y=x,k<<=1;
    }
}

void find(int n)
{  
	if (n==1)  return;
	if (Miller_Rabin(n))  {fac[0][++fac[0][0]]=n;  return;}
	int p=n;
	while (p>=n)  p=pollard_rho(p,rand()%n+1);
	find(p),find(n/p);
}

void factor(int x,int w)
{
	if (M[w])
		{
			int y=M[w];
			for (int j=0; j<=fac[y][0]; j++)  fac[x][j]=fac[y][j];
			return;
		}
	fac[0][0]=0,find(w);
	sort(fac[0]+1,fac[0]+fac[0][0]+1);
	for (int j=1,l; j<=fac[0][0]; j++)
		{
			l=j;
			while ((j<fac[0][0])&&(fac[0][j]==fac[0][j+1]))  j++;
			if (!((j-l)&1))  fac[x][++fac[x][0]]=fac[0][j];
		}
	M[w]=x;
}

void mul(int x,int t)
{
	if (t>0)
		a[x]=(hash){1LL*a[x].x*t%mo1,1LL*a[x].y*t%mo2,1LL*a[x].z*t%mo3};
	else
		a[x]=(hash){1LL*a[x].x*ksm(-t,mo1-2,mo1)%mo1,1LL*a[x].y*ksm(-t,mo2-2,mo2)%mo2,1LL*a[x].z*ksm(-t,mo3-2,mo3)%mo3};
}

void dfs(int x,int f)
{
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=f)
			{
				factor(y,e[i].w),a[y]=a[x];
				for (int j=1,t; j<=fac[y][0]; j++)
					if (b[t=fac[y][j]])  mul(y,-t),b[t]=0;
					else  mul(y,t),b[t]=1;
				dfs(y,x);
				for (int j=1,t; j<=fac[y][0]; j++)
					if (b[t=fac[y][j]])  b[t]=0;
					else  b[t]=1;
			}
}

bool cmp(hash x,hash y)
{
	if (x.x!=y.x)  return x.x<y.x;
	if (x.y!=y.y)  return x.y<y.y;
	return x.z<y.z;
}

void work()
{
	scanf("%d",&n);
	for (int i=1,u,v,w,tot=0; i<n; i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			e[++tot]=(edge){u,v,w,h[u]},h[u]=tot;
			e[++tot]=(edge){v,u,w,h[v]},h[v]=tot;
		}
	a[1]=(hash){1,1,1};
	dfs(1,0);
	sort(a+1,a+n+1,cmp);
	for (int i=1,l; i<=n; i++)
		{
			l=i;
			while ((i<n)&&(a[i].x==a[i+1].x)&&(a[i].y==a[i+1].y)&&(a[i].z==a[i+1].z))  i++;
			ans+=1LL*(i-l+1)*(i-l);
		}
	cout<<ans;
}

int main()
{
	freopen("192.in","r",stdin);
	freopen("192.out","w",stdout);
	work();
	return 0;
}
