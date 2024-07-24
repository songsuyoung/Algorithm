#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>>& arr, vector<bool>& isVisited, vector<int> &dp, int idx)
{
	int res = 1;
	isVisited[idx] = true; //방문 처리하고 

	for (int i = 0; i < arr[idx].size(); i++)
	{
		int cur = arr[idx][i];
		if (isVisited[cur]) continue; //방문 했으면, dfs를 하지 않도록 함.

		res += dfs(arr, isVisited, dp, cur); //이동
	}

	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> arr(N + 1);

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;

		arr[B].push_back(A);
	}

	vector<int> dp(N + 1, 1);
	int maxVal = 0;
	for (int i = 1; i <= N; i++) //N
	{
		vector<bool> isVisited(N + 1, false);
		dp[i] = dfs(arr, isVisited, dp, i); //N
		maxVal = max(maxVal, dp[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		if (maxVal == dp[i])
		{
			cout << i << ' ';
		}
	}
}