#include <iostream>
#include <vector>
using namespace std;

//Top-Down 방식
int recursive(vector<vector<int>>& rooms, vector<vector<int>>& dp,int r,int c)
{
	if (r >= rooms.size() || c >= rooms[0].size()) return 0;
	if (r == rooms.size() - 1 && c == rooms[0].size() - 1)
		return dp[r][c]=rooms[r][c];

	if (dp[r][c] != -1) return dp[r][c];

	return dp[r][c]=max(recursive(rooms, dp, r + 1, c), max(recursive(rooms, dp, r + 1, c + 1), recursive(rooms, dp, r, c + 1)))+rooms[r][c];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;

	vector<vector<int>> rooms(N+1, vector<int>(M+1, 0));
	vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> rooms[i][j];
			dp[i][j] = rooms[i][j];
		}
	}

	//Bottom-Up

	for (int i = 1; i<=N; i++)
	{
		for (int j = 1; j<=M; j++)
		{
			dp[i][j]= max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1]))+rooms[i][j];
		}
	}
	
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	//cout << recursive(rooms,dp,0,0);
}