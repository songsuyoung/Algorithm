#include <bits/stdc++.h>
using namespace std;

void moveFire(int R,int C,queue<pair<int, int>>& q, vector<vector<char>>& building, vector<vector<int>>& distance)
{
	vector<vector<bool>> isVisited(R+1, vector<bool>(C+1, false));

	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };

	while (!q.empty())
	{
		pair<int, int> cur = q.front();

		q.pop();

		if (isVisited[cur.first][cur.second]) continue;
		isVisited[cur.first][cur.second] = true;

		for (int i = 0; i < 4; i++)
		{
			int nextR = cur.first + rows[i];
			int nextC = cur.second + cols[i];

			if (nextR <= 0 || nextC <= 0 || nextR >= R || nextC >= C || building[nextR][nextC] == '#'||isVisited[nextR][nextC]) continue;
		
			if (distance[nextR][nextC] != INT_MAX) continue;
			distance[nextR][nextC] = distance[cur.first][cur.second] + 1;
			q.push(make_pair(nextR, nextC));

		}
	}
}

int bfs(int R,int C,const vector<vector<int>>& distance, vector<vector<char>>& building, pair<int, int> cur)
{
	vector<vector<bool>> isVisited(R+1, vector<bool>(C+1, false));
	queue<pair<int, pair<int, int>>> q;

	q.push(make_pair(0, cur));

	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };
	while (!q.empty())
	{
		pair<int, int> cur = q.front().second;
		int cnt = q.front().first;

		q.pop();
		if (isVisited[cur.first][cur.second] || distance[cur.first][cur.second] <= cnt) continue;
		if (cur.first <= 0 || cur.second <= 0 || cur.first >= R || cur.second >= C) return cnt;
		isVisited[cur.first][cur.second] = true;

		for (int i = 0; i < 4; i++)
		{
			int nextR = cur.first + rows[i];
			int nextC = cur.second + cols[i];

			if (nextR<0 || nextC<0 || nextR>R || nextC>C || building[nextR][nextC] == '#'|| distance[nextR][nextC] <= cnt) continue;

			q.push(make_pair(cnt + 1, make_pair(nextR, nextC)));
		}

	}
	return 0;
}
int main()
{
	int T;
	cin >> T;

	for (int testCase = 0; testCase < T; testCase++)
	{
		int R, C;
		cin >> C >> R;

		vector<vector<char>> building(R+2,vector<char>(C+2));
		pair<int, int> start;
		queue<pair<int, int>> q;

		vector<vector<int>> distance(R + 2, vector<int>(C + 2, INT_MAX));
		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				cin >> building[i][j];

				if (building[i][j] == '@')
				{
					start.first = i;
					start.second = j;
				}

				else if (building[i][j] == '*')
				{
					q.push(make_pair(i, j));
					distance[i][j] = 0;
				}
			}
		}

		moveFire(R + 1, C + 1,q, building, distance);
		int res=bfs(R+1,C+1,distance, building,start);

		if (res == 0)
		{
			cout << "IMPOSSIBLE\n";
		}
		else
		{
			cout << res << '\n';
		}
	}
}