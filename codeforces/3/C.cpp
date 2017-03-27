#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define oo  (1<<30)
#define LL  long long
using namespace std;

int a[3][3],s0,s1;

int win(int x)
{
  if ((a[0][0]==x)&&(a[0][1]==x)&&(a[0][2]==x))  return 1;
  if ((a[1][0]==x)&&(a[1][1]==x)&&(a[1][2]==x))  return 1;
  if ((a[2][0]==x)&&(a[2][1]==x)&&(a[2][2]==x))  return 1;
  if ((a[0][0]==x)&&(a[1][0]==x)&&(a[2][0]==x))  return 1;
  if ((a[0][1]==x)&&(a[1][1]==x)&&(a[2][1]==x))  return 1;
  if ((a[0][2]==x)&&(a[1][2]==x)&&(a[2][2]==x))  return 1;
  if ((a[0][0]==x)&&(a[1][1]==x)&&(a[2][2]==x))  return 1;
  if ((a[0][2]==x)&&(a[1][1]==x)&&(a[2][0]==x))  return 1;
  return 0;
}

int check()
{
  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
      {
    if (a[i][j]==1)  s1++;
    if (a[i][j]==0)  s0++;
      }
  if ((s1-s0!=0)&&(s1-s0!=1))  return 1;
  if ((win(1))&&(s1-s0!=1))  return 1;
  if ((win(0))&&(s1-s0!=0))  return 1;
  return 0;
}

void work()
{
  char ch;
  for (int i=0; i<3; i++)
    {
      for (int j=0; j<3; j++)
    {
      ch=getchar();
      if (ch=='X')  a[i][j]=1;
      if (ch=='0')  a[i][j]=0;
      if (ch=='.')  a[i][j]=-1;
    }
      if (i!=2)  getchar();
    }
  if (check()){printf("illegal");  return;}
  if (win(1)==1)  {printf("the first player won");  return;}
  if (win(0)==1)  {printf("the second player won");  return;}
  if (s0+s1==9)  {printf("draw");  return;}
  if (s1==s0)  {printf("first");  return;}
  if (s1-s0==1) {printf("second");  return;}
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
  work();
  return 0;
}
