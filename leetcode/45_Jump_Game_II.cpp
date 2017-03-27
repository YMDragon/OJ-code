class Solution
{
public:
	int jump(vector<int>& nums)
	{
		int n=nums.size(),a=-1,b=0,c=0,ans=0;
		while (b<n-1)
			{
				for (int i=a+1; i<=b; i++)  c=max(c,i+nums[i]);
				a=b,b=c,ans++;
			}
		return ans;
	}
};
