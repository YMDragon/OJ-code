#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int oo=1<<30;
struct node{int k,s,ch[2],f;}t[100010];

int root,n,tot,ans;

void updata(int x){t[x].s=t[t[x].ch[0]].s+t[t[x].ch[1]].s+1;}

void rotate(int x)
{
	int f=t[x].f,ff=t[f].f,q=(x==t[f].ch[1]),ch=t[x].ch[q^1];
	if (ff)  t[ff].ch[t[ff].ch[1]==f]=x,t[x].f=ff;  else  t[x].f=0;
	t[f].ch[q]=ch,t[ch].f=f;
	t[x].ch[q^1]=f,t[f].f=x;
	t[x].s=t[f].s,updata(f);
}

void splay(int x){while (t[x].f)  rotate(x);  root=x;}

void insert(int n,int v)
{
	if (n==0)  {root=++tot,t[tot]=(node){v,1,{0,0},0};  return;}
	t[n].s++;
	if (v<=t[n].k)
		{
			if (t[n].ch[0])  insert(t[n].ch[0],v);
			else  t[n].ch[0]=++tot,t[tot]=(node){v,1,{0,0},n},splay(tot);
		}else
		{
			if (t[n].ch[1])  insert(t[n].ch[1],v);
			else  t[n].ch[1]=++tot,t[tot]=(node){v,1,{0,0},n},splay(tot);
		}
}

int select(int n,int k)
{
	if (k<=t[t[n].ch[0]].s)  return select(t[n].ch[0],k);
	else  if (k==t[t[n].ch[0]].s+1)  return n;
	else  return select(t[n].ch[1],k-t[t[n].ch[0]].s-1);
}

void work()
{
	int x,res;
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		{
			if (scanf("%d",&x)==EOF)  x=0;
			insert(root,x);
			if (i==1)  res=x;  else  res=oo;
			if (t[root].ch[0])
				res=min(res,x-t[select(t[root].ch[0],t[t[root].ch[0]].s)].k);
			if (t[root].ch[1])
				res=min(res,t[select(t[root].ch[1],1)].k-x);
			ans+=res;
		}
	printf("%d",ans);
}

int main()
{
	freopen("1588.in","r",stdin);
	freopen("1588.out","w",stdout);
	work();
	return 0;
}
