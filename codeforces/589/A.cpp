#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int sd1=173,sd2=233,mo1=int(1e9+7),mo2=int(1e9-3);
const char Domain[]="@bmail.com";

struct node{int ty,hs1,hs2,id;}a[20010];
int n,m,len[20010];
char ch[20010][105];

bool check(int k)//@bmail.com
{
	char c;
	for (int i=len[k]-9,j=0; i<=len[k]; i++,j++)
		{
			c=ch[k][i];
			if (('A'<=c)&&(c<='Z'))  c+='a'-'A';
			if (c!=Domain[j])  return 0;
		}
	return 1;
}

bool cmp(node x,node y)
{
	if (x.ty!=y.ty)  return x.ty<y.ty;
	if (x.hs1!=y.hs1)  return x.hs1<y.hs1;
	if (x.hs2!=y.hs2)  return x.hs2<y.hs2;
	return x.id<y.id;
}

void work()
{
	scanf("%d\n",&n);
	for (int i=1; i<=n; i++)
		scanf("%s\n",ch[i]+1),len[i]=strlen(ch[i]+1);;
	for (int i=1; i<=n; i++)
		if (check(i))
			{
				int hs1=0,hs2=0;  char c;
				for (int j=1; j<=len[i]; j++)
					if ((ch[i][j]=='@')||(ch[i][j]=='+'))
						break;
					else
						{
							c=ch[i][j];
							if (c=='.')  continue;
							if (('A'<=c)&&(c<='Z'))  c+='a'-'A';
							hs1=(1LL*hs1*sd1+c)%mo1,hs2=(1LL*hs2*sd2+c)%mo2;
						}
				a[i]=(node){1,hs1,hs2,i};
			}else
			{
				int hs1=0,hs2=0;  char c;
				for (int j=1; j<=len[i]; j++)
					{
						c=ch[i][j];
						if (('A'<=c)&&(c<='Z'))  c+='a'-'A';
						hs1=(1LL*hs1*sd1+c)%mo1,hs2=(1LL*hs2*sd2+c)%mo2;
					}
				a[i]=(node){1,hs1,hs2,i};
			}
	sort(a+1,a+n+1,cmp);
	for (int i=1; i<=n; i++)
		if ((i==1)||(a[i].ty!=a[i-1].ty)||(a[i].hs1!=a[i-1].hs1)||(a[i].hs2!=a[i-1].hs2))
			m++;
	printf("%d\n",m);
	for (int i=1; i<=n; i++)
		{
			int l=i,r=i;
			while ((i<n)&&(a[i].ty==a[i+1].ty)&&(a[i].hs1==a[i+1].hs1)&&(a[i].hs2==a[i+1].hs2))  i++,r++;
			printf("%d",r-l+1);
			for (int j=l; j<=r; j++)
				printf(" %s",ch[a[j].id]+1);
			printf("\n");
		}
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
