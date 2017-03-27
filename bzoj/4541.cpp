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
 
const int mo=int(1e7+7);
const double Pi=acos(-1),eps=1e-10;
struct point{int x,y;}a[200010];
struct edge{int s,t,vis,a;double r;};
struct Edge{int s,t,n,tr;}e[1200010];
struct node{int s,t,a,n;}hs[1200010];
int n,m,k,cnt,root,hstot,dfntot,h[400010],dfn[400010],hsh[mo];
LL S[400010],S2[400010];
vector <edge> V[200010];
vector <int> b[400010],c;
 
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
 
bool cmp(edge x,edge y){return x.r<y.r;}
edge rotate(edge x){return (edge){0,0,0,0,((x.r>0)?x.r-Pi:x.r+Pi)-eps};}
point operator - (point x,point y){return (point){x.x-y.x,x.y-y.y};}
LL cross(point x,point y){return 1LL*x.x*y.y-1LL*x.y*y.x;}
LL gcd(LL x,LL y){return y?gcd(y,x%y):x;}
 
int find(int np,int p,int q)
{
	return lower_bound(V[np].begin(),V[np].end(),rotate(V[p][q]),cmp)-V[np].begin();
}
 
void push(int x,int y,int a)
{
	int t=(1LL*x*(n+173)+y)%mo;
	hs[++hstot]=(node){x,y,a,hsh[t]},hsh[t]=hstot;
}
 
int find(int x,int y)
{
	int t=(1LL*x*(n+173)+y)%mo;
	for (int i=hsh[t]; i; i=hs[i].n)
		if ((hs[i].s==x)&&(hs[i].t==y))
			return hs[i].a;
	return 0;
}
 
void dfs(int x)
{
	S2[x]=S[x]*S[x],dfn[x]=++dfntot;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (!dfn[y])
			e[i].tr=e[i^1].tr=1,dfs(y),S[x]+=S[y],S2[x]+=S2[y];
}
 
void work()
{
	n=gi(),m=gi(),k=gi();
	for (int i=1; i<=n; i++)
		a[i].x=gi(),a[i].y=gi();
	for (int i=1,x,y; i<=m; i++)
		{
			x=gi(),y=gi();
			V[x].push_back((edge){x,y,0,0,atan2(a[y].y-a[x].y,a[y].x-a[x].x)});
			V[y].push_back((edge){y,x,0,0,atan2(a[x].y-a[y].y,a[x].x-a[y].x)});
		}
	for (int i=1; i<=n; i++)  sort(V[i].begin(),V[i].end(),cmp);
	for (int i=1; i<=n; i++)
		for (int j=0; j<V[i].size(); j++)
			if (!V[i][j].vis)
				{
					int p=i,q=j,np,nq;
					cnt++;
					do{
						V[p][q].vis=cnt,b[cnt].push_back(p);
						np=V[p][q].t,nq=find(np,p,q);
						if (nq==0)  nq=V[np].size()-1;  else  nq--;
						p=np,q=nq;
					}while ((p!=i)||(q!=j));
				}
	for (int i=1,tot=1; i<=n; i++)
		for (int j=0; j<V[i].size(); j++)
			{
				int p=i,q=j,np,nq,x,y;
				np=V[p][q].t,nq=find(np,p,q);
				if (p>np)  continue;
				x=V[p][q].vis,y=V[np][nq].vis;
				e[++tot]=(Edge){x,y,h[x],0},h[x]=tot,V[p][q].a=tot;
				e[++tot]=(Edge){y,x,h[y],0},h[y]=tot,V[np][nq].a=tot;
				push(V[i][j].s,V[i][j].t,V[i][j].a);
				push(V[i][j].t,V[i][j].s,V[np][nq].a);
			}
	for (int i=1; i<=cnt; i++)
		{
			for (int j=2; j<b[i].size(); j++)
				S[i]+=cross(a[b[i][j-1]]-a[b[i][0]],a[b[i][j]]-a[b[i][0]]);
			if (S[i]<0)  root=i;
		}
	dfs(root);
	LL lp,p=0,q,g;
	for (int i=1,d,s,x,y,t; i<=k; i++)
		{
			lp=p,d=(gi()+lp)%n+1,p=0,q=0,s=x=(gi()+lp)%n+1;
			for (int j=1; j<=d; j++)
				{
					y=(j==d)?s:(gi()+lp)%n+1;
					t=find(x,y);
					if (e[t].tr)
						{
							if (dfn[e[t].s]<dfn[e[t].t])
								p-=S2[e[t].t],q-=S[e[t].t];
							else  p+=S2[e[t].s],q+=S[e[t].s];
						}
					x=y;
				}
			q*=2,g=gcd(p,q),p/=g,q/=g;
			pi(p),putchar(' '),pi(q),putchar('\n');
		}
}
 
int main()
{
	freopen("4541.in","r",stdin);
	freopen("4541.out","w",stdout);
	work();
	return 0;
}
