#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
struct node{int x,f,ch[2],s,max;}t[1010];
int n,a[2010],rt;
LL ans,Ans;

void update(int x)
{
	t[x].s=1+t[t[x].ch[0]].s+t[t[x].ch[1]].s;
	t[x].max=max(t[x].x,max(t[t[x].ch[0]].max,t[t[x].ch[1]].max));
}

void rotate(int x)
{
	int f=t[x].f,ff=t[f].f,q=t[f].ch[1]==x,ch=t[x].ch[q^1];
	if (ff)  t[ff].ch[t[ff].ch[1]==f]=x;  else  rt=x;  t[x].f=ff;
	t[f].ch[q]=ch;  if (ch)  t[ch].f=f;
	t[x].ch[q^1]=f,t[f].f=x;
	update(f),update(x);
}

void splay(int x)
{
	while (t[x].f)
		if (!t[t[x].f].f)  rotate(x);
		else  if ((t[t[x].f].ch[1]==x)==(t[t[t[x].f].f].ch[1]==t[x].f))
			rotate(t[x].f),rotate(x);
		else  rotate(x),rotate(x);
}

int find(int k)
{
	int x=rt;
	while (x)
		{
			if (k==t[t[x].ch[0]].s+1)  return x;
			if (k<=t[t[x].ch[0]].s)  x=t[x].ch[0];
			else  k-=t[t[x].ch[0]].s+1,x=t[x].ch[1];
		}
	return x;
}

void del(int x)
{
	while (t[x].s!=1)
		if (t[t[x].ch[0]].s>t[t[x].ch[1]].s)  rotate(t[x].ch[0]);
		else  rotate(t[x].ch[1]);
	t[t[x].f].ch[t[t[x].f].ch[1]==x]=0,splay(t[x].f),t[x].f=0;
}

void chk(int x);

void push(int x,int z)
{
	if (!t[x].ch[0])  return;
	int y=t[x].ch[0];
	while (1)
		if (t[t[y].ch[1]].max>t[x].x)  y=t[y].ch[1];
		else  if (t[y].x>t[x].x)  break;
		else  if (t[y].ch[0])  y=t[y].ch[0];
		else  break;
	if (t[y].max>t[x].x)
		if (t[y].ch[1])
			{
				y=t[y].ch[1];
				while (t[y].ch[0])  y=t[y].ch[0];
				t[y].ch[0]=z;
			}else  t[y].ch[1]=z;
	else  t[y].ch[0]=z;
	t[z].f=y,del(x),splay(z),chk(z);
}

void merge(int k)
{
	int x=find(k),y;
	splay(x),y=t[x].ch[1];
	while (t[y].ch[0])  y=t[y].ch[0];
	del(y),t[x].x+=t[y].x,ans+=t[x].x,update(x),t[y].x=t[x].x;
	push(x,y);
}

void chk(int x)
{
	while ((t[rt].s>2)&&(splay(x),t[find(t[t[x].ch[0]].s-1)].x<=t[x].x))
		merge(t[t[x].ch[0]].s-1);
}

void work()
{
	scanf("%d",&n),Ans=1LL<<60;
	for (int i=1; i<=n; i++)  scanf("%d",&a[i]),a[n+i]=a[i];
	for (int s=0; s<n; s++)
		{
			ans=0,memset(t,0,sizeof(t)),rt=0,t[0].x=1<<30;
			for (int i=1; i<=n; i++)
				t[i].x=a[s+i],t[i].ch[0]=rt,t[rt].f=i,rt=i,update(i),chk(i);
			while (t[rt].s>1)  merge(t[rt].s-1);
			Ans=min(Ans,ans);
		}
	printf("%lld",Ans);
}

int main()
{
	freopen("1022.in","r",stdin);
	freopen("1022.out","w",stdout);
	work();
	return 0;
}
