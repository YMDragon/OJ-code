#include <bits/stdc++.h>
using namespace std;

class WaterTank{
	bool check(vector <int> t,vector <int> x,int C,double mid)
	{
		double rest=0;
		int ti,xi;
		for (int i=0; i<t.size(); i++)
			{
				ti=t[i],xi=x[i];
				rest=max(0.0,rest+(x[i]-mid)*t[i]);
				if (rest>C)  return 0;
			}
		return 1;
	}

public:
	double minOutputRate(vector <int> t,vector <int> x,int C)
	{
		double l=0,r=1000000,mid;
		for (int i=0; r-l>1e-7; check(t,x,C,mid=(l+r)/2)?r=mid:l=mid)
			i++;
		return l;
	}
}Main;

int main()
{
	freopen("250.in","r",stdin);
	freopen("250.out","w",stdout);
	vector <int> t,x;  int C,tmp;  char ch;
	do  scanf("%d%c",&tmp,&ch),t.push_back(tmp);  while (ch!='\n');
	do  scanf("%d%c",&tmp,&ch),x.push_back(tmp);  while (ch!='\n');
	scanf("%d",&C);
	printf("%.10lf",Main.minOutputRate(t,x,C));
	return 0;
}
