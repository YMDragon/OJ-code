#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

const int mo=1998585857,sd=173;
int n,m,k,ha[200010],hb[200010];
char a[200010],b[200010];
map <int,int> M;

void work()
{
	scanf("%s\n%s",a+1,b+1);
	n=m=strlen(a+1),k=1;
	while (!(m&1))  m>>=1,k<<=1;
	for (int i=1; i<=k; i++)
		for (int j=(i-1)*m+1; j<=i*m; j++)
			{
				ha[i]=(1LL*ha[i]*sd+a[j])%mo;
				hb[i]=(1LL*hb[i]*sd+b[j])%mo;
			}
	for (int i=1,tot=0; i<=k; i++)
		if (!M[ha[i]])  M[ha[i]]=++tot,ha[i]=tot;  else  ha[i]=M[ha[i]];
	for (int i=1; i<=k; i++)
		if (!M[hb[i]])  {printf("NO");  return;}  else  hb[i]=M[hb[i]];
	for (int i=k/2,len=2; i>=1; i>>=1,len<<=1)
		for (int j=0; j<i; j++)
			{
				int tag=0;
				for (int l=1; l<=len/2; l++)
					if (ha[j*len+l]!=ha[j*len+l+len/2])
						{
							tag=ha[j*len+l]>ha[j*len+l+len/2];
							break;
						}
				if (tag)
					for (int l=1; l<=len/2; l++)  swap(ha[j*len+l],ha[j*len+l+len/2]);
				tag=0;
				for (int l=1; l<=len/2; l++)
					if (hb[j*len+l]!=hb[j*len+l+len/2])
						{
							tag=hb[j*len+l]>hb[j*len+l+len/2];
							break;
						}
				if (tag)
					for (int l=1; l<=len/2; l++)  swap(hb[j*len+l],hb[j*len+l+len/2]);
			}
	for (int i=1; i<=k; i++)
		if (ha[i]!=hb[i])  {printf("NO");  return;}
	printf("YES");
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
