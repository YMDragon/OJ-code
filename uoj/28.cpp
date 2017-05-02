#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int p[100001],q[100001];

int findSample(int n,int confidence[],int host[],int protocol[])
{
	for (int i=0; i<n; i++)  p[i]=confidence[i],q[i]=0;
	for (int i=n-1; i>0; i--)
		{
			if (protocol[i]==0)
				{
					p[host[i]]+=q[i];
					q[host[i]]+=max(p[i],q[i]);
				}
			if (protocol[i]==1)
				{
					p[host[i]]=max(p[host[i]]+max(p[i],q[i]),q[host[i]]+p[i]);
					q[host[i]]+=q[i];
				}
			if (protocol[i]==2)
				{
					p[host[i]]=max(p[host[i]]+q[i],q[host[i]]+p[i]);
					q[host[i]]+=q[i];
				}
		}
	return max(p[0],q[0]);
}

