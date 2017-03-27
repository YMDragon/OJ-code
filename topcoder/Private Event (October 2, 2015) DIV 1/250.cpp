#include <bits/stdc++.h>
#define pb  push_back
using namespace std;

class EllysPrimesMatrix{
	int n,m,ans;

	int ksc(int a,int b,int mo)
	{
		return (a*b-(int)((long double)a/mo*b+1e-3)*mo+mo)%mo;
	}

	int ksm(int a,int b,int mo)
	{
		int x=a;  a=1;
		while (b)
			{
				if (b&1)  a=ksc(a,x,mo);
				x=ksc(x,x,mo),b>>=1;
			}
		return a;
	}

	bool miller_robin(int n)
	{
		if (n==2)  return 1;
		if ((n==1)||(!(n&1)))  return 0;
		int m=n-1,k=0;
		while (!(m&1))  m>>=1,k++;
		for (int i=1; i<=10; i++)
			{
				int x=ksm(rand()%(n-1)+1,m,n),y;
				for (int j=1; j<=k; j++)
					{
						y=ksc(x,x,n);
						if (y==1)  {if ((x!=1)&&(x!=n-1))  return 0;  else  break;}
						x=y;
					}
				if (y!=1)  return 0;
			}
		return 1;
	}


	void dfs(int x,int k,int s,vector <string> matrix)
	{
		if (x==-1)  {ans+=miller_robin(s);  return;}
		int a[10]={0,0,0,0,0,0,0,0,0,0};
		for (int i=0; i<m; i++)
			if (!a[matrix[x][i]-'0'])
				dfs(x-1,k*10,s+k*(matrix[x][i]-'0'),matrix),a[matrix[x][i]-'0']=1;
	}

public:
	int getCount(vector <string> matrix)
	{
		n=matrix.size(),m=matrix[0].length();
		dfs(n-1,1,0,matrix);
		return ans;
	}
}Main;

int main()
{
	freopen("250.in","r",stdin);
	freopen("250.out","w",stdout);
	string a;
	static vector <string> V;
	for (int i=0; i<7; i++)
		{
			a.clear(),cin>>a;
			if (a.length())  V.push_back(a);
			else  break;
		}
	printf("%d\n",Main.getCount(V));
	return 0;
}
