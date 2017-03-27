#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int n;
string S[10010];

bool cmp(string x,string y)
{
	if (x.length()!=y.length())  return x.length()<y.length();
	return x<y;
}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		cin>>S[i];
	sort(S+1,S+n+1,cmp);
	for (int i=1; i<=n; i++)
		cout<<S[i]<<endl;
}

int main()
{
	freopen("9.in","r",stdin);
	freopen("9.out","w",stdout);
	work();
	return 0;
}
