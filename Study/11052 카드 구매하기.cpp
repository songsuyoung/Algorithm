#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> dp(N+1, 0);

	for (int i = 1; i <= N; i++)
	{
		int coin;
		cin >> coin;

		for (int j = i; j <= N; j++)
		{
			dp[j] = max(dp[j], dp[j-i] + coin);
		}
	}

	cout << dp[N] << '\n';
}