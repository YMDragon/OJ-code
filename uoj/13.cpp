#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct node{int go,f,nex[27];}t[500010];
int n,m,tot;
char ch[500010];

int get(char *ch)
{
	int x=1;
	for (int i=1,len=strlen(ch+1),y; i<=len; i++)
		{
			if (ch[i]!='/')  y=ch[i]-'a';  else  y=26;
			if (!t[x].nex[y])  t[x].nex[y]=++tot,t[tot].f=x;
			x=t[x].nex[y];
			if (((i==len)||(ch[i+1]=='/'))&&(t[x].go))  x=t[x].go,i+=(x==1);
		}
	return x;
}

void print(int x)
{
	if (x!=1)
		{
			print(t[x].f);
			for (int i=0; i<27; i++)
				if (t[t[x].f].nex[i]==x)
					{if (i!=26)  printf("%c",i+'a');  else  printf("/");}
		}else  printf("/");
}

void work()
{
	scanf("%d %d\n",&n,&m);
	tot=1;
	for (int i=1,sp,tp; i<=n; i++)
		{
			scanf("%s",ch),sp=get(ch);
			scanf("%s",ch),tp=get(ch);
			t[sp].go=tp;
		}
	for (int i=1,x; i<=m; i++)
		{
			scanf("%s",ch),x=get(ch);
			print(x),printf("\n");
		}
}

int main()
{
	freopen("13.in","r",stdin);
	freopen("13.out","w",stdout);
	work();
	return 0;
}
