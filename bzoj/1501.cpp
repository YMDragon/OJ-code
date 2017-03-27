#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
 
const int n=10;
int map[20][20],b[15];
 
void print()
{
	for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=i; j++)
				printf("%c",map[i][j]+'A'-1);
			printf("\n");
		}
	exit(0);
}
 
void dfs(int x,int y)
{
	while (map[x][y])
		{
			y++;
			if (x<y)  x++,y=1;
			if (x>n)  {print();  return;}
		}
	if ((!b[1])&&(!map[x+1][y])&&(!map[x][y+1]))
		{
			map[x][y]=map[x+1][y]=map[x][y+1]=1,b[1]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y]=map[x][y+1]=0,b[1]=0;
		}
	if ((!b[1])&&(!map[x][y+1])&&(!map[x+1][y+1]))
		{
			map[x][y]=map[x][y+1]=map[x+1][y+1]=1,b[1]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x+1][y+1]=0,b[1]=0;
		}
	if ((!b[1])&&(!map[x+1][y])&&(!map[x+1][y+1]))
		{
			map[x][y]=map[x+1][y]=map[x+1][y+1]=1,b[1]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y]=map[x+1][y+1]=0,b[1]=0;
		}
	if ((!b[1])&&(!map[x+1][y-1])&&(!map[x+1][y]))
		{
			map[x][y]=map[x+1][y-1]=map[x+1][y]=1,b[1]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y-1]=map[x+1][y]=0,b[1]=0;
		}
	if ((!b[2])&&(!map[x][y+1])&&(!map[x][y+2])&&(!map[x][y+3]))
		{
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x][y+3]=2,b[2]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x][y+3]=0,b[2]=0;
		}
	if ((!b[2])&&(!map[x+1][y])&&(!map[x+2][y])&&(!map[x+3][y]))
		{
			map[x][y]=map[x+1][y]=map[x+2][y]=map[x+3][y]=2,b[2]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y]=map[x+2][y]=map[x+3][y]=0,b[2]=0;
		}
	if ((!b[3])&&(!map[x][y+1])&&(!map[x][y+2])&&(!map[x+1][y]))
		{
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x+1][y]=3,b[3]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x+1][y]=0,b[3]=0;
		}
	if ((!b[3])&&(!map[x+1][y])&&(!map[x+1][y+1])&&(!map[x+1][y+2]))
		{
			map[x][y]=map[x+1][y]=map[x+1][y+1]=map[x+1][y+2]=3,b[3]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y]=map[x+1][y+1]=map[x+1][y+2]=0,b[3]=0;
		}
	if ((!b[3])&&(!map[x+1][y])&&(!map[x+2][y])&&(!map[x+2][y+1]))
		{
			map[x][y]=map[x+1][y]=map[x+2][y]=map[x+2][y+1]=3,b[3]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y]=map[x+2][y]=map[x+2][y+1]=0,b[3]=0;
		}
	if ((!b[3])&&(!map[x+1][y])&&(!map[x+2][y-1])&&(!map[x+2][y]))
		{
			map[x][y]=map[x+1][y]=map[x+2][y-1]=map[x+2][y]=3,b[3]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y]=map[x+2][y-1]=map[x+2][y]=0,b[3]=0;
		}
	if ((!b[3])&&(!map[x+1][y-2])&&(!map[x+1][y-1])&&(!map[x+1][y]))
		{
			map[x][y]=map[x+1][y-2]=map[x+1][y-1]=map[x+1][y]=3,b[3]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y-2]=map[x+1][y-1]=map[x+1][y]=0,b[3]=0;
		}
	if ((!b[3])&&(!map[x][y+1])&&(!map[x][y+2])&&(!map[x+1][y+2]))
		{
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x+1][y+2]=3,b[3]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x+1][y+2]=0,b[3]=0;
		}
	if ((!b[3])&&(!map[x][y+1])&&(!map[x+1][y+1])&&(!map[x+2][y+1]))
		{
			map[x][y]=map[x][y+1]=map[x+1][y+1]=map[x+2][y+1]=3,b[3]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x+1][y+1]=map[x+2][y+1]=0,b[3]=0;
		}
	if ((!b[3])&&(!map[x][y+1])&&(!map[x+1][y])&&(!map[x+2][y]))
		{
			map[x][y]=map[x][y+1]=map[x+1][y]=map[x+2][y]=3,b[3]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x+1][y]=map[x+2][y]=0,b[3]=0;
		}
	if ((!b[4])&&(!map[x][y+1])&&(!map[x+1][y])&&(!map[x+1][y+1]))
		{
			map[x][y]=map[x][y+1]=map[x+1][y]=map[x+1][y+1]=4,b[4]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x+1][y]=map[x+1][y+1]=0,b[4]=0;
		}
	if ((!b[5])&&(!map[x][y+1])&&(!map[x][y+2])&&(!map[x+1][y])&&(!map[x+2][y]))
		{
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x+1][y]=map[x+2][y]=5,b[5]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x+1][y]=map[x+2][y]=0,b[5]=0;
		}
	if ((!b[5])&&(!map[x][y+1])&&(!map[x][y+2])&&(!map[x+1][y+2])&&(!map[x+2][y+2]))
		{
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x+1][y+2]=map[x+2][y+2]=5,b[5]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x+1][y+2]=map[x+2][y+2]=0,b[5]=0;
		}
	if ((!b[5])&&(!map[x+1][y])&&(!map[x+2][y])&&(!map[x+2][y+1])&&(!map[x+2][y+2]))
		{
			map[x][y]=map[x+1][y]=map[x+2][y]=map[x+2][y+1]=map[x+2][y+2]=5,b[5]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y]=map[x+2][y]=map[x+2][y+1]=map[x+2][y+2]=0,b[5]=0;
		}
	if ((!b[5])&&(!map[x+1][y])&&(!map[x+2][y-2])&&(!map[x+2][y-1])&&(!map[x+2][y]))
		{
			map[x][y]=map[x+1][y]=map[x+2][y-2]=map[x+2][y-1]=map[x+2][y]=5,b[5]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y]=map[x+2][y-2]=map[x+2][y-1]=map[x+2][y]=0,b[5]=0;
		}
	if ((!b[6])&&(!map[x][y+1])&&(!map[x][y+2])&&(!map[x][y+3])&&(!map[x+1][y+1]))
		{
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x][y+3]=map[x+1][y+1]=6,b[6]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x][y+3]=map[x+1][y+1]=0,b[6]=0;
		}
	if ((!b[6])&&(!map[x+1][y-1])&&(!map[x+1][y])&&(!map[x+1][y+1])&&(!map[x+1][y+2]))
		{
			map[x][y]=map[x+1][y-1]=map[x+1][y]=map[x+1][y+1]=map[x+1][y+2]=6,b[6]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y-1]=map[x+1][y]=map[x+1][y+1]=map[x+1][y+2]=0,b[6]=0;
		}
	if ((!b[6])&&(!map[x][y+1])&&(!map[x][y+2])&&(!map[x][y+3])&&(!map[x+1][y+2]))
		{
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x][y+3]=map[x+1][y+2]=6,b[6]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x][y+3]=map[x+1][y+2]=0,b[6]=0;
		}
	if ((!b[6])&&(!map[x+1][y-2])&&(!map[x+1][y-1])&&(!map[x+1][y])&&(!map[x+1][y+1]))
		{
			map[x][y]=map[x+1][y-2]=map[x+1][y-1]=map[x+1][y]=map[x+1][y+1]=6,b[6]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y-2]=map[x+1][y-1]=map[x+1][y]=map[x+1][y+1]=0,b[6]=0;
		}
	if ((!b[6])&&(!map[x+1][y])&&(!map[x+1][y+1])&&(!map[x+2][y])&&(!map[x+3][y]))
		{
			map[x][y]=map[x+1][y]=map[x+1][y+1]=map[x+2][y]=map[x+3][y]=6,b[6]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y]=map[x+1][y+1]=map[x+2][y]=map[x+3][y]=0,b[6]=0;
		}
	if ((!b[6])&&(!map[x+1][y-1])&&(!map[x+1][y])&&(!map[x+2][y])&&(!map[x+3][y]))
		{
			map[x][y]=map[x+1][y-1]=map[x+1][y]=map[x+2][y]=map[x+3][y]=6,b[6]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y-1]=map[x+1][y]=map[x+2][y]=map[x+3][y]=0,b[6]=0;
		}
	if ((!b[6])&&(!map[x+1][y])&&(!map[x+2][y])&&(!map[x+2][y+1])&&(!map[x+3][y]))
		{
			map[x][y]=map[x+1][y]=map[x+2][y]=map[x+2][y+1]=map[x+3][y]=6,b[6]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y]=map[x+2][y]=map[x+2][y+1]=map[x+3][y]=0,b[6]=0;
		}
	if ((!b[6])&&(!map[x+1][y])&&(!map[x+2][y-1])&&(!map[x+2][y])&&(!map[x+3][y]))
		{
			map[x][y]=map[x+1][y]=map[x+2][y-1]=map[x+2][y]=map[x+3][y]=6,b[6]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y]=map[x+2][y-1]=map[x+2][y]=map[x+3][y]=0,b[6]=0;
		}
	if ((!b[7])&&(!map[x][y+1])&&(!map[x][y+2])&&(!map[x+1][y])&&(!map[x+1][y+2]))
		{
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x+1][y]=map[x+1][y+2]=7,b[7]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x+1][y]=map[x+1][y+2]=0,b[7]=0;
		}
	if ((!b[7])&&(!map[x][y+1])&&(!map[x+1][y])&&(!map[x+2][y])&&(!map[x+2][y+1]))
		{
			map[x][y]=map[x][y+1]=map[x+1][y]=map[x+2][y]=map[x+2][y+1]=7,b[7]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x+1][y]=map[x+2][y]=map[x+2][y+1]=0,b[7]=0;
		}
	if ((!b[7])&&(!map[x][y+2])&&(!map[x+1][y])&&(!map[x+1][y+1])&&(!map[x+1][y+2]))
		{
			map[x][y]=map[x][y+2]=map[x+1][y]=map[x+1][y+1]=map[x+1][y+2]=7,b[7]=1;
			dfs(x,y);
			map[x][y]=map[x][y+2]=map[x+1][y]=map[x+1][y+1]=map[x+1][y+2]=0,b[7]=0;
		}
	if ((!b[7])&&(!map[x][y+1])&&(!map[x+1][y+1])&&(!map[x+2][y])&&(!map[x+2][y+1]))
		{
			map[x][y]=map[x][y+1]=map[x+1][y+1]=map[x+2][y]=map[x+2][y+1]=7,b[7]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x+1][y+1]=map[x+2][y]=map[x+2][y+1]=0,b[7]=0;
		}
	if ((!b[8])&&(!map[x][y+1])&&(!map[x][y+2])&&(!map[x+1][y])&&(!map[x+1][y+1]))
		{
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x+1][y]=map[x+1][y+1]=8,b[8]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x+1][y]=map[x+1][y+1]=0,b[8]=0;
		}
	if ((!b[8])&&(!map[x][y+1])&&(!map[x+1][y])&&(!map[x+1][y+1])&&(!map[x+1][y+2]))
		{
			map[x][y]=map[x][y+1]=map[x+1][y]=map[x+1][y+1]=map[x+1][y+2]=8,b[8]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x+1][y]=map[x+1][y+1]=map[x+1][y+2]=0,b[8]=0;
		}
	if ((!b[8])&&(!map[x+1][y])&&(!map[x+1][y+1])&&(!map[x+2][y])&&(!map[x+2][y+1]))
		{
			map[x][y]=map[x+1][y]=map[x+1][y+1]=map[x+2][y]=map[x+2][y+1]=8,b[8]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y]=map[x+1][y+1]=map[x+2][y]=map[x+2][y+1]=0,b[8]=0;
		}
	if ((!b[8])&&(!map[x+1][y-1])&&(!map[x+1][y])&&(!map[x+2][y-1])&&(!map[x+2][y]))
		{
			map[x][y]=map[x+1][y-1]=map[x+1][y]=map[x+2][y-1]=map[x+2][y]=8,b[8]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y-1]=map[x+1][y]=map[x+2][y-1]=map[x+2][y]=0,b[8]=0;
		}
	if ((!b[8])&&(!map[x][y+1])&&(!map[x+1][y-1])&&(!map[x+1][y])&&(!map[x+1][y+1]))
		{
			map[x][y]=map[x][y+1]=map[x+1][y-1]=map[x+1][y]=map[x+1][y+1]=8,b[8]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x+1][y-1]=map[x+1][y]=map[x+1][y+1]=0,b[8]=0;
		}
	if ((!b[8])&&(!map[x][y+1])&&(!map[x][y+2])&&(!map[x+1][y+1])&&(!map[x+1][y+2]))
		{
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x+1][y+1]=map[x+1][y+2]=8,b[8]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x+1][y+1]=map[x+1][y+2]=0,b[8]=0;
		}
	if ((!b[8])&&(!map[x][y+1])&&(!map[x+1][y])&&(!map[x+1][y+1])&&(!map[x+2][y+1]))
		{
			map[x][y]=map[x][y+1]=map[x+1][y]=map[x+1][y+1]=map[x+2][y+1]=8,b[8]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x+1][y]=map[x+1][y+1]=map[x+2][y+1]=0,b[8]=0;
		}
	if ((!b[8])&&(!map[x][y+1])&&(!map[x+1][y])&&(!map[x+1][y+1])&&(!map[x+2][y]))
		{
			map[x][y]=map[x][y+1]=map[x+1][y]=map[x+1][y+1]=map[x+2][y]=8,b[8]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x+1][y]=map[x+1][y+1]=map[x+2][y]=0,b[8]=0;
		}
	if ((!b[9])&&(!map[x][y+1])&&(!map[x][y+2])&&(!map[x+1][y+2])&&(!map[x+1][y+3]))
		{
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x+1][y+2]=map[x+1][y+3]=9,b[9]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x+1][y+2]=map[x+1][y+3]=0,b[9]=0;
		}
	if ((!b[9])&&(!map[x][y+1])&&(!map[x+1][y-2])&&(!map[x+1][y-1])&&(!map[x+1][y]))
		{
			map[x][y]=map[x][y+1]=map[x+1][y-2]=map[x+1][y-1]=map[x+1][y]=9,b[9]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x+1][y-2]=map[x+1][y-1]=map[x+1][y]=0,b[9]=0;
		}
	if ((!b[9])&&(!map[x+1][y-1])&&(!map[x+1][y])&&(!map[x+2][y-1])&&(!map[x+3][y-1]))
		{
			map[x][y]=map[x+1][y-1]=map[x+1][y]=map[x+2][y-1]=map[x+3][y-1]=9,b[9]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y-1]=map[x+1][y]=map[x+2][y-1]=map[x+3][y-1]=0,b[9]=0;
		}
	if ((!b[9])&&(!map[x+1][y])&&(!map[x+1][y+1])&&(!map[x+2][y+1])&&(!map[x+3][y+1]))
		{
			map[x][y]=map[x+1][y]=map[x+1][y+1]=map[x+2][y+1]=map[x+3][y+1]=9,b[9]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y]=map[x+1][y+1]=map[x+2][y+1]=map[x+3][y+1]=0,b[9]=0;
		}
	if ((!b[9])&&(!map[x][y+1])&&(!map[x+1][y+1])&&(!map[x+1][y+2])&&(!map[x+1][y+3]))
		{
			map[x][y]=map[x][y+1]=map[x+1][y+1]=map[x+1][y+2]=map[x+1][y+3]=9,b[9]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x+1][y+1]=map[x+1][y+2]=map[x+1][y+3]=0,b[9]=0;
		}
	if ((!b[9])&&(!map[x][y+1])&&(!map[x][y+2])&&(!map[x+1][y-1])&&(!map[x+1][y]))
		{
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x+1][y-1]=map[x+1][y]=9,b[9]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x+1][y-1]=map[x+1][y]=0,b[9]=0;
		}
	if ((!b[9])&&(!map[x+1][y])&&(!map[x+2][y-1])&&(!map[x+2][y])&&(!map[x+3][y-1]))
		{
			map[x][y]=map[x+1][y]=map[x+2][y-1]=map[x+2][y]=map[x+3][y-1]=9,b[9]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y]=map[x+2][y-1]=map[x+2][y]=map[x+3][y-1]=0,b[9]=0;
		}
	if ((!b[9])&&(!map[x+1][y])&&(!map[x+2][y])&&(!map[x+2][y+1])&&(!map[x+3][y+1]))
		{
			map[x][y]=map[x+1][y]=map[x+2][y]=map[x+2][y+1]=map[x+3][y+1]=9,b[9]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y]=map[x+2][y]=map[x+2][y+1]=map[x+3][y+1]=0,b[9]=0;
		}
	if ((!b[10])&&(!map[x+1][y-1])&&(!map[x+1][y])&&(!map[x+1][y+1])&&(!map[x+2][y]))
		{
			map[x][y]=map[x+1][y-1]=map[x+1][y]=map[x+1][y+1]=map[x+2][y]=10,b[10]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y-1]=map[x+1][y]=map[x+1][y+1]=map[x+2][y]=0,b[10]=0;
		}
	if ((!b[11])&&(!map[x+1][y])&&(!map[x+1][y+1])&&(!map[x+2][y+1])&&(!map[x+2][y+2]))
		{
			map[x][y]=map[x+1][y]=map[x+1][y+1]=map[x+2][y+1]=map[x+2][y+2]=11,b[11]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y]=map[x+1][y+1]=map[x+2][y+1]=map[x+2][y+2]=0,b[11]=0;
		}
	if ((!b[11])&&(!map[x+1][y-1])&&(!map[x+1][y])&&(!map[x+2][y-2])&&(!map[x+2][y-1]))
		{
			map[x][y]=map[x+1][y-1]=map[x+1][y]=map[x+2][y-2]=map[x+2][y-1]=11,b[11]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y-1]=map[x+1][y]=map[x+2][y-2]=map[x+2][y-1]=0,b[11]=0;
		}
	if ((!b[11])&&(!map[x][y+1])&&(!map[x+1][y-1])&&(!map[x+1][y])&&(!map[x+2][y-1]))
		{
			map[x][y]=map[x][y+1]=map[x+1][y-1]=map[x+1][y]=map[x+2][y-1]=11,b[11]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x+1][y-1]=map[x+1][y]=map[x+2][y-1]=0,b[11]=0;
		}
	if ((!b[11])&&(!map[x][y+1])&&(!map[x+1][y+1])&&(!map[x+1][y+2])&&(!map[x+2][y+2]))
		{
			map[x][y]=map[x][y+1]=map[x+1][y+1]=map[x+1][y+2]=map[x+2][y+2]=11,b[11]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x+1][y+1]=map[x+1][y+2]=map[x+2][y+2]=0,b[11]=0;
		}
	if ((!b[12])&&(!map[x][y+1])&&(!map[x][y+2])&&(!map[x][y+3])&&(!map[x+1][y]))
		{
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x][y+3]=map[x+1][y]=12,b[12]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x][y+3]=map[x+1][y]=0,b[12]=0;
		}
	if ((!b[12])&&(!map[x+1][y])&&(!map[x+1][y+1])&&(!map[x+1][y+2])&&(!map[x+1][y+3]))
		{
			map[x][y]=map[x+1][y]=map[x+1][y+1]=map[x+1][y+2]=map[x+1][y+3]=12,b[12]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y]=map[x+1][y+1]=map[x+1][y+2]=map[x+1][y+3]=0,b[12]=0;
		}
	if ((!b[12])&&(!map[x+1][y])&&(!map[x+2][y])&&(!map[x+3][y])&&(!map[x+3][y+1]))
		{
			map[x][y]=map[x+1][y]=map[x+2][y]=map[x+3][y]=map[x+3][y+1]=12,b[12]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y]=map[x+2][y]=map[x+3][y]=map[x+3][y+1]=0,b[12]=0;
		}
	if ((!b[12])&&(!map[x+1][y])&&(!map[x+2][y])&&(!map[x+3][y-1])&&(!map[x+3][y]))
		{
			map[x][y]=map[x+1][y]=map[x+2][y]=map[x+3][y-1]=map[x+3][y]=12,b[12]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y]=map[x+2][y]=map[x+3][y-1]=map[x+3][y]=0,b[12]=0;
		}
	if ((!b[12])&&(!map[x+1][y-3])&&(!map[x+1][y-2])&&(!map[x+1][y-1])&&(!map[x+1][y]))
		{
			map[x][y]=map[x+1][y-3]=map[x+1][y-2]=map[x+1][y-1]=map[x+1][y]=12,b[12]=1;
			dfs(x,y);
			map[x][y]=map[x+1][y-3]=map[x+1][y-2]=map[x+1][y-1]=map[x+1][y]=0,b[12]=0;
		}
	if ((!b[12])&&(!map[x][y+1])&&(!map[x][y+2])&&(!map[x][y+3])&&(!map[x+1][y+3]))
		{
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x][y+3]=map[x+1][y+3]=12,b[12]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x][y+2]=map[x][y+3]=map[x+1][y+3]=0,b[12]=0;
		}
	if ((!b[12])&&(!map[x][y+1])&&(!map[x+1][y+1])&&(!map[x+2][y+1])&&(!map[x+3][y+1]))
		{
			map[x][y]=map[x][y+1]=map[x+1][y+1]=map[x+2][y+1]=map[x+3][y+1]=12,b[12]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x+1][y+1]=map[x+2][y+1]=map[x+3][y+1]=0,b[12]=0;
		}
	if ((!b[12])&&(!map[x][y+1])&&(!map[x+1][y])&&(!map[x+2][y])&&(!map[x+3][y]))
		{
			map[x][y]=map[x][y+1]=map[x+1][y]=map[x+2][y]=map[x+3][y]=12,b[12]=1;
			dfs(x,y);
			map[x][y]=map[x][y+1]=map[x+1][y]=map[x+2][y]=map[x+3][y]=0,b[12]=0;
		}
}
 
void work()
{
	char ch;
	memset(map,127,sizeof(map));
	for (int i=1; i<=n; i++)
		for (int j=1; j<=i; j++)
			{
				ch=getchar();
				while ((ch!='.')&&((ch<'A')||(ch>'L')))  ch=getchar();
				if (ch=='.')  map[i][j]=0;
				else  map[i][j]=ch-'A'+1,b[map[i][j]]=1;
			}
	dfs(1,1);
	printf("No solution");
}
 
int main()
{
	freopen("1501.in","r",stdin);
	freopen("1501.out","w",stdout);
	work();
	return 0;
}
