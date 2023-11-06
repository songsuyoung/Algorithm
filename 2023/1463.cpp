#include <iostream>
#include <climits>
using namespace std;

int recursive(int N,int *dp, const int initVal)
{
	if (N <= 0)
		return dp[0];

	if (N == 1)
		return dp[1];

	if (dp[N] != initVal)
		return dp[N];


	int three = initVal, two = initVal, minus = initVal;
	if (N % 3 == 0)
		three =recursive(N / 3, dp, initVal)+1;
	if (N % 2 == 0)
		two = recursive(N / 2, dp, initVal)+1;
	
	int res = min(three, two);
	
	minus = recursive(N - 1, dp, initVal)+1;

	dp[N]= min(res, minus);
	return dp[N];
}

int main()
{
	int N;
	int* dp = new int[1000001];
	cin >> N;

	for (int i = 0; i <= N; i++)
	{
		dp[i] = 1000002;
	}
	dp[1] = 0;

	cout <<recursive(N,dp, 1000002);
	delete dp;
}