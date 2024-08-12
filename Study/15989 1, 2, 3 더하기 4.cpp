#include <iostream>
#include <vector>
using namespace std;

int main()
{

	int TC;

	cin >> TC;

	for (int i = 0; i < TC; i++)
	{

		int n;
		cin >> n;

		vector<int> dp(n+1, 0);

		dp[0] = 1;

		for (int i = 1; i <=3; i++)
		{
			for (int j = i; j <= n; j++)
			{
				dp[j] = dp[j - i] + dp[j];
			}
		}
		cout << dp[n] << '\n';
	}
}