#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct node{int f,tag,ch[2];}t[10010];
int n,m;

bool isroot(int x){return (t[x].f==0)||((t[t[x].f].ch[0]!=x)&&(t[t[x].f].ch[1]!=x));}

void push_down(int x)
{
	if (t[x].tag)
		{
			swap(t[x].ch[0],t[x].ch[1]);
			if (t[x].ch[0])  t[t[x].ch[0]].tag^=1;
			if (t[x].ch[1])  t[t[x].ch[1]].tag^=1;
			t[x].tag=0;
		}
}

void up(int x)
{
	if (!isroot(x))  up(t[x].f);
	push_down(x);
}

void rotate(int x)
{
	int f=t[x].f,ff=isroot(f)?0:t[f].f,q=(t[f].ch[1]==x),ch=t[x].ch[q^1];
	if (ff)  t[ff].ch[t[ff].ch[1]==f]=x;  t[x].f=t[f].f;
	t[f].ch[q]=ch,t[ch].f=f;
	t[x].ch[q^1]=f,t[f].f=x;
	t[0].ch[0]=t[0].ch[1]=t[0].f=t[0].tag=0;
}

void splay(int x)
{
	up(x);
	while (!isroot(x))  rotate(x);
}

void access(int x)
{
	for (int y=0; x; y=x,x=t[x].f)  splay(x),t[x].ch[1]=y;
}

void event(int x){access(x),splay(x),t[x].tag^=1;}

int same_tree(int x,int y)
{
	event(x),access(y),splay(y);
	return (x==y)||(t[x].f)||(t[y].f);
}

void link(int x,int y)
{
	if (same_tree(x,y))  return;
	event(x),access(y),splay(y);
	t[x].f=y;
}

void cut(int x,int y)
{
	if (!same_tree(x,y))  return;
	event(x),access(y),splay(y);
	t[x].f=t[y].ch[0]=0;
}

void work()
{
	scanf("%d %d\n",&n,&m);
	for (int i=1,x,y; i<=m; i++)
		{
			char s[10];
			scanf("%s %d %d\n",s,&x,&y);
			if (s[0]=='C')  link(x,y);
			if (s[0]=='D')  cut(x,y);
			if (s[0]=='Q')
				{if (same_tree(x,y))  printf("Yes\n");  else  printf("No\n");}
		}
}

int main()
{
	freopen("2049.in","r",stdin);
	freopen("2049.out","w",stdout);
	work();
	return 0;
}
