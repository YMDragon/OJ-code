#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
#define mp  make_pair
using namespace std;

typedef long long  LL;
typedef pair <int,LL>  PIL;
typedef set <PIL>::iterator  Iter;
int n,q;
set <PIL> S;

Iter pre(Iter x){x--;  return x;}

void work()
{
	scanf("%d %d",&n,&q);
	S.insert(mp(0,1LL<<45)),S.insert(mp(1,0)),S.insert(mp(n+1,-1));
	for (int i=1,a,l; i<=q; i++)
		{
			LL b;
			scanf("%d %lld",&a,&b),a++;
			Iter x=pre(S.upper_bound(mp(a,1LL<<60))),y;
			x=(S.insert(mp(a,(*x).second))).first;
			while (b>0)
				{
					y=pre(x),l=a-(*y).first;
					if (((*pre(y)).second-(*y).second)*l>=b)
						{
							if (b%l)  S.insert(mp((*y).first+b%l,(*y).second+b/l));
							S.erase(y),y=S.insert(mp((*y).first,(*y).second+(b+l-1)/l)).first;
							if ((*pre(y)).second==(*y).second)  S.erase(y);
							b=0;
						}else  b-=((*pre(y)).second-(*y).second)*l,S.erase(y);
				}
			if ((*pre(x)).second==(*x).second)  S.erase(x);
		}
	for (Iter x=S.begin(),y; x!=S.end(); y=x,x++)
		if ((*x).first>1)
			for (int i=(*y).first; i<(*x).first; i++)
				printf("%lld\n",(*y).second);
}

int main()
{
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
	work();
	return 0;
}
