#include <iostream>
#include <vector>
using namespace std;

pair<int,int> recursive(vector<int>& nums, vector<int>& dp, int idx)
{
	if (idx == nums.size()-1)
	{
		return make_pair(nums[idx], dp[idx]);
	}

	const pair<int, int>& res = recursive(nums, dp, idx + 1);

	if (res.first < nums[idx])
	{
		dp[idx] += res.second;
		return make_pair(nums[idx], dp[idx]);
	}

	for (int i = idx + 1; i < nums.size(); i++)
	{
		if (nums[idx] > nums[i] && dp[idx] <= dp[i])
		{
			dp[idx] = dp[i]+1;
		}
	}

	return res.second > dp[idx] ? res : make_pair(nums[idx], dp[idx]);
}
int main()
{
	int N;
	cin >> N;

	vector<int> nums(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	vector<int> dp(N, 1);

	cout<<nums.size()-recursive(nums, dp,0).second<<'\n';

}