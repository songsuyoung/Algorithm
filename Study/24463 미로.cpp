#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void print(int N, int M, vector<string>& maze)
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << maze[i][j];
		}
		cout << '\n';
	}
}

void rollback(int N, int M, vector<string>& maze, vector<vector<pair<int, int>>>& arr, pair<int, int> st, pair<int, int> ed)
{

	pair<int, int> back = arr[ed.first][ed.second];
	maze[ed.first][ed.second] = '.';
	while (back != st)
	{
		if (back.first < 0 || back.second < 0 || back.first >= N || back.second >= M) continue;
		maze[back.first][back.second] = '.';
		back = arr[back.first][back.second];
	}

	maze[back.first][back.second] = '.';
}


void bfs(int N, int M, vector<string>& maze, pair<int, int> st, pair<int, int> ed)
{
	vector<vector<bool>> isVisited(N + 1, vector<bool>(M + 1, 0));
	vector<vector<pair<int, int>>> arr(N + 1, vector <pair<int, int>>(M + 1, { 0,0 }));
	queue<pair<int, int>> q;

	q.push(st);

	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		if (isVisited[cur.first][cur.second]) continue;
		if (cur == ed) break;

		isVisited[cur.first][cur.second] = true;
		for (int i = 0; i < 4; i++)
		{
			int nextR = cur.first + rows[i];
			int nextC = cur.second + cols[i];

			if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= M || maze[nextR][nextC] == '+' || isVisited[nextR][nextC]) continue;

			arr[nextR][nextC] = cur;
			q.push({ nextR,nextC });
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (maze[i][j] == '.') maze[i][j] = '@';
		}
	}

	rollback(N, M, maze, arr, st, ed);
	print(N, M, maze);
}


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	

	vector<string> maze(N+1);

	vector<pair<int, int>> dest;
	for (int i = 0; i < N; i++)
	{
		cin >> maze[i];
	}

	for (int i = 0; i < M; i++)
	{
		if (maze[0][i] == '.')
		{
			dest.push_back({ 0,i });
		}

		if (maze[N-1][i] == '.')
		{
			dest.push_back({ N-1,i });
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (maze[i][0] == '.')
		{
			dest.push_back({ i,0 });
		}

		if (maze[i][M - 1] == '.')
		{
			dest.push_back({ i,M-1 });
		}
	}
	
	bfs(N, M, maze, dest[0], dest[1]);
}