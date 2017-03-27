#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int oo=int(1e9);
struct node{int s,ls,rs;}t[8000010];
int n,m,a[10010],root[10010],tot,aa[20],bb[20],la,lb;

void add(int &la,int l,int r,int v)
{
	int n=++tot,mid=(l+r)>>1;
	t[n]=t[la],t[n].s++;
	if (l!=r){if (v<=mid)  add(t[n].ls,l,mid,v);  else  add(t[n].rs,mid+1,r,v);}
	la=n;
}

void del(int n,int l,int r,int v)
{
	int mid=(l+r)>>1;
	t[n].s--;
	if (l==r)  return;
	if (v<=mid)  del(t[n].ls,l,mid,v);  else  del(t[n].rs,mid+1,r,v);
}

int ask(int l,int r,int k)
{
	int ss=0,mid=(l+r)>>1;
	for (int i=1; i<=la; i++)  ss-=t[t[aa[i]].ls].s;
	for (int i=1; i<=lb; i++)  ss+=t[t[bb[i]].ls].s;
	if (l==r)  return l;
	else
		if (k<=ss)
			{
				for (int i=1; i<=la; i++)  aa[i]=t[aa[i]].ls;
				for (int i=1; i<=lb; i++)  bb[i]=t[bb[i]].ls;
				return ask(l,mid,k);
			}else
			{
				for (int i=1; i<=la; i++)  aa[i]=t[aa[i]].rs;
				for (int i=1; i<=lb; i++)  bb[i]=t[bb[i]].rs;
				return ask(mid+1,r,k-ss);
			}
}

void BIT_add(int x,int v){for (; x<=n; x+=x&-x)  add(root[x],0,oo,v);}
void BIT_del(int x,int v){for (; x<=n; x+=x&-x)  del(root[x],0,oo,v);}
int BIT_ask(int x,int y,int k)
{
	for (la=0; x; x-=x&-x)  aa[++la]=root[x];
	for (lb=0; y; y-=y&-y)  bb[++lb]=root[y];
	return ask(0,oo,k);
}

void work()
{
	int x,y,k;
	char ch;
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]),BIT_add(i,a[i]);
	for (int i=1; i<=m; i++)
		{
			scanf("\n%c",&ch);
			if (ch=='Q')  scanf("%d%d%d",&x,&y,&k),printf("%d\n",BIT_ask(x-1,y,k));
			else  scanf("%d %d",&x,&k),BIT_del(x,a[x]),BIT_add(x,k),a[x]=k;
		}
}

int main()
{
	freopen("1901.in","r",stdin);
	freopen("1901.out","w",stdout);
	work();
	return 0;
}
