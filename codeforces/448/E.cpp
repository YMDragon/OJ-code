#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#define pb  push_back
using namespace std;

typedef long long  LL;

const int N=100000;
vector <LL> a;
vector <int> b[N+10];
LL x,k;

vector <int> f(int k)
{
	vector <int> res;
	if (k==0)  res.pb(int(a.size()-1));
	else  if (k&1)
		{
			vector <int> X=f(k-1);
			for (int i=0; i<X.size(); i++)
				for (int j=0; j<b[X[i]].size()&&res.size()<N; j++)
					res.pb(b[X[i]][j]);
		}else
		{
			vector <int> pos;
			vector <int> X=f(k/2);
			for (int i=0,j=0; i<X.size(); i++)  if (X[i]==j)  pos.pb(i),j++;
			for (int i=0; i<X.size(); i++)
				for (int j=0; j<b[X[i]].size()&&res.size()<N; j++)
					{
						int y=b[X[i]][j],l=y?pos[y-1]+1:0,r=pos[y];
						for (int k=l; k<=r&&res.size()<N; k++)  res.pb(X[k]);
					}
	}
	return res;
}

void work()
{
	scanf("%lld %lld",&x,&k),k=min(k,1LL*N);
	for (LL i=1; i*i<=x; i++)
		if (x%i==0)
			{
				a.pb(i);
				if (i*i!=x)  a.pb(x/i);
			}
	sort(a.begin(),a.end());
	for (int i=0; i<a.size(); i++)
		for (int j=0; j<=i; j++)
			if (a[i]%a[j]==0)  b[i].pb(j);
	vector <int> X=f(k);
	for (int i=0; i<X.size(); i++)  printf("%lld ",a[X[i]]);
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
