#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define oo  (1<<30)
#define LL  long long
using namespace std;

void work()
{
  int x1,y1,x2,y2,x,y;
  x1=getchar()-'a'+1;
  scanf("%d\n",&y1);
  x2=getchar()-'a'+1;
  scanf("%d\n",&y2);
  x=x2-x1,y=y2-y1;
  printf("%d\n",int(max(fabs(x),fabs(y))));
  if ((x>0)&&(y>0))
    for (; (x!=0)&&(y!=0); x--,y--)
      printf("RU\n");
  if ((x>0)&&(y<0))
    for (; (x!=0)&&(y!=0); x--,y++)
      printf("RD\n");
  if ((x<0)&&(y>0))
    for (; (x!=0)&&(y!=0); x++,y--)
      printf("LU\n");
  if ((x<0)&&(y<0))
    for (; (x!=0)&&(y!=0); x++,y++)
      printf("LD\n");
  if (x>0)
    for (; x!=0; x--)
      printf("R\n");
  if (x<0)
    for (; x!=0; x++)
      printf("L\n");
  if (y>0)
    for (; y!=0; y--)
      printf("U\n");
  if (y<0)
    for (; y!=0; y++)
      printf("D\n");
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
  work();
  return 0;
}
