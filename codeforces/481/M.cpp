#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <deque>
using namespace std;

struct node{int ch,r,c,deep,n;}a[10000];
int n,m,h[30],tot,deep;
deque <node> Q;
string S;

void work()
{
	scanf("%d\n",&n);
	for (int i=1; i<=n; i++)
		{
			getline(cin,S),m=S.size();
			for (int j=1; j<=m; j++)
				{
					if (S[j-1]=='{')  deep++;
					if (S[j-1]=='}')
						{
							node x;
							while ((!Q.empty())&&((x=Q.back()).deep==deep))
								h[x.ch]=x.n,Q.pop_back();
							deep--;
						}
					if (('a'<=S[j-1])&&(S[j-1]<='z'))
						{
							int t=S[j-1]-'a';
							a[++tot]=(node){t,i,j,deep,h[t]};
							Q.push_back(a[tot]);
							if (h[t])
								printf("%d:%d: warning: shadowed declaration of %c, the shadowed position is %d:%d\n",i,j,S[j-1],a[h[t]].r,a[h[t]].c);
							h[t]=tot;
						}
				}
		}
}

int main()
{
	freopen("M.in","r",stdin);
	freopen("M.out","w",stdout);
	work();
	return 0;
}
