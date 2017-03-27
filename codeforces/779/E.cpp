#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
using namespace std;

struct node{string a,b,c;int ty;}a[5010];
int n,m,s0[1010],s1[1010];
map <string,int> M;
map <string,string> M0,M1;
string s,s2;
char ch;

string And(string a,string b)
{
	for (int i=0; i<m; i++)
		if ((a[i]=='1')&&(b[i]=='1'))  a[i]='1';
		else  a[i]='0';
	return a;
}

string Or(string a,string b)
{
	for (int i=0; i<m; i++)
		if ((a[i]=='1')||(b[i]=='1'))  a[i]='1';
		else  a[i]='0';
	return a;
}

string Xor(string a,string b)
{
	for (int i=0; i<m; i++)
		if (a[i]==b[i])  a[i]='0';
		else  a[i]='1';
	return a;
}

void work()
{
	scanf("%d %d\n",&n,&m);
	for (int i=1; i<=n; i++)
		{
			cin>>a[i].a;
			cin>>s;
			s.clear(),ch=getchar();
			while (ch==' ')  ch=getchar();
			while (ch!='\n')  s+=ch,ch=getchar();
			if ((s[0]=='0')||(s[0]=='1'))
				{
					a[i].b=s,a[i].ty=0;
				}else
				{
					int j,t;
					for (j=0; j<s.length(); j++)
						{
							if (s[j]==' ')  break;
							a[i].b+=s[j];
						}
					if (s[j+1]=='A')  a[i].ty=1;
					else  if (s[j+1]=='O')  a[i].ty=2;
					else  a[i].ty=3;
					for (j++,t=0; j<s.length(); j++)
						if (t)  a[i].c+=s[j];
						else  if (s[j]==' ')  t=1;
				}
		}
	s.clear(),s+='?',s2.clear();
	for (int i=0; i<m; i++)  s2+='0';
	M0[s]=s2;
	for (int i=0; i<m; i++)  s2[i]='1';
	M1[s]=s2;
	for (int i=1; i<=n; i++)
		{
			if (a[i].ty==0)
				{
					M0[a[i].a]=a[i].b;
					M1[a[i].a]=a[i].b;
				}
			if (a[i].ty==1)  
				{
					M0[a[i].a]=And(M0[a[i].b],M0[a[i].c]);
					M1[a[i].a]=And(M1[a[i].b],M1[a[i].c]);
				}
			if (a[i].ty==2)  
				{
					M0[a[i].a]=Or(M0[a[i].b],M0[a[i].c]);
					M1[a[i].a]=Or(M1[a[i].b],M1[a[i].c]);
				}
			if (a[i].ty==3)  
				{
					M0[a[i].a]=Xor(M0[a[i].b],M0[a[i].c]);
					M1[a[i].a]=Xor(M1[a[i].b],M1[a[i].c]);
				}
		}
	for (map <string,string>::iterator x=M0.begin(); x!=M0.end(); x++)
		if ((*x).first[0]!='?')
			for (int i=0; i<m; i++)
				if ((*x).second[i]=='1')
					s0[i]++;
	for (map <string,string>::iterator x=M1.begin(); x!=M1.end(); x++)
		if ((*x).first[0]!='?')
			for (int i=0; i<m; i++)
				if ((*x).second[i]=='1')
					s1[i]++;
	for (int i=0; i<m; i++)
		if (s0[i]<=s1[i])  putchar('0');
		else  putchar('1');
	puts("");
	for (int i=0; i<m; i++)
		if (s0[i]>=s1[i])  putchar('0');
		else  putchar('1');
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	work();
	return 0;
}
