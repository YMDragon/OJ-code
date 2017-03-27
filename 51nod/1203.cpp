#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const int N=100010,Size=300,mo=int(1e9+7);
struct query{int l,r,id;}q[N];
int n,m,a[N],b[N][16],c[N][16],tot[N],cnt[N],p[N],isp[N],inv[N],ptot;
LL ans[N],res;

bool cmp(query x,query y)
{
	if (x.l/Size!=y.l/Size)  return x.l<y.l;
	else  if (x.r!=y.r)  return x.r<y.r;
	else  return x.l<y.l;
}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]);
	for (int i=1; i<=m; i++)  scanf("%d %d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+m+1,cmp);
	isp[1]=-1,inv[1]=1;
	for (int i=2; i<N; i++)  inv[i]=mo-1LL*(mo/i)*inv[mo%i]%mo;
	for (int i=2; i<N; i++)
		{
			if (!isp[i])  p[isp[i]=++ptot]=i;
			for (int j=1; j<=ptot&&i*p[j]<N; j++)
				{
					isp[i*p[j]]=-1;
					if (i%p[j]==0)  break;
				}
		}
	for (int i=1; i<=n; i++)
		{
			for (int j=1; p[j]*p[j]<=a[i]; j++)
				if (a[i]%p[j]==0)
					{
						b[i][++tot[i]]=p[j],c[i][tot[i]]=p[j],a[i]/=p[j];
						while (a[i]%p[j]==0)
							a[i]/=p[j],b[i][tot[i]+1]=b[i][tot[i]]*p[j],c[i][++tot[i]]=p[j];
					}
			if (a[i]!=1)  b[i][++tot[i]]=a[i],c[i][tot[i]]=a[i];
		}
	for (int id=1; id<=m; id++)
		{
			if ((id==1)||(q[id].l/Size!=q[id-1].l/Size))
				{
					memset(cnt,0,sizeof(cnt)),res=1;
					for (int i=q[id].l; i<=q[id].r; i++)
						for (int j=1; j<=tot[i]; j++)
							{
								if (!cnt[b[i][j]])  res=1LL*res*c[i][j]%mo;
								cnt[b[i][j]]++;
							}
				}else
				{
					for (int i=q[id-1].l; i<q[id].l; i++)
						for (int j=1; j<=tot[i]; j++)
							{
								cnt[b[i][j]]--;
								if (!cnt[b[i][j]])  res=1LL*res*inv[c[i][j]]%mo;
							}
					for (int i=q[id].l; i<q[id-1].l; i++)
						for (int j=1; j<=tot[i]; j++)
							{
								if (!cnt[b[i][j]])  res=1LL*res*c[i][j]%mo;
								cnt[b[i][j]]++;
							}
					for (int i=q[id-1].r+1; i<=q[id].r; i++)
						for (int j=1; j<=tot[i]; j++)
							{
								if (!cnt[b[i][j]])  res=1LL*res*c[i][j]%mo;
								cnt[b[i][j]]++;
							}
				}
			ans[q[id].id]=res;
		}
	for (int i=1; i<=m; i++)  printf("%lld\n",ans[i]);
}

int main()
{
	freopen("1203.in","r",stdin);
	freopen("1203.out","w",stdout);
	work();
	return 0;
}
