#include <bits/stdc++.h>
using namespace std;

class PalindromePath{
	int ans[20][20],mp[20][20];

	int solve(int n,int x,int y)
	{
		if (x==y)  return 0;
		if (ans[x][y])  return ans[x][y];
		ans[x][y]=1<<30;
		for (int i=0; i<n; i++)
			if (mp[x][i])
				for (int j=0; j<n; j++)
					if (mp[x][i]==mp[y][j])
						ans[x][y]=min(ans[x][y],solve(n,i,j)+2);
		return ans[x][y];
	}

public:
	int shortestLength(int n,vector <int> a,vector <int> b,string c)
	{
		for (int i=0; i<a.size(); i++)
			{
				mp[a[i]][b[i]]=mp[b[i]][a[i]]=c[i]-'a'+1;
				ans[a[i]][b[i]]=ans[b[i]][a[i]]=1;
			}
		solve(n,0,1);
		return ans[0][1]==(1<<30)?-1:ans[0][1];
	}
}Main;

int main()
{
	freopen("900.in","r",stdin);
	freopen("900.out","w",stdout);
	int n,x;  vector <int> a,b;  string c;  char ch;
	scanf("%d",&n);
	while (scanf("%d%c",&x,&ch))  {a.push_back(x);  if (ch=='\n')  break;}
	while (scanf("%d%c",&x,&ch))  {b.push_back(x);  if (ch=='\n')  break;}
	cin>>c;
	printf("%d",Main.shortestLength(n,a,b,c));
	return 0;
}
