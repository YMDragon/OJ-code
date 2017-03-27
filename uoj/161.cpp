#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int N=1000010;
int n,h[N],t[N],ht[N],a[N],b[N],c[N],cnt[100010];
double sum,ans[N];

int gi()
{
	int w=0;  char ch=getchar();
	while ((ch<'0')||('9'<ch))  ch=getchar();
	while (('0'<=ch)&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return w;
}

void pd(double x)
{
	printf("%d.",int(x)),x-=int(x);
	x*=10,printf("%d",int(x)),x-=int(x);
	x*=10,printf("%d",int(x)),x-=int(x);
	x*=10,printf("%d",int(x)),x-=int(x);
}

void sorta()
{
	for (int i=0; i<=100000; i++)  cnt[i]=0;
	for (int i=1; i<=n; i++)  cnt[t[i]]++;
	for (int i=1; i<=100000; i++)  cnt[i]+=cnt[i-1];
	for (int i=n; i; i--)  c[cnt[t[i]]--]=i;
	for (int i=0; i<=100000; i++)  cnt[i]=0;
	for (int i=n; i; i--)  cnt[ht[c[i]]]++;
	for (int i=1; i<=100000; i++)  cnt[i]+=cnt[i-1];
	for (int i=n; i; i--)  a[cnt[ht[c[i]]]--]=c[i];
}

void sortb()
{
	for (int i=0; i<=100000; i++)  cnt[i]=0;
	for (int i=1; i<=n; i++)  cnt[t[i]]++;
	for (int i=1; i<=100000; i++)  cnt[i]+=cnt[i-1];
	for (int i=n; i; i--)  c[cnt[t[i]]--]=i;
	for (int i=0; i<=100000; i++)  cnt[i]=0;
	for (int i=1; i<=n; i++)  cnt[h[c[i]]]++;
	for (int i=1; i<=100000; i++)  cnt[i]+=cnt[i-1];
	for (int i=1; i<=n; i++)  b[cnt[h[c[i]]]--]=c[i];
}

void work()
{
	n=gi();
	for (int i=1; i<=n; i++)  h[i]=gi();
	for (int i=1; i<=n; i++)  t[i]=gi(),ht[i]=h[i]-t[i];
	//for (int i=1; i<=n; i++)  a[i]=b[i]=i;
	//sort(a+1,a+n+1,cmpa);
	//sort(b+1,b+n+1,cmpb);
	sorta(),sortb();
	for (int i=1,j=0,_=0; i<=n; i++)
		{
			if (h[a[i]]!=h[a[i-1]])
				for (int k=j-_+1; k<=j; k++)
					sum=((ans[b[k]]==-1)||(sum==-1)?-1:(sum+ans[b[k]]));
			while ((j<n)&&(h[b[j+1]]<=ht[a[i]]))
				j++,sum=((ans[b[j]]==-1)||(sum==-1)?-1:(sum+ans[b[j]]));
			if ((t[a[i]]==0)&&((h[a[i]]!=h[a[i-1]])||(t[a[i-1]])))
				{
					_=0;
					while ((_<j)&&(h[b[j-_]]==h[a[i]])&&(t[b[j-_]]==0))  _++;
				}else  if (t[a[i]])  _=0;
			if (j-_==0)  if (_)  ans[a[i]]=-1;  else  ans[a[i]]=1;
			else  ans[a[i]]=(sum==-1?-1:((sum+j)/(j-_)));
		}
	for (int i=1; i<=n; i++)
		{
			if (ans[i]<0)  pd(0);  else  pd(ans[i]);
			putchar(' ');
		}
}

int main()
{
	freopen("161.in","r",stdin);
	freopen("161.out","w",stdout);
	work();
	return 0;
}
