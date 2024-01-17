#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	return a.first < b.first;
}
pair<int, int> recursive(const vector<pair<int, int>>& wire, vector<int>& dp, int idx)
{
	if ((wire.size() - 1) == idx)
	{
		return make_pair(idx, dp[idx]);
	}

	pair<int, int> res = recursive(wire, dp, idx + 1);

	if (wire[res.first].second > wire[idx].second)
	{
		dp[idx] = res.second+1;
		return make_pair(idx, dp[idx]);
	}

	for (int i = idx; i < wire.size(); i++)
	{
		if (wire[idx].second < wire[i].second && dp[idx] <= dp[i])
		{
			dp[idx] = dp[i] + 1;
		}
	}

	return dp[idx] > res.second ? make_pair(idx, dp[idx]) : res;
}
int main()
{
	int N;
	cin >> N;

	vector<pair<int, int>> wire(N);
	for (int i = 0; i < N; i++)
	{
		cin >> wire[i].first >> wire[i].second;
	}

	sort(wire.begin(), wire.end(),compare);

	vector<int> dp(wire.size(), 1);

	cout<<wire.size()-recursive(wire, dp,0).second<<'\n';
}