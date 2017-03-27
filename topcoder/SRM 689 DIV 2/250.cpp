#include <bits/stdc++.h>
using namespace std;

class SimilarUserDetection{
public:
	string haveSimilar(vector <string> handles)
	{
		for (int i=0; i<handles.size(); i++)
			for (int j=0; j<handles[i].size(); j++)
				if (handles[i][j]=='0')  handles[i][j]='O';
				else  if ((handles[i][j]=='l')||(handles[i][j]=='I'))
					handles[i][j]='1';
		for (int i=0; i<handles.size(); i++)
			for (int j=i+1; j<handles.size(); j++)
				if (handles[i]==handles[j])
					return "Similar handles found";
		return "Similar handles not found";
	}
}Main;

int main()
{
	freopen("250.in","r",stdin);
	freopen("250.out","w",stdout);
	string x;  vector <string> a;
	while (cin>>x)  a.push_back(x);
	cout<<Main.haveSimilar(a);
	return 0;
}
