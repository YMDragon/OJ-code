#include <bits/stdc++.h>
using namespace std;

long double pi=acos(-1);
int n,A,B,k;
long double a,b,t,phi,ans;

long double solve(long double Sin,long double Cos)
{
	long double t=acos(Cos);
	if (Sin<0)  t+=pi;
	return t;
}

int up(long double x){return int(x)+(int(x)!=x);}

void work()
{
	scanf("%d %d %d",&A,&B,&n);
	for (int i=1; i<=10000; i++)
		{
			long double Sin=sin(i),Cos=cos(i);
			a+=A*Cos/(i+Sin)-B*Sin/(i+Cos);
			b+=A*Sin/(i+Sin)+B*Cos/(i+Cos);
		}
	t=sqrt(a*a+b*b);
	phi=acos(a/t);
	if (b<0)  phi=pi-phi;
	k=up(phi/pi);
	ans=1LL*(2*k+n-1)*n/2*pi-n*phi;
	printf("%.3lf",double(ans));
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	work();
	return 0;
}
