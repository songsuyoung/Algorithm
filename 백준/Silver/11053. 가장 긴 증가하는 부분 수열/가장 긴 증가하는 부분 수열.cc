#include <bits/stdc++.h>
using namespace std;

vector<int> dp(1'005);

pair<int, int> recursive(int N, vector<int>& arr, int idx)
{
	if (idx >= N-1)
	{
		return {idx, dp[idx]};
	}

	pair<int,int> pre = recursive(N, arr, idx+1);

	//>= ㄴㄴ
	if (arr[pre.first] > arr[idx])
	{
		dp[idx] = pre.second + 1;
		return {idx, pre.second + 1};
	}

	int original = dp[idx];
	for (int i = idx + 1; i < N; i++)
	{
		if (arr[idx] < arr[i] && dp[idx] <= dp[i])
		{
			dp[idx] = max(dp[idx], original + dp[i]);
		}
	}

	return dp[idx] > pre.second ? make_pair(idx, dp[idx]) : pre;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin>>N;

	vector<int> arr(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin>>arr[i];
		dp[i] = 1;  //자기 자신 포함
	}

	
	pair<int,int> res = recursive(N, arr, 0);

	cout<<res.second<<'\n';
}
