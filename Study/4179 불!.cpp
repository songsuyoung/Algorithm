#include <bits/stdc++.h>
using namespace std;

void CalFireDist(int R,int C,vector<vector<char>>& arr, queue<pair<int, int>>& q, vector<vector<int>>& fireDist)
{
	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };

	while (!q.empty())
	{
		pair<int, int> pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextR = pos.first + rows[i];
			int nextC = pos.second + cols[i];

			if (nextR <= 0 || nextC <= 0 || nextR >= R || nextC >= C || arr[nextR][nextC] == '#') continue;

			if (fireDist[nextR][nextC] > fireDist[pos.first][pos.second] + 1)
			{
				fireDist[nextR][nextC] = fireDist[pos.first][pos.second] + 1;
				q.push(make_pair(nextR, nextC));
			}
		}
	}
}

int BFS(int R, int C, vector<vector<char>>& arr, vector<vector<int>>& fireDist, pair<int, int> start)
{
	queue<pair<int, pair<int, int>>> q;
	vector<vector<bool>> isVisited(R, vector<bool>(C, false));
	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };

	q.push(make_pair(0, start));

	while (!q.empty())
	{
		int cnt = q.front().first;
		pair<int, int> pos = q.front().second;

		q.pop();

		if (pos.first >= R||pos.second>=C||pos.first<=0||pos.second<=0) return cnt;
		if (fireDist[pos.first][pos.second] <= cnt || isVisited[pos.first][pos.second]) continue;

		isVisited[pos.first][pos.second] = true;
		for (int i = 0; i < 4; i++)
		{
			int nextR = pos.first + rows[i];
			int nextC = pos.second + cols[i];

			if (nextR < 0 || nextC < 0 || nextR > R || nextC > C || arr[nextR][nextC] == '#') continue;	
			if(fireDist[nextR][nextC]>cnt+1)
				q.push(make_pair(cnt + 1, make_pair(nextR, nextC)));
		}
	}

	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	queue<pair<int, int>> fire;
	pair<int, int> start;

	int R, C;
	cin >> R >> C;

	vector<vector<char>> arr(R + 2, vector<char>(C + 2, '.'));
	vector<vector<int>> fireDis(R + 2, vector<int>(C + 2, INT_MAX));
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 'F')
			{
				fire.push(make_pair(i, j));
				fireDis[i][j] = 0;
			}

			if (arr[i][j] == 'J')
			{
				start.first = i;
				start.second = j;
			}
		}
	}

	CalFireDist(R+1,C+1,arr,fire, fireDis);
	int answer = BFS(R+1,C+1,arr, fireDis, start);

	if (answer < 0)
	{
		cout << "IMPOSSIBLE \n";
	}
	else
	{
		cout << answer << '\n';
	}
}