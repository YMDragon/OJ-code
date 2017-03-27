#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int x,y,X,Y,n,a[505][505],ans;
char ch[100010];

void work()
{
	scanf("%d %d %d %d\n%s",&x,&y,&X,&Y,ch+1),n=strlen(ch+1),ans=x*y;
	for (int i=1; i<=n; i++)
		{
			printf("%d ",!a[X][Y]);
			if (!a[X][Y])  a[X][Y]=1,ans--;
			if ((ch[i]=='L')&&(Y!=1))  Y--;
			if ((ch[i]=='R')&&(Y!=y))  Y++;
			if ((ch[i]=='U')&&(X!=1))  X--;
			if ((ch[i]=='D')&&(X!=x))  X++;
		}
	printf("%d ",ans);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
