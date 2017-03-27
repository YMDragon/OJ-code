#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define oo  (1<<30)
#define LL  long long
using namespace std;

char ch[100];
int len,n;

int check()
{
  if ((ch[0]=='R')&&('1'<=ch[1])&&(ch[1]<='9'))
    for (int i=2; i<len; i++)
      if (ch[i]=='C')  return i;
  return 0;
}

void print(int a)
{
  if (a)
    {
      print((a-1)/26);
      printf("%c",'A'+(a-1)%26);
    }
}

void work()
{
  scanf("%d\n",&n);
  for (int i=1; i<=n; i++)
    {
      int t,a=0,b=0,c=1;
      scanf("%s\n",ch);
      len=strlen(ch);
      t=check();
      if (t)
    {
      for (int i=1; i<t; i++)
        a=a*10+ch[i]-'0';
      for (int i=t+1; i<len; i++)
        b=b*10+ch[i]-'0';
      print(b);
      printf("%d\n",a);
    }else
    {
      for (int i=0; i<len; i++)
        if (('1'<=ch[i])&&(ch[i]<='9'))  {t=i;  break;}
      for (int i=t-1; i>=0; i--)
        a+=c*(ch[i]-'A'+1),c*=26;
      for (int i=t; i<len; i++)
        b=b*10+ch[i]-'0';
      printf("R%dC%d\n",b,a);
    }
    }
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
  work();
  return 0;
}
