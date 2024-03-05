#include <bits/stdc++.h>
using namespace std;
using ll = long long;


// 1 2
// 
bool recursive(vector<ll> &nums, pair<int,int> cmd, vector<vector<int>> &dp)
{
	if (cmd.first == cmd.second)
		return	dp[cmd.first][cmd.second] = 1;
	
	if (dp[cmd.first][cmd.second] != -1) return dp[cmd.first][cmd.second];

	if ((cmd.first + 1) <= (cmd.second - 1))
	{
		bool preRes = recursive(nums, make_pair(cmd.first + 1, cmd.second - 1), dp);

		if (preRes && nums[cmd.first] != nums[cmd.second])
		{
			dp[cmd.first][cmd.second] = 0;
		}
		else if (preRes && nums[cmd.first] == nums[cmd.second])
		{
			dp[cmd.first][cmd.second] = 1;
		}
		else
		{
			dp[cmd.first][cmd.second] = preRes;
		}
	}
	else
	{
		//길이가 2차이 날경우
		if (nums[cmd.first] == nums[cmd.second])
		{
			dp[cmd.first][cmd.second] = true;
		}
		else
		{
			dp[cmd.first][cmd.second] = false;
		}
	}
	return dp[cmd.first][cmd.second];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;

	vector<ll> nums(N+1,0);
	for (int i = 1; i <= N; i++)
	{
		cin >> nums[i];
	}

	int M;
	cin >> M;

	pair<int, int> cmd;
	vector<vector<int>> dp(2002,vector<int>(2002,-1));

	for (int i = 0; i < M; i++)
	{
		cin >> cmd.first >> cmd.second;
		
		cout << recursive(nums, cmd, dp) <<'\n';
	}

}