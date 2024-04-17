#include <iostream>
#include <vector>
using namespace std;

int rows[4] = { -1,1,0,0 };
int cols[4] = { 0,0,-1,1 };

int recursive(int N,vector<vector<int>> &arr,vector<vector<int>> &dp,int r,int c)
{
	if (r < 0 || c < 0 || r >= arr.size() || c >= arr.size())
	{
		return 0;
	}

	if (dp[r][c] != 0) return dp[r][c];

	int res = 1;
	for (int i = 0; i < 4; i++)
	{
		int nextR = r + rows[i];
		int nextC = c + cols[i];

		if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= N) continue;

		if (arr[r][c] < arr[nextR][nextC])
		{
			res = max(res, recursive(N, arr, dp, nextR, nextC) + 1);
		}
	}

	return dp[r][c] = res;
}

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> arr(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	vector<vector<int>> dp(N, vector<int>(N, 0));

	int maxVal = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			maxVal = max(maxVal, recursive(N, arr, dp, i, j));
		}
	}
	cout << maxVal << '\n';

}