#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long  LL;
LL a,b,c,x1,x2,y1,y2,x0,y0,d,l1,r1,l2,r2;

LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if (!b)  return x=1,y=0,a;
	LL d=exgcd(b,a%b,y,x);
	return y-=a/b*x,d;
}

void solve(LL l,LL r,LL a,LL &ansl,LL &ansr)
{
	if (a<0)  l=-l,r=-r,a=-a,swap(l,r);
	ansl=(l>0)?(l-1)/a+1:l/a;
	ansr=(r>=0)?r/a:(r+1)/a-1;
}

void work()
{
	cin>>a>>b>>c>>x1>>x2>>y1>>y2,c=-c;
	if ((x1>x2)||(y1>y2))  cout<<0,exit(0);
	if (a*b==0)
		{
			if ((a==0)&&(b==0))
				if (c==0)  cout<<1LL*(x2-x1+1)*(y2-y1+1);  else  cout<<0;
			else
				if (a==0)
					if ((c%b==0)&&(y1<=c/b)&&(c/b<=y2))  cout<<(x2-x1+1);  else  cout<<0;
				else
					if ((c%a==0)&&(x1<=c/a)&&(c/a<=x2))  cout<<(y2-y1+1);  else  cout<<0;
			exit(0);
		}
	d=exgcd(a,b,x0,y0);
	if (c%d!=0)  cout<<0;
	else
		{
			x0*=c/d,y0*=c/d,a/=d,b/=d;
			solve(x1-x0,x2-x0,b,l1,r1),solve(y0-y2,y0-y1,a,l2,r2);
			cout<<max(0LL,min(r1,r2)-max(l1,l2)+1);
		}
}

int main()
{
	freopen("106.in","r",stdin);
	freopen("106.out","w",stdout);
	work();
	return 0;
}
