#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

char ch[100010];
int n,ans;

void work()
{
	scanf("%s",ch+1),n=strlen(ch+1);
	for (int i=1,t=0; i<n; i++)
		if ((ch[i]=='A')&&(ch[i+1]=='B')&&(!t))  t=1,i++;
		else  if ((ch[i]=='B')&&(ch[i+1]=='A')&&(t))  ans=1;
	for (int i=1,t=0; i<n; i++)
		if ((ch[i]=='B')&&(ch[i+1]=='A')&&(!t))  t=1,i++;
		else  if ((ch[i]=='A')&&(ch[i+1]=='B')&&(t))  ans=1;
	if (ans)  printf("YES");  else  printf("NO");
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	work();
	return 0;
} 
