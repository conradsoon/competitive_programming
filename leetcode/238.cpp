class Solution
{
public:
	vector<int> productExceptSelf(vector<int> &nums)
	{
		int n = size(nums);
		vector<int> ans(n, 1);
		int pf = 1;
		for (int i = n - 1; i > 0; i--)
		{
			pf *= nums[i];
			ans[i - 1] *= pf;
		}
		pf = 1;
		for (int i = 0; i < n - 1; i++)
		{
			pf *= nums[i];
			ans[i + 1] *= pf;
		}
		return ans;
	}
};