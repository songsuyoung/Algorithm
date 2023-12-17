#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(int R, int C, queue<pair<int, int>>& q, vector<vector<bool>>& isVisited, vector<vector<char>>& board)
{
	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };
	while (!q.empty())
	{
		pair<int, int> pos = q.front();
		q.pop();

		if (pos.first >= R-1)
		{
			return true;
		}

		if (isVisited[pos.first][pos.second]) continue;
		isVisited[pos.first][pos.second] = true;

		for (int i = 0; i < 4; i++)
		{
			int nextR = pos.first + rows[i];
			int nextC = pos.second + cols[i];

			if (nextR < 0 || nextR>=R||nextC < 0 || nextC >= C || board[nextR][nextC] == '1') continue;

			q.push(make_pair(nextR, nextC));
		}

	}

	return false;
}
int main()
{
	int R, C;
	cin >> R >> C;

	vector<vector<char>> board(R, vector<char>(C,false));
	queue<pair<int, int>> q;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];

			if (i == 0 && board[i][j] == '0')
			{
				q.push(make_pair(i, j));
			}
		}
	}

	vector<vector<bool>> isVisited(R, vector<bool>(C, false));
	bool isSuccess=bfs(R,C,q, isVisited, board);

	if (isSuccess)
		cout << "YES\n";
	else
		cout << "NO\n";
}