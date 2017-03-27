#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int seed=173,mo=int(1e9+7);
int n,p,l[100010],r[100010],lx[100010],rx[100010],hs[11000000],sd[11000000];
char ch[11000000];

int get(int l,int r){return (hs[r]-1LL*hs[l-1]*sd[r-l+1]%mo+mo)%mo;}

bool check(int x,int y)
{
	if (r[x]-l[x]!=r[y]-l[y])  return 1;
	for (int i=0; i<=r[x]-l[x]; i++)
		if (ch[l[x]+i]!=ch[l[y]+i])
			return 1;
	return 0;
}

int find(int x,int r)
{
	while ((ch[x]!='*')&&(x<=r))  x++;
	return x-1;
}

void work()
{
	scanf("%d",&n),p=0;
	for (int i=1; i<=n; i++)
		{
			scanf("%s",ch+r[i-1]+1);
			l[i]=r[i-1]+1,r[i]=r[i-1]+strlen(ch+r[i-1]+1);
			lx[i]=r[i]-l[i]+1,rx[i]=-1;
			for (int j=0; j<=r[i]-l[i]; j++)
				if (ch[l[i]+j]=='*')
					lx[i]=min(lx[i],j),rx[i]=max(rx[i],j);
			if (rx[i]==-1)  {if (!p)  p=i;  else  if (check(p,i))  p=-1;}
			rx[i]=r[i]-l[i]-rx[i];
		}
	if (p==-1)  {printf("N\n");  return;}
	sd[0]=1;
	for (int i=1; i<=r[n]; i++)
		hs[i]=(1LL*hs[i-1]*seed+ch[i])%mo,sd[i]=1LL*sd[i-1]*seed%mo;
	if (p==0)
		{
			p=1;
			for (int i=2; i<=n; i++)
				if (lx[i]>lx[p])  p=i;
			for (int i=1; i<=n; i++)
				if (get(l[i],l[i]+lx[i]-1)!=get(l[p],l[p]+lx[i]-1))
					{printf("N\n");  return;}
			p=1;
			for (int i=2; i<=n; i++)
				if (rx[i]>rx[p])  p=i;
			for (int i=1; i<=n; i++)
				if (get(r[i]-rx[i]+1,r[i])!=get(r[p]-rx[i]+1,r[p]))
					{printf("N\n");  return;}
		}else
		{
			for (int i=1; i<=n; i++)
				{
					int x=l[i],y,j=l[p],T;
					while (x<=r[i])
						{
							y=find(x,r[i]);
							if (x==l[i])  T=1;
							else  if (y==r[i])  T=1,j=r[p]-y+x;
							else  T=1<<30;
							for (; j+y-x<=r[p]&&T; j++,T--)
								if (get(x,y)==get(j,j+y-x))
									break;
							if ((j+y-x>r[p])||(!T))  break;
							j+=y-x+1,x=y+2;
						}
					if (x<=r[i])  {printf("N\n");  return;}
				}
		}
	printf("Y\n");
}

int main()
{
	freopen("3574.in","r",stdin);
	freopen("3574.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
