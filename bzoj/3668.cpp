#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int f[40][2],n,m,len,op[100010][40],ans;

void work()
{
	scanf("%d %d\n",&n,&m);
	char ch[3];
	int maxk=0;
	for (int i=1,k; i<=n; i++)
		{
			scanf("%s %d\n",ch,&op[i][1]),k=1;
			while (op[i][k])  op[i][k+1]=op[i][k]/2,op[i][k]%=2,k++;
			maxk=max(maxk,k-1);
			if (ch[0]=='A')  op[i][0]=1;
			if (ch[0]=='O')  op[i][0]=2;
			if (ch[0]=='X')  op[i][0]=3;
		}
	for (int x=m; x; len++)  x/=2;
	len=max(len,maxk);
	for (int i=1; i<=len; i++)
		for (int j=0; j<=1; j++)
			{
				f[i][j]=j;
				for (int k=1; k<=n; k++)
					if (op[k][0]==1)  f[i][j]&=op[k][i];
					else  if (op[k][0]==2)  f[i][j]|=op[k][i];
					else  f[i][j]^=op[k][i];
			}
	for (int i=len,k=0; i>=1; i--)
		if (k)
			{if ((f[i][0])||(f[i][1]))  ans+=1<<(i-1);}
		else
			if (f[i][0])  ans+=1<<(i-1),k=(m&(1<<(i-1)))>0;
			else  if ((f[i][1])&&(m&(1<<(i-1))))  ans+=1<<(i-1);
			else  k=(m&(1<<(i-1)))>0;;
	printf("%d",ans);
}

int main()
{
	freopen("3668.in","r",stdin);
	freopen("3668.out","w",stdout);
	work();
	return 0;
} 
