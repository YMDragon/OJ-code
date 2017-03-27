#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int m;

struct node{
	int h,a,x,y,t,T,tag;

	void read()
	{
		scanf("%d %d %d %d",&h,&a,&x,&y);
	}

	int f(int h){return (1LL*x*h+y)%m;}

	void solve()
	{
		int X=h,Y=h;
		tag=0;
		if (h==a)  return (void)(tag=1);
		do{
			X=f(X),Y=f(f(Y)),t+=1-tag;
			if (X==a)  tag=1;
		}while (X!=Y);
		do{
			X=f(X),T++;
		}while (X!=Y);
		if (tag)
			{
				X=a;
				for (int i=1; i<=T; i++)
					X=f(X);
				if (X!=a)  tag=2;
			}
	}
}a,b;

void work()
{
	scanf("%d",&m);
	a.read(),b.read();
	a.solve();
	if (a.tag==0)  return (void)printf("-1");
	if (a.tag==2)
		{
			int X=b.h;
			for (int i=1; i<=a.t; i++)  X=b.f(X);
			if (X==b.a)  printf("%d",a.t);  else  printf("-1");
			return;
		}
	for (int i=1; i<=a.t; i++)  b.h=b.f(b.h);
	int nx=1,ny=0;
	for (int i=1; i<=a.T; i++)  (ny+=nx)%=m,nx=1LL*nx*b.x%m;
	ny=1LL*ny*b.y%m;
	b.x=nx,b.y=ny;
	b.solve();
	if (b.tag==0)  return (void)printf("-1");
	printf("%lld",a.t+1LL*a.T*b.t);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
