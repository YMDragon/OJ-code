#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define oo  (1<<30)
#define LL  long long
using namespace std;

struct node{char name[40];int score;}p[1010],pp[1010],inpu[1010];
int n,ans,max_score,tot;

int check(node a,node b)
{
  if (strlen(a.name)!=strlen(b.name))
    return 0;
  for (int i=0,len=strlen(a.name); i<len; i++)
    if (a.name[i]!=b.name[i])  return 0;
  return 1;
}

void work()
{
  scanf("%d\n",&n);
  for (int i=1; i<=n; i++)
    {
      scanf("%s %d\n",inpu[i].name,&inpu[i].score);
      int f=1;
      for (int j=1; j<=tot; j++)
    if (check(p[j],inpu[i]))
      {f=0,p[j].score+=inpu[i].score;  break;}
      if (f)
    p[++tot]=inpu[i];
    }
  max_score=-(1<<30);
  for (int i=1; i<=tot; i++)
    max_score=max(max_score,p[i].score);
  tot=0;
  for (int i=1; i<=n; i++)
    {
      int f=1;
      for (int j=1; j<=tot; j++)
    if (check(pp[j],inpu[i]))
      {
        f=0,pp[j].score+=inpu[i].score;
        if (p[j].score==max_score)
          if (pp[j].score>=max_score)  {printf("%s",pp[j].name);  return;}
      }
      if (f)
    {
      pp[++tot]=inpu[i];
      if (p[tot].score==max_score)
        if (pp[tot].score>=max_score)  {printf("%s",pp[tot].name);  return;}
    }
    }
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
  work();
  return 0;
}
