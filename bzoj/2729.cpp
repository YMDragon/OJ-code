#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=10000;
struct Longint{
	int n[3000],len;
}x,y;
int n,m;

Longint operator + (Longint x,Longint y)
{
	x.len=max(x.len,y.len);
	for (int i=1; i<=x.len; i++)
		x.n[i]+=y.n[i];
	for (int i=1; i<=x.len; i++)
		if (x.n[i]>=mo)  x.n[i]-=mo,x.n[i+1]++;
	if (x.n[x.len+1])  x.len++;
	return x;
}

Longint operator * (Longint x,int y)
{
	for (int i=1; i<=x.len; i++)
		x.n[i]*=y;
	for (int i=1; i<=x.len; i++)
		if (x.n[i]>=mo)  x.n[i+1]+=x.n[i]/mo,x.n[i]%=mo;
	if (x.n[x.len+1])  x.len++;
	return x;
}

void print(Longint x)
{
	printf("%d",x.n[x.len]);
	for (int i=x.len-1; i>=1; i--)
		{
			if (x.n[i]<1000)  printf("0");
			if (x.n[i]<100)  printf("0");
			if (x.n[i]<10)  printf("0");
			printf("%d",x.n[i]);
		}
}

void work()
{
	scanf("%d %d",&n,&m);
	x.len=y.len=1,x.n[1]=y.n[1]=1;
	x=x*(n+1)*2*m;
	for (int i=1; i<m; i++)
		x=x*(n+3-i);
	y=y*(n+1)*n;
	for (int i=1; i<=m; i++)
		y=y*(n+4-i);
	x=x+y;
	for (int i=1; i<=n; i++)
		x=x*i;
	print(x);
}

int main()
{
	freopen("2729.in","r",stdin);
	freopen("2729.out","w",stdout);
	work();
	return 0;
}
