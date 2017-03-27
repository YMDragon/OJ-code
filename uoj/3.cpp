#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct edge{int x,y,a,b;}e[100010];
struct node{int x,f,ch[2],max,tag;}t[150010];
int n,m,N,ans;

bool cmp(edge x,edge y){return (x.a<y.a);}

bool isroot(int x)
{
	return (t[t[x].f].ch[0]!=x)&&(t[t[x].f].ch[1]!=x);
}

void pushdown(int x)
{
	if (t[x].tag)
		{
			swap(t[x].ch[0],t[x].ch[1]);
			if (t[x].ch[0])  t[t[x].ch[0]].tag^=1;
			if (t[x].ch[1])  t[t[x].ch[1]].tag^=1;
			t[x].tag=0;
		}
}

void update(int x)
{
	t[x].max=max(t[x].x,max(t[t[x].ch[0]].max,t[t[x].ch[1]].max));
}

void go_up(int x)
{
	if (!isroot(x))  go_up(t[x].f);
	pushdown(x);
}

void rotate(int x)
{
	int f=t[x].f,ff=t[f].f,q=(t[f].ch[1]==x),ch=t[x].ch[q^1];
	if (!isroot(f))  t[ff].ch[t[ff].ch[1]==f]=x;  t[x].f=ff;
	t[f].ch[q]=ch;  if (ch)  t[ch].f=f;
	t[x].ch[q^1]=f,t[f].f=x;
	update(f),update(x);
}

void splay(int x)
{
	go_up(x);
	while (!isroot(x))
		if (isroot(t[x].f))  rotate(x);
		else  if ((t[t[x].f].ch[1]==x)==(t[t[t[x].f].f].ch[1]==t[x].f))
			rotate(t[x].f),rotate(x);
		else  rotate(x),rotate(x);
}

void access(int x)
{
	for (int y=0; x; )
		splay(x),t[x].ch[1]=y,update(x),y=x,x=t[x].f;
}

void event(int x)
{
	access(x),splay(x),t[x].tag^=1;
}

void link(int x,int y,int w)
{
	event(y);
	t[++n].x=w,t[n].max=w,t[n].f=x,t[y].f=n;
}

void cut(int x)
{
	splay(x);
	t[t[x].ch[0]].f=t[t[x].ch[1]].f=0;
}

int getmax(int x,int y)
{
	event(y),access(x),splay(x);
	while (x)
		{
			if (t[x].x==t[x].max)  return x;
			if (t[t[x].ch[0]].max==t[x].max)  x=t[x].ch[0];
			else  x=t[x].ch[1];
		}
	return 0;
}

bool sametree(int x,int y)
{
	event(y),access(x),splay(x);
	while (x)
		{
			if (x==y)  return 1;
			pushdown(x),x=t[x].ch[0];
		}
	return 0;
}

void work()
{
	scanf("%d %d",&n,&m),N=n,ans=1<<30;
	for (int i=1; i<=m; i++)
		scanf("%d %d %d %d",&e[i].x,&e[i].y,&e[i].a,&e[i].b);
	sort(e+1,e+m+1,cmp);
	for (int i=1,tmp; i<=m; i++)
		if (e[i].x!=e[i].y)
			{
				if (sametree(e[i].x,e[i].y))
					{
						if (t[tmp=getmax(e[i].x,e[i].y)].x>e[i].b)
							cut(tmp),link(e[i].x,e[i].y,e[i].b);
					}else  link(e[i].x,e[i].y,e[i].b);
				if (sametree(1,N))
					ans=min(ans,e[i].a+t[getmax(1,N)].x);
			}
	printf("%d",(ans==(1<<30))?-1:ans);
}

int main()
{
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	work();
	return 0;
}
