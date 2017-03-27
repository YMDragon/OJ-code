#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct Splay{
	struct node{int k,s,ch[2],f;}t[2100000];
	int tot,root,k;

	void rotate(int x)
	{
		int f=t[x].f,ff=t[f].f,q=(t[f].ch[1]==x),ch=t[x].ch[q^1];
		if (ff)  t[ff].ch[(t[ff].ch[1]==f)]=x,t[x].f=ff;  else  root=x,t[x].f=0;
		t[f].ch[q]=ch;if (ch)  t[ch].f=f;
		t[x].ch[q^1]=f,t[f].f=x;
		t[x].s=t[f].s,t[f].s=t[t[f].ch[0]].s+t[t[f].ch[1]].s+1;
	}

	void splay(int x){while (t[x].f)  rotate(x);}
	void move(int x){k=x;}
	void prev(){k--;}
	void next(){k++;}
	void updata(int n){t[n].s=t[t[n].ch[0]].s+t[t[n].ch[1]].s+(n!=0);}

	int rank(int k)
	{
		int n=root;
		while (n)
			{
				if (t[t[n].ch[0]].s+1==k)  break;
				if (t[t[n].ch[0]].s>=k)  n=t[n].ch[0];
				else  k-=t[t[n].ch[0]].s+1,n=t[n].ch[1];
			}
		return n;
	}

	int dfs_build(int l,int r)
	{
		int n=++tot,mid=(l+r)>>1;
		if (l<mid)
			{
				t[n].ch[0]=dfs_build(l,mid-1);
				t[n].s+=t[t[n].ch[0]].s;
				t[t[n].ch[0]].f=n;
			}
		while ((t[n].k=getchar()))  if ((32<=t[n].k)&&(t[n].k<=126))  break;
		t[n].s++;
		if (mid<r)
			{
				t[n].ch[1]=dfs_build(mid+1,r);
				t[n].s+=t[t[n].ch[1]].s;
				t[t[n].ch[1]].f=n;
			}
		return n;
	}

	void insert(int n)
	{
		int l=rank(k),r=rank(k+1),rot=dfs_build(1,n);
		splay(l),splay(r);
		if (l)  t[l].ch[1]=rot,t[rot].f=l;
		else  if (r)  t[r].ch[0]=rot,t[rot].f=r;
		else  root=rot;
		updata(l),updata(r);
	}

	void del(int n)
	{
		int l=rank(k),r=rank(k+n+1);
		splay(l),splay(r);
		if (l)  t[l].ch[1]=0;
		else  if (r)  t[r].ch[0]=0;
		else  root=0;
		updata(l),updata(r);
	}

	void dfs_print(int n)
	{
		if (!n)  return;
		dfs_print(t[n].ch[0]);
		printf("%c",t[n].k);
		dfs_print(t[n].ch[1]);
	}

	void get(int n)
	{
		int l=rank(k),r=rank(k+n+1);
		splay(l),splay(r);
		if (l)  dfs_print(t[l].ch[1]);
		else  if (r)  dfs_print(t[r].ch[0]);
		else  dfs_print(root);
		printf("\n");
	}
}Splay;

void work()
{
	int m,n;  char ch[6];
	scanf("%d",&m);
	for (int i=1; i<=m; i++)
		{
			scanf("%s",ch);
			switch (ch[0])
				{
				case 'M':{scanf("%d",&n);  Splay.move(n);  break;}
				case 'I':{scanf("%d",&n);  Splay.insert(n);  break;}
				case 'D':{scanf("%d",&n);  Splay.del(n);  break;}
				case 'G':{scanf("%d",&n);  Splay.get(n);  break;}
				case 'P':{Splay.prev();  break;}
				case 'N':{Splay.next();  break;}
				}
		}
}

int main()
{
	freopen("1507.in","r",stdin);
	freopen("1507.out","w",stdout);
	work();
	return 0;
} 
