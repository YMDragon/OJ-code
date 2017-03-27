#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct node{int x,f,ch[2],tag,l,min,sum;}t[400010];
int n,m,tot,Map[300010];
char ch,ch2;

bool isroot(int x){return (t[t[x].f].ch[0]!=x)&&(t[t[x].f].ch[1]!=x);}

void pushdown(int x)
{
	if (t[x].tag)
		{
			swap(t[x].ch[0],t[x].ch[1]),t[x].tag=0;
			t[t[x].ch[0]].tag^=1,t[t[x].ch[1]].tag^=1;
		}
}

void update(int x)
{
	t[x].min=min(t[x].x,min(t[t[x].ch[0]].min,t[t[x].ch[1]].min));
	t[x].sum=t[x].l+t[t[x].ch[0]].sum+t[t[x].ch[1]].sum;
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
	for (int y=0; x; splay(x),t[x].ch[1]=y,update(x),y=x,x=t[x].f);
}

void event(int x)
{
	access(x),splay(x),t[x].tag^=1;
}

void link(int x,int y,int z)
{
	event(z),t[y].f=x,t[z].f=y;
}

void cut(int x)
{
	splay(x);
	t[t[x].ch[0]].f=t[t[x].ch[1]].f=0;
}

int getmin(int x,int y)
{
	event(y),access(x),splay(x);
	while (x)
		{
			if (t[x].x==t[x].min)  return x;
			if (t[t[x].ch[0]].min==t[x].min)  x=t[x].ch[0];
			else  x=t[x].ch[1];
		}
	return 0;
}

int dis(int x,int y)
{
	event(y),access(x),splay(x);
	return t[x].sum;
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
	scanf("%d %d",&n,&m),tot=n,t[0].min=1<<30;
	for (int i=1; i<=n; i++)  t[i].x=t[i].min=1<<30;
	for (int i=1,id,u,v,_; i<=m; i++)
		{
			do  ch=getchar();  while ((ch!='f')&&(ch!='m')&&(ch!='c'));
			do  ch2=getchar();  while (ch2!=' ');
			if (ch=='f')
				{
					scanf("%d %d %d",&id,&u,&v),id++,u++,v++;
					Map[id]=++tot;
					scanf("%d %d",&t[tot].x,&t[tot].l);
					t[tot].min=t[tot].x,t[tot].sum=t[tot].l;
					if (sametree(u,v))
						{
							if (t[_=getmin(u,v)].x<t[tot].x)
								cut(_),link(u,tot,v);
						}else  link(u,tot,v);
				}
			if (ch=='m')
				{
					scanf("%d %d",&u,&v),u++,v++;
					printf("%d\n",sametree(u,v)?dis(u,v):-1);
				}
			if (ch=='c')
				{
					scanf("%d %d",&id,&u),id=Map[id+1];
					splay(id),t[id].l=u,update(id);
				}
		}
}

int main()
{
	freopen("274.in","r",stdin);
	freopen("274.out","w",stdout);
	work();
	return 0;
}
