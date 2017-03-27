#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxnum=524287;
struct node{int x,ch[2];}t[10000000];
int n,m,tot,rt[500010];

void insert(int &n,int l,int r,int x)
{
	t[++tot]=t[n],n=tot;
	t[n].x++;
	if (l!=r)
		{
			int mid=(l+r)>>1;
			if (x<=mid)  insert(t[n].ch[0],l,mid,x);
			else  insert(t[n].ch[1],mid+1,r,x);
		}
}

int query1(int n1,int n2,int l,int r,int x)
{
	if (l==r)  return l;
	else
		{
			int mid=(l+r)>>1,p=(x&(mid-l+1))>0;
			if (t[t[n1].ch[p^1]].x-t[t[n2].ch[p^1]].x)
				return query1(t[n1].ch[p^1],t[n2].ch[p^1],p?l:(mid+1),p?mid:r,x);
			else  return query1(t[n1].ch[p],t[n2].ch[p],p?(mid+1):l,p?r:mid,x);
		}
}

int query2(int n1,int n2,int l,int r,int x)
{
	if (r<=x)  return t[n1].x-t[n2].x;
	else
		{
			int mid=(l+r)>>1,res=0;
			res+=query2(t[n1].ch[0],t[n2].ch[0],l,mid,x);
			if (mid<x)  res+=query2(t[n1].ch[1],t[n2].ch[1],mid+1,r,x);
			return res;
		}
}

int query3(int n1,int n2,int l,int r,int k)
{
	if (l==r)  return l;
	else
		{
			int mid=(l+r)>>1;
			if (t[t[n1].ch[0]].x-t[t[n2].ch[0]].x>=k)  return query3(t[n1].ch[0],t[n2].ch[0],l,mid,k);
			else  return query3(t[n1].ch[1],t[n2].ch[1],mid+1,r,k-(t[t[n1].ch[0]].x-t[t[n2].ch[0]].x));
		}
}

void work()
{
	scanf("%d",&m);
	for (int i=1,ty,l,r,x; i<=m; i++)
		{
			scanf("%d",&ty);
			if (ty==0)  scanf("%d",&x),n++,rt[n]=rt[n-1],insert(rt[n],0,maxnum,x);
			if (ty==1)  scanf("%d %d %d",&l,&r,&x),printf("%d\n",query1(rt[r],rt[l-1],0,maxnum,x));
			if (ty==2)  scanf("%d",&x),n-=x;
			if (ty==3)  scanf("%d %d %d",&l,&r,&x),printf("%d\n",query2(rt[r],rt[l-1],0,maxnum,x));
			if (ty==4)  scanf("%d %d %d",&l,&r,&x),printf("%d\n",query3(rt[r],rt[l-1],0,maxnum,x));
		}
}

int main()
{
	freopen("XRQRS.in","r",stdin);
	freopen("XRQRS.out","w",stdout);
	work();
	return 0;
}
