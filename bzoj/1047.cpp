#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int a,b,n,ans;
int s[1010][1010],hmax[1010][1010],hmin[1010][1010];
int amax[1010][1010],amin[1010][1010];

int getint()
{
	char ch=getchar();
	int w=0,q=1;
	while (((ch<'0')||(ch>'9'))&&(ch!='-'))  ch=getchar();
	if (ch=='-')  q=-1,ch=getchar();
	while ((ch>='0')&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return w*q;
}

void work()
{
	scanf("%d %d %d",&a,&b,&n);
	for (int i=1; i<=a; i++)
		for (int j=1; j<=b; j++)
			s[i][j]=getint();
	for (int i=1; i<=a; i++)
		for (int j=1; j<=b-n+1; j++)
			{
				hmax[i][j]=s[i][j],hmin[i][j]=s[i][j];
				for (int l=j+1; l<j+n; l++)
					{
						hmax[i][j]=max(hmax[i][j],s[i][l]);
						hmin[i][j]=min(hmin[i][j],s[i][l]);
					}
			}
	for (int i=1; i<=a-n+1; i++)
		for (int j=1; j<=b-n+1; j++)
			{
				amax[i][j]=hmax[i][j],amin[i][j]=hmin[i][j];
				for(int l=i+1; l<i+n; l++)
					{
						amax[i][j]=max(amax[i][j],hmax[l][j]);
						amin[i][j]=min(amin[i][j],hmin[l][j]);
					}
			}
	ans=amax[1][1]-amin[1][1];
	for (int i=1; i<=a-n+1; i++)
		for (int j=1; j<=b-n+1; j++)
			ans=min(ans,amax[i][j]-amin[i][j]);
	printf("%d",ans);	       
}

int main()
{
	freopen("1047.in","r",stdin);
	freopen("1047.out","w",stdout);
	work();
	return 0;
} 
