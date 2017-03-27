#include <bits/stdc++.h>
using namespace std;

typedef long long  LL;
const int mo=int(1e9+7);
struct matrix{int a[7][7];}a;
int ans;
LL n;

matrix operator * (matrix x,matrix y)
{
	matrix z;
	memset(z.a,0,sizeof(z.a));
	for (int i=0; i<7; i++)
		for (int j=0; j<7; j++)
			for (int k=0; k<7; k++)
				(z.a[i][j]+=1LL*x.a[i][k]*y.a[k][j]%mo)%=mo;
	return z;
}

matrix qpow(matrix a,LL b)
{
	matrix x=a;
	a=(matrix){{{1,0,0,0,0,0,0},
							{0,1,0,0,0,0,0},
							{0,0,1,0,0,0,0},
							{0,0,0,1,0,0,0},
							{0,0,0,0,1,0,0},
							{0,0,0,0,0,1,0},
							{0,0,0,0,0,0,1}}};
	while (b)
		{
			if (b&1)  a=a*x;
			x=x*x,b>>=1;
		}
	return a;
}

void work()
{
	cin>>n;
	a=(matrix){{{1,1,0,0,0,0,0},
							{0,0,1,0,0,0,0},
							{0,0,0,0,0,1,1},
							{1,1,0,0,0,0,0},
							{0,0,1,0,0,0,0},
							{0,0,0,1,1,0,0},
							{0,0,0,0,0,1,1}}};
	a=qpow(a,n);
	for (int i=0; i<7; i++)
		(ans+=a.a[6][i])%=mo;
	printf("%d",ans);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	work();
	return 0;
}
