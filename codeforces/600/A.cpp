#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

string ans[2];
int n;
char s[100010];

bool isanum(int l,int r)
{
	if (l>r)  return 0;
	for (int i=l; i<=r; i++)
		if ((s[i]<'0')||(s[i]>'9'))  return 0;
	if ((s[l]=='0')&&(l!=r))  return 0;
	return 1;
}

void work()
{
	scanf("%s",s+1),n=strlen(s+1);
	for (int i=1,j=1; i<=n+1; i++)
		if ((s[i]==';')||(s[i]==',')||(i>n))
			{
				int t=isanum(j,i-1);
				if (ans[t].size())  ans[t]+=',';  else  ans[t]+='"';
				for (int k=j; k<i; k++)
					ans[t]+=s[k];
				j=i+1;
			}
	if (ans[1].size())  cout<<ans[1]<<"\"\n";  else  cout<<"-\n";
	if (ans[0].size())  cout<<ans[0]<<"\"\n";  else  cout<<"-\n";
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
}
