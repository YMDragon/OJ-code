#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int n,q;
char ch[100010];
vector <int> V[26];

void work()
{
	scanf("%d %d\n",&n,&q);
	scanf("%s",ch+1);
	for (int i=1; i<=n; i++)
		V[ch[i]-'a'].push_back(i);
	for (int i=1,l,r,k,x; i<=q; i++)
		{
			scanf("%d %d %d",&l,&r,&k);
			if (k==1)
				{
					x=l;
					for (int j=0; j<26; j++)
						{
							int st=lower_bound(V[j].begin(),V[j].end(),l)-V[j].begin();
							int en=upper_bound(V[j].begin(),V[j].end(),r)-V[j].begin();
							for (; st<en; st++)
								V[j][st]=x++;
						}
				}
			else
				{
					x=l;
					for (int j=25; j>=0; j--)
						{
							int st=lower_bound(V[j].begin(),V[j].end(),l)-V[j].begin();
							int en=upper_bound(V[j].begin(),V[j].end(),r)-V[j].begin();
							for (; st<en; st++)
								V[j][st]=x++;
						}
				}
		}
	for (int i=0; i<26; i++)
		for (int j=0; j<V[i].size(); j++)
			ch[V[i][j]]=i+'a';
	printf("%s",ch+1);
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
