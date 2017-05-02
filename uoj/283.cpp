#include <bits/stdc++.h>
using namespace std;

int n,m,tot,ans,ansk;

void work()
{
	scanf("%d %d",&n,&m);
	if (n==1)  {return;}
	if (n==2)  {printf("1 2\n");  return;}
	if (n==3)  {printf("1 2\n1 3\n");  return;}
	for (int k=2; k*k<=n+1; k++)
		if (n*k-(4*k*k*k-3*k*k-k)/6>ans)
			ans=n*k-(4*k*k*k-3*k*k-k)/6,ansk=k;
	for (int i=ansk,x=0; i>1; i--)
		{
			tot++;
			for (int j=2; j<2*i; j++)
				tot++,printf("%d %d\n",tot-1,tot);
			if (x)  printf("%d %d\n",tot-i+1,x);
			x=tot-i+1;
		}
	for (int i=tot+1; i<=n; i++)  printf("%d %d\n",tot-1,i);
	fprintf(stderr,"%d\n",ans);
}

int main()
{
	freopen("283.in","r",stdin);
	freopen("283.out","w",stdout);
	work();
	return 0;
}
