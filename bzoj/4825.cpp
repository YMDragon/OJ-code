#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

typedef long long  LL;
typedef pair <int,int>  PII;
struct node{int x,f,ch[2],s,tf,tch[2];}t[100010];
int tot;
set <PII> S;
set <PII> ::iterator It,It2;

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

bool isroot(int x)
{
	return (t[t[x].f].ch[0]!=x)&&(t[t[x].f].ch[1]!=x);
}

void update(int x)
{
	t[x].s=1+t[t[x].ch[0]].s+t[t[x].ch[1]].s;
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

int dep(int x)
{
	if (!x)  return 0;
	access(x),splay(x);
	return t[x].s;
}

int xmin(int x)
{
	splay(x);
	while (t[x].ch[0])  x=t[x].ch[0];
	return x;
}

int insert(int c)
{
	int fa=0;
	tot++,It=(S.insert(make_pair(c,tot))).first;
	if (It!=S.begin())  It2=It,It2--,fa=(*It2).second;
	It2=It,It2++;
	if ((It2!=S.end())&&(dep(fa)<dep((*It2).second)))  fa=(*It2).second;
	t[tot]=(node){c,fa,{0,0},1,fa,{0,0}};
	if (fa)  t[fa].tch[c>t[fa].x]=tot;
	return dep(tot);
}

int lspaly(int ty)
{
	int x=(*S.begin()).second,res=dep(x),y;
	if (!t[x].tf)
		{
			if ((!ty)&&(t[x].tch[1]))
				access(x),splay(t[x].tch[1]),t[t[x].tch[1]].f=t[t[x].tch[1]].tf=0;
			return res;
		}
	access(t[x].tf);
	if (t[x].tch[1])
		{
			t[t[x].tf].tch[0]=t[x].tch[1],splay(t[x].tch[1]);
			t[t[x].tch[1]].f=t[t[x].tch[1]].tf=t[x].tf;
		}else  t[t[x].tf].tch[0]=0;
	t[x].f=0;
	if (ty)
		{
			y=xmin(t[x].tf),splay(y);
			t[x].tf=0,t[x].tch[1]=y,t[y].f=t[y].tf=x;
		}
	return res;
}

int rspaly(int ty)
{
	int x=(*S.rbegin()).second,res=dep(x),y;
	if (!t[x].tf)
		{
			if ((!ty)&&(t[x].tch[0]))
				access(x),splay(t[x].tch[0]),t[t[x].tch[0]].f=t[t[x].tch[0]].tf=0;
			return res;
		}
	access(t[x].tf);
	if (t[x].tch[0])
		{
			t[t[x].tf].tch[1]=t[x].tch[0],splay(t[x].tch[0]);
			t[t[x].tch[0]].f=t[t[x].tch[0]].tf=t[x].tf;
		}else  t[t[x].tf].tch[1]=0;
	t[x].f=0;
	if (ty)
		{
			y=xmin(t[x].tf),splay(y);
			t[x].tf=0,t[x].tch[0]=y,t[y].f=t[y].tf=x;
		}
	return res;
}

void work()
{
	for (int i=gi(),ty; i; i--)
		{
			ty=gi();
			if (ty==1)  pi(insert(gi()));
			if (ty==2)  pi(lspaly(1));
			if (ty==3)  pi(rspaly(1));
			if (ty==4)  pi(lspaly(0)),S.erase(*S.begin());
			if (ty==5)  pi(rspaly(0)),S.erase(*S.rbegin());
			puts("");
		}
}

int main()
{
	freopen("4825.in","r",stdin);
	freopen("4825.out","w",stdout);
	work();
	return 0;
}
