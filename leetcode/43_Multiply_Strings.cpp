class Solution
{
	const double pi=acos(-1);

	struct complex
	{
		double real,imag;
		complex operator + (complex x){return (complex){(*this).real+x.real,(*this).imag+x.imag};}
		complex operator - (complex x){return (complex){(*this).real-x.real,(*this).imag-x.imag};}
		complex operator * (complex x){return (complex){(*this).real*x.real-(*this).imag*x.imag,(*this).real*x.imag+(*this).imag*x.real};}
		complex operator / (double x){return (complex){(*this).real/x,(*this).imag/x};}
	};

	vector <complex> DFT(vector <complex> a,int op)
	{
		int n=a.size();
		for (int i=0; i<n; i++)
			{
				int t=i,p=0;
				for (int j=1; j<n; j<<=1)  p<<=1,p|=t&1,t>>=1;
				if (p<i)  swap(a[i],a[p]);
			}
		for (int len=2; len<=n; len<<=1)
			{
				complex w=(complex){cos(2*pi*op/len),sin(2*pi*op/len)};
				for (int i=0; i<n; i+=len)
					{
						complex W=(complex){1,0};
						for (int j=0; j<(len>>1); j++)
							{
								complex u=a[i+j],v=a[i+j+(len>>1)];
								a[i+j]=u+W*v,a[i+j+(len>>1)]=u-W*v,W=W*w;
							}
					}
			}
		if (op==-1)
			for (int i=0; i<n; i++)  a[i]=a[i]/n;
		return a;
	}

public:
	string multiply(string num1, string num2)
	{
		int n=1;  vector <int> res;  string ans;
		while (n<num1.size()+num2.size())  n<<=1;
		vector <complex> a(n),b(n),c(n);
		for (int i=0; i<num1.size(); i++)  a[num1.size()-i-1]=(complex){num1[i]-'0',0};
		for (int i=0; i<num2.size(); i++)  b[num2.size()-i-1]=(complex){num2[i]-'0',0};
		a=DFT(a,1),b=DFT(b,1);
		for (int i=0; i<n; i++)  c[i]=a[i]*b[i];
		c=DFT(c,-1);
		for (int i=0; i<n; i++)  res.push_back(int(c[i].real+0.5));
		res.push_back(0);
		for (int i=0; i<n; i++)  if (res[i]>9)  res[i+1]+=res[i]/10,res[i]%=10;
		while (res[n])  res.push_back(res[n]/10),res[n]%=10,n++;
		while ((n)&&(!res[n-1]))  n--;
		for (int i=n-1; i>=0; i--)  ans=ans+char(res[i]+'0');
		if (n==0)  ans=ans+'0';
		return ans;
	}
};
