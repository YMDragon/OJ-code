#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include "gondola.h"
using namespace std;

typedef long long  LL;

int a[100001],b[250001];

int valid(int n, int inputSeq[])
{
	int frist=-1;
	for (int i=0; i<n; i++)
		if ((1<=inputSeq[i])&&(inputSeq[i]<=n))
			{
				if ((frist!=-1)&&((inputSeq[i]-i+n)%n!=frist))  return 0;
				else  frist=(inputSeq[i]-i+n)%n;
			}
	sort(inputSeq,inputSeq+n);
	for (int i=1; i<n; i++)
		if (inputSeq[i]==inputSeq[i-1])  return 0;
	return 1;
}

//----------------------

int replacement(int n, int gondolaSeq[], int replacementSeq[])
{
	int l=0,m=0,frist,t=0;
	for (int i=0; i<n; i++)  b[gondolaSeq[i]]=i+1;
	for (int i=0; i<n; i++)
		if ((1<=gondolaSeq[i])&&(gondolaSeq[i]<=n))
			{
				frist=(gondolaSeq[i]-i+n)%n;
				for (int j=0; j<n; j++)
					a[j]=frist,frist=frist%n+1;
				break;
			}
	if (a[0]==0)  for (int i=0; i<n; i++)  a[i]=i+1;
	for (int i=0; i<n; i++)
		if ((1<=gondolaSeq[i])&&(gondolaSeq[i]<=n))  m++;
		else  if (gondolaSeq[i]>gondolaSeq[t])  t=i;
	for (int i=n+1; m<n; i++)
		if (b[i])  replacementSeq[l++]=a[b[i]-1],m++;
		else  replacementSeq[l++]=a[t],a[t]=i;
	return l;
}

//----------------------

LL ksm(LL a,LL b,LL mo)
{
	LL x=a;a=1;
	while (b)
		{
			if (b&1)  a=a*x%mo;
			x=x*x%mo,b>>=1;
		}
	return a;
}

int countReplacement(int n, int inputSeq[])
{
	if (!valid(n,inputSeq))  return 0;
	LL ans=1,mo=1000000009,t=0;
	for (int i=0; i<n; i++)
		t+=(1<=inputSeq[i])&(inputSeq[i]<=n);
	for (int i=0; i<n; i++)
		if (inputSeq[i]>n)
			ans=ans*ksm(n-i,inputSeq[i]-(i?max(inputSeq[i-1],n):n)-1,mo)%mo;
	return t?ans:ans*n%mo;
}
