#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#define mk  make_pair
using namespace std;

typedef long long  LL;
typedef pair<int,int>  PII;
struct node{int t,s,p,id;LL ti;}a[300010],b[300010];
LL n,T,Ti,X,ans[300010];
priority_queue <PII> Q1,Q2;

bool cmpt(node x,node y){return x.t<y.t;}
bool cmpp(node x,node y){return x.p<y.p;}

LL getint()
{
	int w=0,q=1;  char ch=getchar();
	while (((ch<'0')||(ch>'9'))&&(ch!='-'))  ch=getchar();
	if (ch=='-')  q=0,ch=getchar();
	while ((ch>='0')&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return q?w:-w;
}

void putLL(LL x){if (x>9)  putLL(x/10);  putchar(x%10+'0');}

void prepare()
{
	LL t=-1,i=1,x;  int q;
	while (t<T)
		{
			while ((i<=n)&&(t+1==a[i].t))  Q2.push(mk(b[i].p,i)),i++;
			if (i<=n)  q=b[i].t-t-1;  else  q=1<<30;
			if (!Q2.empty())
				{
					q=min(q,b[x=(Q2.top().second)].s),b[x].s-=q;
					if (b[x].s==0)  Q2.pop();
					b[x].ti+=max(0LL,min(T,t+q)-max(Ti,t+1)+1);
				}
			t+=q;
		}
}

void getft()
{
	LL t=-1,i=1,x;  int q;
	while ((i<=n)||(!Q1.empty()))
		{
			while ((i<=n)&&(t+1==a[i].t))  Q1.push(mk(a[i].p,i)),i++;
			if (i<=n)  q=a[i].t-t-1;  else  q=1<<30;
			if (!Q1.empty())
				{
					q=min(q,a[x=(Q1.top().second)].s),a[x].s-=q;
					if (a[x].s==0)  Q1.pop(),ans[a[x].id]=t+q;
				}
			t+=q;
		}
}

void work()
{
	n=getint();
	for (int i=1; i<=n; i++)
		a[i].t=getint(),a[i].s=getint(),a[i].p=getint(),a[i].id=i;
	scanf("%lld",&T),T--;
	sort(a+1,a+n+1,cmpt);
	for (int i=1; i<=n; i++)
		{
			b[i]=a[i];
			if (a[i].p==-1)  Ti=a[i].t,X=i,a[i].p=b[i].p=0;
		}
	prepare();
	sort(b+1,b+n+1,cmpp);
	for (int i=1; i<=n; i++)
		{
			b[1].ti+=(i==1)?0:b[i].ti;
			if ((b[1].ti==a[X].s)&&(b[i].p+1!=b[i+1].p))
				{a[X].p=b[i].p+1;  break;}
		}
	putLL(a[X].p),putchar('\n');
	getft();
	for (int i=1; i<=n; i++)  putLL(ans[i]+1),putchar(' ');
}

int main()
{
	freopen("10.in","r",stdin);
	freopen("10.out","w",stdout);
	work();
	return 0;
}
