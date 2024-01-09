/*
목표 : 최단 거리의 max값을 찾는다.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<bool>>& isVisited, vector<vector<char>>& board, pair<int, int> st)
{
	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };

	queue < pair<int, pair<int, int>>> q;
	int cnt = 0;
	q.push(make_pair(0, st));
	while (!q.empty())
	{
		cnt = q.front().first;
		pair<int, int> pos = q.front().second;

		q.pop();

		if (isVisited[pos.first][pos.second]) continue;
		isVisited[pos.first][pos.second] = true;
		for (int i = 0; i < 4; i++)
		{
			int nextR = pos.first + rows[i];
			int nextC = pos.second + cols[i];

			if (nextR < 0 || nextC < 0 || nextR >= board.size() || nextC >= board[0].size() || isVisited[nextR][nextC]||board[nextR][nextC]!='L') continue;
 		
			q.push(make_pair(cnt + 1, make_pair(nextR, nextC)));
		}
	}

	return cnt;
}
int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<char>> board(N, vector<char>(M));
	vector<pair<int, int>> stPoint;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 'L')
				stPoint.push_back(make_pair(i, j));
		}
	}

	int res = 0;

	//시작점 선택... 
	for (int k = 0; k < stPoint.size(); k++)
	{
		vector<vector<bool>> isVisited(N, vector<bool>(M, false));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (board[i][j] == 'L' && isVisited[i][j] == false)
				{
					res = max(res, bfs(isVisited, board, stPoint[k]));
				}
			}
		}
	}

	cout << res << '\n';
}