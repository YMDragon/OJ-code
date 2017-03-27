#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long  LL;
const int siz=300;
int n,q,a[100010],MIN[400][400],ST[100010][20],Log[100010],Stack[100010][2];
LL sum[400][101010];

int gi()
{
	int w=0,q=1;  char ch=getchar();
	while (((ch<'0')||('9'<ch))&&(ch!='-'))  ch=getchar();
	if (ch=='-')  q=0,ch=getchar();
	while (('0'<=ch)&&(ch<='9'))  w=w*10+ch-'0',ch=getchar();
	return q?w:-w;
}

void pi(LL x)
{
	if (x<0)  putchar('-'),x=-x;
	if (x>9)  pi(x/10);
	putchar(x%10+'0');
}

int mina(int x,int y){return (a[x]<a[y])?x:y;}

int getmin(int l,int r)
{
	int loglen=Log[r-l+1];
	return mina(ST[l][loglen],ST[r-(1<<loglen)+1][loglen]);
}

LL solve(int l,int r)
{
	if (l>r)  return 0;
	int mid=getmin(l,r);
	return 1LL*a[mid]*(mid-l+1)*(r-mid+1)+solve(l,mid-1)+solve(mid+1,r);
}

void work()
{
	n=gi(),q=gi();
	for (int i=1; i<=n; i++)  a[i]=gi();
	for (int i=1,x=1,top; i<=(n+siz-1)/siz; i++,x+=siz)
		{
			top=1,Stack[top][0]=a[i*siz],Stack[top][1]=1;
			LL S=a[i*siz];
			sum[i][i*siz]=S;
			for (int j=i*siz-1; j; j--)
				{
					Stack[top+1][1]=1;
					while ((top)&&(a[j]<=Stack[top][0]))
						{
							S-=1LL*Stack[top][0]*Stack[top][1];
							Stack[top][1]+=Stack[top+1][1],top--;
						}
					top++,Stack[top][0]=a[j],S+=1LL*Stack[top][0]*Stack[top][1];
					sum[i][j]=sum[i][j+1]+S;
				}
			sum[i][x+siz]=a[x];
			S=a[x],top=1,Stack[top][0]=a[x],Stack[top][1]=1;
			for (int j=x+1; j<=n; j++)
				{
					Stack[top+1][1]=1;
					while ((top)&&(a[j]<=Stack[top][0]))
						{
							S-=1LL*Stack[top][0]*Stack[top][1];
							Stack[top][1]+=Stack[top+1][1],top--;
						}
					top++,Stack[top][0]=a[j],S+=1LL*Stack[top][0]*Stack[top][1];
					sum[i][j+siz]=sum[i][j+siz-1]+S;
					if (j%siz==0)  MIN[i][j/siz]=Stack[1][0];
				}
		}
	Log[0]=-1;
	for (int i=1; i<=n; i++)  ST[i][0]=i,Log[i]=Log[i/2]+1;
	for (int j=1; j<20; j++)
		for (int i=1; i+(1<<(j-1))<=n; i++)
			ST[i][j]=mina(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
	for (int i=1,l,r,L,R; i<=q; i++)
		{
			l=gi(),r=gi(),L=1,R=0;
			while ((L-1)*siz+1<l)  L++;
			while ((R+1)*siz<=r)  R++;
			if (L>R)
				pi(solve(l,r)),putchar('\n');
			else
				{
					LL ans=sum[L][r+siz]+sum[R][l]-sum[L][R*siz+siz];
					int Min=MIN[L][R];
					for (int j=(L-1)*siz,k=R*siz+1; j>=l||k<=r; )
						if ((k>r)||((j>=l)&&(a[j]>a[k])))
							Min=min(Min,a[j]),ans+=1LL*(k-R*siz-1)*Min,j--;
						else  Min=min(Min,a[k]),ans+=1LL*((L-1)*siz-j)*Min,k++;
					pi(ans),putchar('\n');
				}
		}
}

int main()
{
	freopen("4540.in","r",stdin);
	freopen("4540.out","w",stdout);
	work();
	return 0;
}
