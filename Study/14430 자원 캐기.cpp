#include <iostream>
#include <vector>
using namespace std;

int dfs(int R,int C,vector<vector<int>>& land, vector<vector<int>> &dp, pair<int, int> pos)
{
	if (pos.first >= R || pos.second >= C) return 0;

	if (dp[pos.first][pos.second] != 0)
		return dp[pos.first][pos.second];
	//오른쪽으로 한 칸 이동
	int left=dfs(R, C, land, dp,make_pair(pos.first, pos.second + 1));

	//왼쪽으로 한칸 이동
	int right=dfs(R, C, land, dp,make_pair(pos.first + 1, pos.second));

	dp[pos.first][pos.second] = land[pos.first][pos.second] + max(left, right);
	return dp[pos.first][pos.second];
}
int main()
{
	int R, C;
	cin >> R >> C;

	vector<vector<int>> land(R, vector<int>(C));
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> land[i][j];
		}
	}
	vector<vector<int>> dp(R, vector<int>(C, 0));
	cout<<dfs(R,C,land,dp,make_pair(0,0));
}