#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int mo=1e9+9,P=400000004,Q=666666671;
int n,m,ans;

int ksm(int a,int b)
{
	int x=a;  a=1;
	while (b)
		{
			if (b&1)  a=1LL*a*x%mo;
			x=1LL*x*x%mo,b>>=1;
		}
	return a;
}

int getsum(int t,int l,int r){return 1LL*(ksm(P,r)-ksm(P,l-1)+mo)*Q%mo*t%mo;}

struct Splay{
	struct node{int t,ss,sum,s,l,r,f,ch[2];}t[300010];
	int root,cnt;

	void update(int x)
	{
		t[x].s=t[t[x].ch[0]].s+t[t[x].ch[1]].s+1;
		t[x].sum=(0LL+t[t[x].ch[0]].sum+t[t[x].ch[1]].sum+t[x].ss)%mo;
	}
	
	void rotate(int x)
	{
		int f=t[x].f,ff=t[f].f,q=(t[f].ch[1]==x),ch=t[x].ch[q^1];
		if (ff)  t[ff].ch[t[ff].ch[1]==f]=x;  else  root=x;  t[x].f=ff;
		t[f].ch[q]=ch,t[ch].f=f;
		t[x].ch[q^1]=f,t[f].f=x;
		update(f),update(x);
	}

	void splay(int x){if (!x)  return;  while (t[x].f)  rotate(x);}

	int lower_bound(int x)
	{
		int n=root,res=0;
		while (n)
			{
				if ((t[n].l<x)&&(x<=t[n].r))  return n;
				if (t[n].l<x)  res=t[n].l>t[res].l?n:res,n=t[n].ch[1];
				else  n=t[n].ch[0];
			}
		return res;
	}

	int upper_bound(int x)
	{
		int n=root,res=0;
		while (n)
			{
				if ((t[n].l<=x)&&(x<t[n].r))  return n;
				if (t[n].r>x)  res=t[n].r<t[res].r?n:res,n=t[n].ch[0];
				else  n=t[n].ch[1];
			}
		return res;
	}
	
	int ask(int l,int r)
	{
		int ll=lower_bound(l),rr=upper_bound(r),res=0;
		if ((ll==rr)&&(ll))  return getsum(t[ll].t,l-t[ll].l+1,r-t[ll].l+1);
		splay(ll),splay(rr);
		if (ll)  res=t[t[ll].ch[1]].sum;
		else  if (rr)  res=t[t[rr].ch[0]].sum;
		else  res=t[root].sum;
		if (ll)  (res+=getsum(t[ll].t,l-t[ll].l+1,t[ll].r-t[ll].l+1))%=mo;
		if (rr)  (res+=getsum(t[rr].t,1,r-t[rr].l+1))%=mo;
		return res;
	}

	void modify(int l,int r,int st)
	{
		int ll=lower_bound(l),rr=upper_bound(r),n=++cnt;
		t[n]=(node){st,getsum(st,1,r-l+1),0,1,l,r,0,{0,0}};
		if (ll==rr)
			{
				splay(ll);
				if (ll)
					{
						t[++cnt]=(node){t[ll].t,getsum(t[ll].t,1,l-t[ll].l),0,1,t[ll].l,l-1,n,{t[ll].ch[0],0}};
						t[t[cnt].ch[0]].f=cnt,t[n].ch[0]=cnt;
						update(cnt);
						t[++cnt]=(node){int(1LL*t[rr].t*ksm(P,r-t[rr].l+1)%mo),getsum(t[ll].t,r-t[rr].l+2,t[rr].r-t[rr].l+1),0,1,r+1,t[rr].r,n,{0,t[rr].ch[1]}};
						t[t[cnt].ch[1]].f=cnt,t[n].ch[1]=cnt;
						update(cnt);
					}else
					{
						t[n].ch[0]=t[ll].ch[0],t[t[ll].ch[0]].f=n;
						t[n].ch[1]=t[rr].ch[1],t[t[rr].ch[1]].f=n;
					}
				update(n),root=n;
				return;
			}
		splay(ll),splay(rr);
		if (ll)  t[ll].ch[1]=0;
		if (rr)  t[rr].ch[0]=0;
		root=0;
		if (ll)
			{
				t[ll].r=l-1,t[ll].ss=getsum(t[ll].t,1,t[ll].r-t[ll].l+1),t[ll].f=n;
				t[n].ch[0]=ll,update(ll);
			}
		if (rr)
			{
				t[rr].t=1LL*t[rr].t*ksm(P,r-t[rr].l+1)%mo,t[rr].l=r+1,t[rr].ss=getsum(t[rr].t,1,t[rr].r-t[rr].l+1),t[rr].f=n;
				t[n].ch[1]=rr,update(rr);
			}
		update(n),root=n;
	}
}T;

void work()
{
	scanf("%d %d",&n,&m);
	T.t[0].l=0,T.t[0].r=n+1;
	T.modify(1,n,0);
	for (int i=1,ty,l,r,t,p; i<=m; i++)
		{
			scanf("%d %d %d",&ty,&l,&r),l^=ans,r^=ans;
			if (ty==1)
				{
					scanf("%d %d",&t,&p);
					T.modify(l,r,1LL*t*ksm(P,p)%mo);
				}else
				{
					ans=T.ask(l,r);
					printf("%d\n",ans);
				}
		}
}

int main()
{
	freopen("95.in","r",stdin);
	freopen("95.out","w",stdout);
	work();
	return 0;
}
