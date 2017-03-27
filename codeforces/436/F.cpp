#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
const int size=300;
struct node{int a,b;}a[100010];
struct Node{LL a[size+10];int tag,b[size+10],maxa;}b[400];
int n,w,maxa;
LL c[size+10];

bool cmp(node x,node y){return x.b<y.b;}

void modify(int p)
{
	for (int i=1,j=1; i<=p; i+=size,j++)
		if (i+size-1<=p)
			{
				Node &x=b[j];
				x.tag++;
				int X=x.b[x.b[0]],Y=x.b[x.b[0]+1];
				if (x.a[X]+x.tag*X<x.a[Y]+x.tag*Y)
					x.b[0]++,x.maxa=Y;
			}else
			{
				Node &x=b[j];
				if (x.tag)
					for (int k=1; k<=size; k++)
						x.a[k]+=1LL*(k+i-1)*x.tag;
				for (int k=1; k<=p-i+1; k++)
					x.a[k]+=k+i-1;
				x.tag=0;
				int &len=x.b[0];
				len=0;
				for (int k=1; k<=size; k++)
					{
						while ((len)&&(x.a[x.b[len]]+c[len]*x.b[len]<x.a[k]+c[len]*k))
							len--;
						x.b[++len]=k;
						if (len!=1)  c[len]=(x.a[x.b[len-1]]-x.a[k])/(k-x.b[len-1])+1;
					}
				x.b[len+1]=0,x.maxa=x.b[1],len=1;
			}
}

void getmax(LL &sum,int &p)
{
	sum=0,p=0;
	for (int i=1; i<=(maxa+size-1)/size; i++)
		{
			LL res=b[i].a[b[i].maxa]+1LL*b[i].tag*(b[i].maxa+(i-1)*size);
			if (res>sum)  sum=res,p=b[i].maxa+(i-1)*size;
		}
}

void work()
{
	scanf("%d %d",&n,&w);
	for (int i=1; i<=n; i++)
		scanf("%d %d",&a[i].a,&a[i].b),maxa=max(maxa,a[i].a);
	sort(a+1,a+n+1,cmp);
	for (int i=1,j=1; i<=maxa; i+=size,j++)
		b[j].maxa=1,b[j].b[0]=1,b[j].b[1]=1,b[j].b[2]=size;
	for (int i=0,j=1; i<=a[n].b+1; i++)
		{
			while ((j<=n)&&(a[j].b<i))  modify(a[j].a),j++;
			LL sum;  int p;
			getmax(sum,p);
			sum+=1LL*(n-j+1)*i*w;
			printf("%lld %d\n",sum,p);
		}
}

int main()
{
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
	work();
	return 0;
}
