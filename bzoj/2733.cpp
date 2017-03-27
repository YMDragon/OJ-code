#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
 
struct node{int k,s,ch[2],f;}t[100010];
 
void updata(int x){t[x].s=t[t[x].ch[0]].s+t[t[x].ch[1]].s+1;}
int fr(int x){while (t[x].f)  x=t[x].f;  return x;}
 
void rotate(int x)
{
	int f=t[x].f,ff=t[f].f,q=x==t[f].ch[1],ch=t[x].ch[q^1];
	if (ff)  t[x].f=ff,t[ff].ch[f==t[ff].ch[1]]=x;  else  t[x].f=0;
	t[f].ch[q]=ch,t[ch].f=f;
	t[x].ch[q^1]=f,t[f].f=x;
	t[x].s=t[f].s,updata(f);
}
 
void splay(int x){while (t[x].f)  rotate(x);}
 
void modify(int x,int y)
{
	int i=fr(x),q=t[y].k>=t[i].k;
	while (t[i].ch[q])  t[i].s++,i=t[i].ch[q],q=(t[y].k>=t[i].k);;
	t[i].s++,t[i].ch[q]=y,t[y].f=i,t[y].s=1,splay(y);
}
 
int select(int x,int k)
{
	int i=fr(x);
	if (k>t[i].s)  return -1;
	while (k!=t[t[i].ch[0]].s+1)
		{
			if (k<=t[t[i].ch[0]].s)  i=t[i].ch[0];
			else  k=k-t[t[i].ch[0]].s-1,i=t[i].ch[1];
		}
	return i;
}
 
void merge(int x,int y)
{
	int q;
	x=fr(x),y=fr(y);
	if (x==y)  return;
	if (t[x].s<t[y].s)  swap(x,y);
	queue <int> Q;  Q.push(y);
	while (!Q.empty())
		{
			q=Q.front(),Q.pop();
			if (t[q].ch[0])  Q.push(t[q].ch[0]);
			if (t[q].ch[1])  Q.push(t[q].ch[1]);
			modify(x,q);
		}
}

void work()
{
	int n,m,q,x,y;
	char ch;
	scanf("%d %d",&n,&m);
	for (int i=1; i<=n; i++)  scanf("%d",&t[i].k),t[i].s=1;
	for (int i=1; i<=m; i++)  scanf("%d %d",&x,&y),merge(x,y);
	scanf("%d\n",&q);
	for (int i=1; i<=q; i++)
		{
			scanf("%c %d %d\n",&ch,&x,&y);
			if ((x==0)||(y==0))  continue;
			if (ch=='B')  merge(x,y);
			if (ch=='Q')  printf("%d\n",select(x,y));
		}
}

int main()
{
	freopen("2733.in","r",stdin);
	freopen("2733.out","w",stdout);
	work();
	return 0;
}
