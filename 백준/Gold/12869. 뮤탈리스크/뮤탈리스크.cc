#include <bits/stdc++.h>
using namespace std;

int dp[65][65][65];

int recursive(int N, int one, int two, int three)
{
	if (one < 0)
	{
		one = 0;
	}

	if (two < 0)
	{
		two = 0;
	}

	if (three < 0)
	{
		three = 0;
	}
	if (one == 0 && two == 0 && three == 0)
	{
		//종료
		return 0;
	}

	if (dp[one][two][three] != INT_MAX)
	{
		return dp[one][two][three];
	}

	if (N == 1)
	{
		dp[one][two][three] = min(dp[one][two][three], recursive(N, one - 9, two, three) + 1);
	}
	else if (N == 2)
	{
		dp[one][two][three] = min(dp[one][two][three], recursive(N, one - 9, two - 3, three)+1);
		dp[one][two][three] = min(dp[one][two][three], recursive(N, one - 3, two - 9, three)+1);
	}
	else
	{
		//N 3개
		dp[one][two][three] = min(dp[one][two][three], recursive(N, one - 9, two - 3, three - 1) + 1);
		dp[one][two][three] = min(dp[one][two][three], recursive(N, one - 9, two - 1, three - 3) + 1);
		dp[one][two][three] = min(dp[one][two][three], recursive(N, one - 3, two - 9, three - 1) + 1);
		dp[one][two][three] = min(dp[one][two][three], recursive(N, one - 3, two - 1, three - 9) + 1);
		dp[one][two][three] = min(dp[one][two][three], recursive(N, one - 1, two - 3, three - 9) + 1);
		dp[one][two][three] = min(dp[one][two][three], recursive(N, one - 1, two - 9, three - 3) + 1);
	}

	return dp[one][two][three];
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin>>N;

	vector<int> scv(3,0);

	for (int i = 0; i < N; i++)
	{
		cin>>scv[i];
	}

	for (int i = 60; i >= 0; i--)
	{
		for (int j = 60; j >= 0; j--)
		{
			for (int k = 60; k >= 0; k--)
			{
				dp[i][j][k] = INT_MAX;
			}
		}
	}

	cout<<recursive(N, scv[0], scv[1], scv[2])<<'\n';
}
