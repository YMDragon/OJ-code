#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
typedef int  ARR[4];
struct matrix{
	ARR a[4];
	ARR& operator [] (int x){return a[x];}
}I,Zero;
LL n;
int mo,ans[7];

matrix operator * (matrix x,matrix y)
{
	matrix z=Zero;
	for (int i=1; i<=3; i++)
		for (int j=1; j<=3; j++)
			for (int k=1; k<=3; k++)
				(z[i][j]+=1LL*x[i][k]*y[k][j]%mo)%=mo;
	return z;
}

matrix ksm(matrix a,LL b)
{
	matrix x=a;  a=I;
	while (b)
		{
			if (b&1)  a=a*x;
			x=x*x,b>>=1;
		}
	return a;
}

void work()
{
	cin>>n>>mo;
	ans[3]=1;
	I[1][1]=I[2][2]=I[3][3]=1;
	for (LL x=1; x<=n; x*=10)
		{
			matrix res=Zero;
			res[1][1]=x*10%mo,res[2][1]=res[2][2]=res[3][1]=res[3][2]=res[3][3]=1;
			if (x*10<=n)  res=ksm(res,x*9);
			else  res=ksm(res,n-x+1);
			ans[4]=ans[5]=ans[6]=0;
			for (int j=1; j<=3; j++)
				for (int k=1; k<=3; k++)
					(ans[j+3]+=1LL*ans[k]*res[k][j]%mo)%=mo;
			ans[1]=ans[4],ans[2]=ans[5],ans[3]=ans[6];
		}
	printf("%d",ans[1]);
}

int main()
{
	freopen("2326.in","r",stdin);
	freopen("2326.out","w",stdout);
	work();
	return 0;
}
