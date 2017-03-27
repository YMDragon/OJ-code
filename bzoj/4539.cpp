#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

typedef long long  LL;
typedef int  arr[100010];
struct edge{int s,t,n;}e[200010];
struct node{int rt,f;LL siz;};
struct Tnode{int s,ls,rs;}t[2000010];
int n,m,q,tot,f[100010][20],F[100010][20],rt[100010];
LL G[100010][20];
arr h,dfn,dfnr,dfsx,dep,Dep;
vector <node> V;

LL gi()
{
	LL w=0,q=1;  char ch=getchar();
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

bool cmp(node x,node y){return x.siz<y.siz;}

void dfs(int x,int fa)
{
	f[x][0]=fa,dfsx[++tot]=x,dfn[x]=tot,dep[x]=dep[fa]+1;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=fa)  dfs(y,x);
	dfnr[x]=tot;
}

void modify(int &n,int l,int r,int x)
{
	t[++tot]=t[n],n=tot,t[n].s++;
	if (l!=r)
		{
			int mid=(l+r)>>1;
			if (x<=mid)  modify(t[n].ls,l,mid,x);
			else  modify(t[n].rs,mid+1,r,x);
		}
}

int ask(int n1,int n2,int l,int r,int k)
{
	if (l==r)  return l;
	else
		{
			int mid=(l+r)>>1;
			if (k<=t[t[n1].ls].s-t[t[n2].ls].s)
				return ask(t[n1].ls,t[n2].ls,l,mid,k);
			else
				return ask(t[n1].rs,t[n2].rs,mid+1,r,k-(t[t[n1].ls].s-t[t[n2].ls].s));
		}
}

int get(int p,LL x)
{
	return ask(rt[dfnr[V[p].rt]],rt[dfn[V[p].rt]-1],1,n,x-(p?V[p-1].siz:0));
}

int dis(int x,int y)
{
	int res=0;
	if (dep[x]>dep[y])  swap(x,y);
	for (int i=19; i>=0; i--)
		if (dep[f[y][i]]>=dep[x])
			res+=(1<<i),y=f[y][i];
	if (x==y)  return res;
	for (int i=19; i>=0; i--)
		if (f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i],res+=(2<<i);
	return res+2;
}

LL getdis(LL x,LL y)
{
	LL res=0;
	int p,q;
	p=lower_bound(V.begin(),V.end(),(node){0,0,x},cmp)-V.begin();
	res+=dis(V[p].rt,get(p,x));
	q=lower_bound(V.begin(),V.end(),(node){0,0,y},cmp)-V.begin();
	res+=dis(V[q].rt,get(q,y));
	if (p==q)  return dis(get(p,x),get(q,y));
	if (Dep[p]>Dep[q])  swap(p,q),swap(x,y);
	for (int i=19; i>=0; i--)
		if (Dep[F[q][i]]>Dep[p])
			res+=G[q][i],q=F[q][i];
	if (p==F[q][0])
		{
			res-=dis(V[p].rt,get(p,x));
			return res+dis(get(p,x),V[q].f)+1;
		}else  if (Dep[p]!=Dep[q])  res+=G[q][0],q=F[q][0];
	for (int i=19; i>=0; i--)
		if (F[p][i]!=F[q][i])
			res+=G[p][i]+G[q][i],p=F[p][i],q=F[q][i];
	res+=dis(V[p].f,V[q].f)+2;
	return res;
}

void work()
{
	n=gi(),m=gi(),q=gi();
	for (int i=1,u,v,tot=0; i<n; i++)
		{
			u=gi(),v=gi();
			e[++tot]=(edge){u,v,h[u]},h[u]=tot;
			e[++tot]=(edge){v,u,h[v]},h[v]=tot;
		}
	dfs(1,0);
	for (int j=1; j<20; j++)
		for (int i=1; i<=n; i++)
			f[i][j]=f[f[i][j-1]][j-1];
	for (int i=1; i<=n; i++)
		rt[i]=rt[i-1],modify(rt[i],1,n,dfsx[i]);
	V.push_back((node){1,1,n});
	for (int i=1,u,x,f; i<=m; i++)
		{
			u=gi();
			LL v=gi();
			x=lower_bound(V.begin(),V.end(),(node){0,0,v},cmp)-V.begin();
			f=get(x,v);
			V.push_back((node){u,f,V[i-1].siz+dfnr[u]-dfn[u]+1});
			F[i][0]=x,G[i][0]=dis(V[x].rt,f)+1,Dep[i]=Dep[x]+1;
		}
	for (int j=1; j<20; j++)
		for (int i=1; i<=m; i++)
			F[i][j]=F[F[i][j-1]][j-1],G[i][j]=G[i][j-1]+G[F[i][j-1]][j-1];
	for (int i=1; i<=q; i++)
		pi(getdis(gi(),gi())),putchar('\n');
}

int main()
{
	freopen("4539.in","r",stdin);
	freopen("4539.out","w",stdout);
	work();
	return 0;
}
