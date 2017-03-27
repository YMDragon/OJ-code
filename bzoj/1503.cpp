#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct node{int k,s,ch[2],f;}t[200010];
int n,tot,root;

void updata(int x)
{
	t[x].s=t[t[x].ch[0]].s+t[t[x].ch[1]].s+1;
}

void rotate(int x)
{
	int f=t[x].f,ff=t[f].f,q=(x==t[f].ch[1]);
	if (ff)  t[x].f=t[f].f,t[ff].ch[f==t[ff].ch[1]]=x;
	else  t[x].f=0,root=x;
	t[f].ch[q]=t[x].ch[q^1],t[t[x].ch[q^1]].f=f;
	t[x].ch[q^1]=f,t[f].f=x;
	t[x].s=t[f].s,updata(f);
}

void splay(int x)
{
	while (t[x].f)  rotate(x);  root=x;
}

void insert(int n,int v)
{
	if (n)  t[n].s++;
	int q=(v>t[n].k);
	if (t[n].ch[q]==0)  t[n].ch[q]=++tot,t[tot]=(node){v,1,{0,0},n},splay(tot);
	else  insert(t[n].ch[q],v);
}

int select(int n,int k)
{
	if (k<=t[t[n].ch[0]].s)  return select(t[n].ch[0],k);
	else  if (k==t[t[n].ch[0]].s+1)  return n;
	else  return select(t[n].ch[1],k-t[t[n].ch[0]].s-1);
}

void work()
{
	int min,x,k=0,ans=0;
	scanf("%d %d\n",&n,&min);
	char ch;
	for (int i=1; i<=n; i++)
		{
			scanf("%c %d\n",&ch,&x);
			if (ch=='I')  if (x>=min)  insert(root,x-k);
			if (ch=='A')  k+=x;
			if (ch=='S')
				{
					k-=x;
					insert(root,min-k);
					ans+=t[t[root].ch[0]].s;
					root=t[root].ch[1];
					t[root].f=0;
					updata(root);
				}
			if (ch=='F')
				{
					if (t[root].s>=x)  printf("%d\n",t[select(root,t[root].s-x+1)].k+k);
					else  printf("-1\n");
				}
			t[0]=(node){0,0,{0,0},0};
		}
	printf("%d",ans);
}

int main()
{
	freopen("1503.in","r",stdin);
	freopen("1503.out","w",stdout);
	work();
	return 0;
}
