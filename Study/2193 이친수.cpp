#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll recursive(int N,vector<ll> &dp)
{
	if (N < 0)
	{
		return dp[0];
	}
	else if (N == 1)
	{
		return dp[1];
	}

	if (dp[N] != -1) return dp[N];

	return dp[N]=recursive(N - 1, dp) + recursive(N - 2, dp);
}
int main()
{
	int N;
	cin >> N;

	vector<ll> dp(N+1, -1);
	dp[0] = 0;
	dp[1] = 1;
	cout<<recursive(N,dp);
}