#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
LL y,l;

bool check(int x,LL b)
{
	LL s=x%10,m=1;
	x/=10;
	while (x)
		{
			if (m>y/b)  return 0;
			m*=b;
			if (s>y-x%10*m)  return 0;
			s+=x%10*m;
			x/=10;
		}
	return s<=y;
}

LL calc(int x,LL b)
{
	LL s=0,m=1;
	while (x)  s+=x%10*m,x/=10,m*=b;
	return s;
}

bool check(int b)
{
	LL x=y,z=0,t=1;
	while (x)
		{
			if (x%b>9)  return 0;
			z+=x%b*t,x/=b,t*=10;
		}
	return z>=l;
}

void work()
{
	cin>>y>>l;
	if (l<=10000)
		for (int i=l; i<=10000; i++)
			{
				LL L=1,R=LL(1e18)+1,mid;
				for (; R-L>1; check(i,mid=(L+R)>>1)?L=mid:R=mid);
				if (calc(i,L)==y)  {cout<<L;  return;}
			}
	for (int i=100000; i; i--)
		if (check(i))  {cout<<i;  return;}
}

int main()
{
	freopen("4612.in","r",stdin);
	freopen("4612.out","w",stdout);
	work();
	return 0;
}
