#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define Ls(n)  (n<<1)
#define Rs(n)  (Ls(n)|1)
#define lowbit(x)  (x&-x)
#define mp  make_pair
#define pb  push_back
using namespace std;

class Cdgame{
	int suma,sumb;
	set <int> S;
public:
	int rescount(vector <int> a,vector <int> b)
	{
		for (int i=0; i<a.size(); i++)  suma+=a[i];
		for (int i=0; i<b.size(); i++)  sumb+=b[i];
		for (int i=0; i<a.size(); i++)
			for (int j=0; j<b.size(); j++)
				S.insert((a[i]-b[j])*(suma-sumb-a[i]+b[j]));
		return S.size();
	}
}Main;

int main()
{
	freopen("250.in","r",stdin);
	freopen("250.out","w",stdout);
	int n,m;
	vector <int> a,b;
	scanf("%d %d",&n,&m);
	for (int i=1,x; i<=n; i++)  scanf("%d",&x),a.pb(x);
	for (int i=1,x; i<=m; i++)  scanf("%d",&x),b.pb(x);
	printf("%d",Main.rescount(a,b));
	return 0;
}
