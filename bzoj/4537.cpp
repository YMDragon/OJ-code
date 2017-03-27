#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;

const int siz=500;
struct edge{int u,v,a,b,ans,id;}a[100010],b[100010],p[50010],e[10000];
int n,m,q,tim,h[50010],ufs[50010],maxa[50010],maxb[50010],vis[50010],A,B,ans;

int gi()
{
	int w=0,q=1;  char ch=getchar();
	while (((ch<'0')||('9'<ch))&&(ch!='-'))  ch=getchar();
	if (ch=='-')  q=0,ch=getchar();
	while (('0'<=ch)&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return q?w:-w;
}

void pi(int x)
{
	if (x<0)  putchar('-'),x=-x;
	if (x>9)  pi(x/10);
	putchar(x%10+'0');
}

bool cmpa(edge x,edge y){return (x.a<y.a)||((x.a==y.a)&&(x.b<y.b));}
bool cmpb(edge x,edge y){return (x.b<y.b)||((x.b==y.b)&&(x.a<y.a));}
bool cmp(edge x,edge y){return (x.b<=y.b)&&(x.a<=y.a);}
bool cmpid(edge x,edge y){return x.id<y.id;}
int find(int x){return ufs[x]==x?x:ufs[x]=find(ufs[x]);}

void link(int i)
{
	int u,v;
	if ((u=find(a[i].u))!=(v=find(a[i].v)))
		{
			ufs[v]=u;
			maxa[u]=max(maxa[u],maxa[v]);
			maxb[u]=max(maxb[u],maxb[v]);
		}
	maxa[u]=max(maxa[u],a[i].a),maxb[u]=max(maxb[u],a[i].b);
}

bool dfs(int x,int T)
{
	int res=(x==T);
	vis[x]=tim;
	if (maxa[x]>A)  A=maxa[x];
	if (maxb[x]>B)  B=maxb[x];
	for (int i=h[x],y; y=e[i].v,i; i=e[i].id)
		{
			if (e[i].a>A)  A=e[i].a;
			if (e[i].b>B)  B=e[i].b;
			if (vis[y]!=tim)  res|=dfs(y,T);
		}
	return res;
}

void work()
{
	n=gi(),m=gi();
	for (int i=1; i<=m; i++)
		a[i].u=gi(),a[i].v=gi(),a[i].a=gi(),a[i].b=gi();
	q=gi();
	for (int i=1; i<=q; i++)
		p[i].u=gi(),p[i].v=gi(),p[i].a=gi(),p[i].b=gi(),p[i].id=i;
	sort(a+1,a+m+1,cmpa),sort(p+1,p+q+1,cmpa);
	for (int i=1; i<=m; i++)  a[i].id=i;
	memcpy(b,a,sizeof(b)),sort(b+1,b+m+1,cmpb);
	for (int i=1,al,ar,pl,pr=0; i<=(m+siz-1)/siz; i++)
		{
			al=(i-1)*siz+1,ar=min(i*siz,m);
			pl=pr+1;
			while ((pr<q)&&(cmpa(p[pr+1],a[ar])))  pr++;
			if (ar==m)  pr=q;
			if (pl>pr)  continue;
			sort(p+pl,p+pr+1,cmpb);
			for (int j=1; j<=n; j++)  ufs[j]=j,maxa[j]=maxb[j]=-1;
			for (int j=pl,J=1; j<=pr; j++)
				{
					do{
						while ((J<=m)&&(b[J].id>=al))  J++;
						if ((J<=m)&&(cmp(b[J],p[j])))  link(b[J].id),J++;  else  break;
					}while (J<=m);
					for (int k=al,tot=0; k<=ar; k++)
						if (cmp(a[k],p[j]))
							{
								int u=find(a[k].u),v=find(a[k].v);
								e[++tot]=(edge){u,v,a[k].a,a[k].b,0,h[u]},h[u]=tot;
								e[++tot]=(edge){v,u,a[k].a,a[k].b,0,h[v]},h[v]=tot;
							}
					A=B=-1,tim++;
					if ((dfs(find(p[j].u),find(p[j].v)))&&(A==p[j].a)&&(B==p[j].b))
						p[j].ans=1;  else  p[j].ans=0;
					for (int k=al; k<=ar; k++)
						if (cmp(a[k],p[j]))
							h[find(a[k].u)]=h[find(a[k].v)]=0;
				}
		}
	sort(p+1,p+q+1,cmpid);
	for (int i=1; i<=q; i++)  puts(p[i].ans?"Yes":"No");
}

int main()
{
	freopen("4537.in","r",stdin);
	freopen("4537.out","w",stdout);
	work();
	return 0;
}
