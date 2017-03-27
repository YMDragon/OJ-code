#include <bits/stdc++.h>
#define pb  push_back
using namespace std;

class BearSong{
	int n,a[1010],ans;
public:
	int countRareNotes(vector <int> notes)
	{
		n=notes.size();
		for (int i=0; i<n; i++)  a[notes[i]]++;
		for (int i=1; i<=1000; i++)  ans+=(a[i]==1);
		return ans;
	}
}Main;

int main()
{
	freopen("250.in","r",stdin);
	freopen("250.out","w",stdout);
	vector <int> notes;  int n;
	scanf("%d",&n);
	for (int i=1,x; i<=n; i++)  scanf("%d",&x),notes.pb(x);
	printf("%d",Main.countRareNotes(notes));
	return 0;
}
