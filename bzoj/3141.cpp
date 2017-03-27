#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#define mp  make_pair
using namespace std;

typedef pair<int,int>  PII;
struct node{int l,r,x;}Node[1000010];
int n,m,k,cnt,tot,a[500010],s[500010];

struct Deque{
	int st,en,len;

	int back(){return Node[en].x;}
	bool empty(){return !len;}
	int front(){return Node[st].x;}
	int size(){return len;}
	void pop_front(){st=Node[st].r,len--;}
	void pop_back(){en=Node[en].l,len--;}

	void push_back(int x)
	{
		if (len)  Node[++tot]=(node){en,0,x},Node[en].r=tot,en=tot;
		else  Node[++tot]=(node){0,0,x},st=en=tot;
		len++;
	}
}Q[1000010],q[1000010];

void pi(int x)
{
	if (x>9)  pi(x/10);  putchar(x%10+'0');
}

int gi()
{
	int w=0;  char ch=getchar();
	while ((ch<'0')||('9'<ch))  ch=getchar();
	while (('0'<=ch)&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return w;
}

void work()
{
	n=gi(),m=gi();
	for (int i=1; i<=n; i++)
		{
			a[i]=gi(),s[i]=gi();
			if (s[i]==0)  s[i]=-1;
			s[i]+=s[i-1],cnt+=(s[i]==0);
		}
	k=s[n]?(fabs(s[n])+m-1)/m:cnt<m;
	if (k==0)
		{
			for (int i=1; i<n; i++)  if (!s[i])  q[0].push_back(i);
			for (int i=1,lans=0; i<m; i++)
				{
					while (q[0].size()>=m-i)
						{
							while ((!Q[0].empty())&&(a[Q[0].back()]>a[q[0].front()]))
								Q[0].pop_back();
							Q[0].push_back(q[0].front()),q[0].pop_front();
						}
					while (Q[0].front()<=lans)  Q[0].pop_front();
					pi(a[Q[0].front()]),putchar(' '),Q[0].pop_front();
				}
		}else
		{
			for (int i=1; i<n; i++)
				q[s[i]+n].push_back(i);
			for (int i=1,lans=0,ans; ans=0,i<m; i++)
				{
					for (int j=n+s[lans]-k; j<=n+s[lans]+k; j++)
						{
							if (fabs(j-n-s[n])>(m-i)*k)  continue;
							while ((!q[j].empty())&&(n-q[j].front()>=m-i))
								{
									if (q[j].front()>lans)
										{
											while ((!Q[j].empty())&&(a[Q[j].back()]>a[q[j].front()]))
												Q[j].pop_back();
											Q[j].push_back(q[j].front());
										}
									q[j].pop_front();
								}
							while ((!Q[j].empty())&&(Q[j].front()<=lans))  Q[j].pop_front();
							if ((!Q[j].empty())&&((!ans)||(a[Q[j].front()]<a[ans])))
								ans=Q[j].front();
						}
					pi(a[ans]),putchar(' '),lans=ans;
				}
		}
	pi(a[n]);
}

int main()
{
	freopen("3141.in","r",stdin);
	freopen("3141.out","w",stdout);
	work();
	return 0;
}
