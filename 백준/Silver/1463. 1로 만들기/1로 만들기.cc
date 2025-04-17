#include <bits/stdc++.h>
using namespace std;

int dp[1'000'005];

int recursive(int X)
{
	
	if (X <= 1)
	{
		return 0;
	}

	if (dp[X] != 0)
	{
		return dp[X];
	}

	int three = 0, two = 0, one = 0;
	if (X % 3 == 0)
	{
		three = recursive(X / 3) + 1;
	}

	if (X % 2 == 0)
	{
		two = recursive(X / 2) + 1;
	}

	one = recursive(X - 1) + 1;

	if (three == 0)
	{
		three = 100'000;
	}

	if (two == 0)
	{
		two = 100'000;
	}

	if (one == 0)
	{
		one = 100'000;
	}

	return dp[X] = min(min(one,two),three);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin>>N;

	cout<<recursive(N)<<'\n';
}
