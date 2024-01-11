#include <iostream>
#include <vector>
using namespace std;

long long recursive(int C, vector<int>& dp)
{
	if (C < 0) return 0;
	if (C <= 1) return dp[C];

	if (dp[C] != 0) return dp[C];

	int a = recursive(C - 1, dp);
	int b = recursive(C - 2, dp); //2의 경우의 수가 2개로 늘어남

	return dp[C] = (a + 2*b) % 10007;
}
int main()
{
	int N;
	cin >> N;

	vector<int> dp(1001, 0);

	dp[0] = 1;
	dp[1] = 1;

	cout << recursive(N, dp) << '\n';
}