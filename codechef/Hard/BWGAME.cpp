#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

struct node{int x,k,s,ch[2];}t[200010];
int n,rt[100010],a[100010],b[100010],tot,ans;

int merge(int x,int y)
{
	if ((!x)||(!y))  return x?x:y;
	if (t[x].x>t[y].x)  swap(x,y);
	int q=t[t[x].ch[1]].s<t[t[x].ch[0]].s;
	t[x].ch[q]=merge(t[x].ch[q],y),t[x].s+=t[y].s;
	return x;
}

void work()
{
	scanf("%d",&n),memset(t,0,sizeof(t)),memset(rt,0,sizeof(rt)),ans=1,tot=0,t[0].x=1<<30;
	for (int i=1,l,r; i<=n; i++)
		scanf("%d %d",&l,&r),t[++tot]=(node){r,i,1,{0,0}},rt[l]=merge(rt[l],tot),a[i]=b[i]=i;
	for (int i=1,x,r; i<=n; i++)
		{
			if (rt[i]==0)  {ans=0;  break;}
			x=t[rt[i]].k,r=t[rt[i]].x;
			if (x!=a[i])
				{
					ans*=-1;
					swap(a[i],a[b[x]]),swap(b[a[b[x]]],b[x]);
				}
			while (t[rt[i]].x==r)  rt[i]=merge(t[rt[i]].ch[0],t[rt[i]].ch[1]);
			rt[r+1]=merge(rt[r+1],rt[i]);
		}
	puts(ans?(ans>0?"Alex":"Fedor"):"Draw");
}

int main()
{
	freopen("BWGAME.in","r",stdin);
	freopen("BWGAME.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)  work();
	return 0;
}
