#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

int n,a,b,c,ans;
multiset <int> S;

void erase(int x)
{
	multiset <int>::iterator t=S.upper_bound(x);
	if (t!=S.begin())  S.erase(--t);
}

int last(){multiset <int>::iterator x=S.end();  if (x!=S.begin())  x--;  return *x;}

void work()
{
	scanf("%d %d %d %d",&n,&a,&b,&c);
	cerr<<S.size()<<endl;
	for (int i=1,t; i<=n; i++)  scanf("%d",&t),S.insert(t);
	cerr<<S.size()<<endl;
	if (last()>a+b+c)  {printf("-1");  return;}
	if (a>b)  swap(a,b);
	if (b>c)  swap(b,c);
	if (a>b)  swap(a,b);
	while (last()>b+c)  erase(a+b+c),ans++;
	while (last()>a+c)
		erase(b+c),erase(a),ans++;
	while ((last()>a+b)&&(last()>c))  erase(a+c),erase(b),ans++;
	if (a+b>=c)  while (last()>c)  erase(a+b),erase(c),ans++;
	while ((S.size())&&((*S.begin())<=b))  erase(a),erase(b),erase(c),ans++;
	while (S.size())  erase(a+b),erase(c),ans++;
	printf("%d",ans);
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
