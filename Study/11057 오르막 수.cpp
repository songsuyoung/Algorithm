#include <iostream>
#include <vector>
using namespace std;

int main()
{

	vector<int> dp(10, 1);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{//N번 반복
		for (int j = 1; j < 10; j++)
		{
			dp[j] = (dp[j] + dp[j - 1])%10'007;
		}
	}
	cout << dp[9] << '\n';
}