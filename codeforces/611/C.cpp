#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int h,w,q,a[505][505],hsum[505][505],wsum[505][505];

void work()
{
	scanf("%d %d",&h,&w);
	for (int i=1; i<=h; i++)
		for (int j=1; j<=w; j++)
			{
				char ch;
				do  ch=getchar();  while ((ch!='.')&&(ch!='#'));
				a[i][j]=(ch=='.');
			}
	for (int i=1; i<=h; i++)
		for (int j=1; j<=w; j++)
			{
				hsum[i][j]=(a[i][j]&a[i-1][j])+hsum[i-1][j]+hsum[i][j-1]-hsum[i-1][j-1];
				wsum[i][j]=(a[i][j]&a[i][j-1])+wsum[i-1][j]+wsum[i][j-1]-wsum[i-1][j-1];
			}
	scanf("%d",&q);
	for (int i=1,r1,c1,r2,c2,ans; i<=q; i++)
		{
			scanf("%d %d %d %d",&r1,&c1,&r2,&c2),ans=0;
			ans+=hsum[r2][c2]-hsum[r1][c2]-hsum[r2][c1-1]+hsum[r1][c1-1];
			ans+=wsum[r2][c2]-wsum[r1-1][c2]-wsum[r2][c1]+wsum[r1-1][c1];
			printf("%d\n",ans);
		}
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
