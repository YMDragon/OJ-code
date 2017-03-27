#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct node{
	int x,fail,son[65];
	int& operator [](int x){return son[x];}
}t[2500010];
int n,m,tot,root,a[505],Q[2500010];
char ch[50010];

int trans(char c)
{
	if (('a'<=c)&&(c<='z'))  return c-'a';
	if (('A'<=c)&&(c<='Z'))  return c-'A'+26;
	if (('0'<=c)&&(c<='9'))  return c-'0'+52;
	return 62;
}

int insert(char *ch)
{
	int len=strlen(ch+1),x=root,y;
	for (int i=1; i<=len; i++)
		{
			y=trans(ch[i]);
			if (!t[x][y])  t[x][y]=++tot;
			x=t[x][y];
		}
	return x;
}

void prepare()
{
	int x,y,i,L=1,R=0;
	Q[++R]=root,t[root].fail=root;
	for (i=0; i<=62; i++)  if (!t[root][i])  t[root][i]=root;
	while (L<=R)
		for (x=Q[L++],i=0; y=t[x][i],i<=62; i++)
			{
				if (y>root)  Q[++R]=y;  else  t[x][i]=t[t[x].fail][i];
				if (x==root)  {if (y)  t[y].fail=x;}
				else  {if (y)  t[y].fail=t[t[x].fail][i];}
			}
}

void run(char *ch)
{
	int len=strlen(ch+1),x=root;
	for (int i=1; i<=len; i++)
		x=t[x][trans(ch[i])],t[x].x++;
}

void work()
{
	scanf("%d\n",&n),root=tot=1;
	for (int i=1; i<=n; i++)  scanf("%s\n",ch+1),a[i]=insert(ch);
	prepare();
	scanf("%d\n",&m);
	for (int i=1; i<=m; i++)  scanf("%s\n",ch+1),run(ch);
	for (int i=tot; i; i--)  t[t[Q[i]].fail].x+=t[Q[i]].x;
	for (int i=1; i<=n; i++)  printf("%d\n",t[a[i]].x);
}

int main()
{
	freopen("LYRC.in","r",stdin);
	freopen("LYRC.out","w",stdout);
	work();
	return 0;
}
