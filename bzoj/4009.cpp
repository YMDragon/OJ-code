#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct edge{int s,t,n;}e[200010];
struct plate{int xl,xr,yl,yr,k;}b[200010];
struct fruit{int x,y,k,ans,id;}a[100010];
struct node{int x,y1,y2,ty;}c[500010];
int n,p,q,cnt,m,h[100010],id[100010][2],f[100010][20],boo[100010];

struct BIT{
	int t[100010];
	void add(int x,int k){for (; x<=n; x+=x&-x)  t[x]+=k;}
	int ask(int x){int res=0;  for (; x; x-=x&-x)  res+=t[x]; return res;}
}Bit;

void dfs(int x,int fa)
{
	id[x][0]=++cnt,f[x][0]=fa;
	for (int i=h[x]; i; i=e[i].n)
		if (e[i].t!=fa)  dfs(e[i].t,x);
	id[x][1]=cnt;
}

int find(int x,int y)
{
	for (int i=19; i>=0; i--)
		if ((id[y][0]<id[f[x][i]][0])&&(id[f[x][i]][0]<=id[y][1]))
			x=f[x][i];
	return x;
}

bool cmpid(fruit x,fruit y){return x.id<y.id;}
bool cmpx(node x,node y){return (x.x<y.x)||((x.x==y.x)&&(x.ty>y.ty));}

void solve(int al,int ar,int bl,int br,int l,int r)
{
	if (l==r)
		{
			for (int i=al; i<=ar; i++)  a[i].ans=l;
			return;
		}
	if ((al>ar)||(bl>br))  return;
	int amid=al-1,bmid=bl-1,mid=(l+r)>>1,N=0;
	for (int i=bl; i<=br; i++)
		if (b[i].k<=mid)  bmid++,swap(b[i],b[bmid]);
	for (int i=bl; i<=bmid; i++)
		{
			c[++N]=(node){b[i].xl,b[i].yl,b[i].yr,1};
			c[++N]=(node){b[i].xr,b[i].yl,b[i].yr,-1};
		}
	for (int i=al; i<=ar; i++)
		c[++N]=(node){a[i].x,a[i].y,i,0};
	sort(c+1,c+N+1,cmpx);
	for (int i=1,t; i<=N; i++)
		if (c[i].ty!=0)  Bit.add(c[i].y1,c[i].ty),Bit.add(c[i].y2+1,-c[i].ty);
		else  if ((t=Bit.ask(c[i].y1))>=a[c[i].y2].k)  boo[c[i].y2]=1;
		else  boo[c[i].y2]=0,a[c[i].y2].k-=t;
	for (int i=al; i<=ar; i++)
		if (boo[i])  amid++,swap(a[i],a[amid]);
	solve(al,amid,bl,bmid,l,mid);
	solve(amid+1,ar,bmid+1,br,mid+1,r);
}

void work()
{
	scanf("%d %d %d",&n,&p,&q);
	for (int i=1,x,y,tot=0; i<n; i++)
		{
			scanf("%d %d",&x,&y);
			e[++tot]=(edge){x,y,h[x]},h[x]=tot;
			e[++tot]=(edge){y,x,h[y]},h[y]=tot;
		}
	dfs(1,0);
	for (int j=1; j<20; j++)
		for (int i=1; i<=n; i++)
			f[i][j]=f[f[i][j-1]][j-1];
	for (int i=1,x,y,z,k; i<=p; i++)
		{
			scanf("%d %d %d",&x,&y,&k);
			if (id[x][0]>id[y][0])  swap(x,y);
			if (id[y][0]<=id[x][1])
				{
					z=find(y,x);
					if (id[z][0]!=1)  b[++m]=(plate){1,id[z][0]-1,id[y][0],id[y][1],k};
					if (id[z][1]!=n)  b[++m]=(plate){id[y][0],id[y][1],id[z][1]+1,n,k};
				}else
				b[++m]=(plate){id[x][0],id[x][1],id[y][0],id[y][1],k};
		}
	for (int i=1,x,y,k; i<=q; i++)
		{
			scanf("%d %d %d",&x,&y,&k);
			if (id[x][0]>id[y][0])  swap(x,y);
			a[i]=(fruit){id[x][0],id[y][0],k,0,i};
		}
	solve(1,q,1,m,1,1e9);
	sort(a+1,a+q+1,cmpid);
	for (int i=1; i<=q; i++)
		printf("%d\n",a[i].ans);
}

int main()
{
	freopen("4009.in","r",stdin);
	freopen("4009.out","w",stdout);
	work();
	return 0;
}
