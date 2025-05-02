#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> tmp;

void Melt(int R, int C, vector<string>& lake, vector<vector<bool>>& isVisited)
{
	queue<pair<int, int>> q = tmp;

	while (!tmp.empty())
	{
		tmp.pop();
	}

	int rows[] = { -1,1,0,0 };
	int cols[] = { 0,0,-1,1 };

	while (!q.empty())
	{
		pair<int, int> cur = q.front();

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextR = cur.first + rows[i];
			int nextC = cur.second + cols[i];

			if (nextR < 0 || nextC < 0 || nextR >= R || nextC >= C || isVisited[nextR][nextC]) continue;

			if (lake[nextR][nextC] == 'X')
			{
				isVisited[nextR][nextC] = true;
				tmp.push({nextR, nextC});
				lake[nextR][nextC] = '.';
			}
		}
	}
}

queue<pair<int, int>> next_swan;
bool Move(int N, int R, int C, vector<vector<bool>>& isVisited, vector<string>& lake)
{
	queue<pair<int, int>> q = next_swan;

	int rows[] = { -1,1,0,0 };
	int cols[] = { 0,0,-1,1 };
	
	while (!next_swan.empty())
	{
		next_swan.pop();
	}
	
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

			if (nextR < 0 || nextC < 0 || nextR >= R || nextC >= C || isVisited[nextR][nextC]) continue;

			if (lake[nextR][nextC] == 'X')
			{
				next_swan.push({nextR, nextC});
				continue;
			}

			if (lake[nextR][nextC] == 'L')
			{
				return true;
			}

			q.push({ nextR,nextC });
		}
	}

	return false;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int R, C;

	cin >> R >> C;

	vector<string> lake(R);

	int N = 0;
	pair<int,int> swan;

	for (int i = 0; i < R; i++)
	{
		cin >> lake[i];

		for (int j = 0; j < C; j++)
		{
			if (lake[i][j] == 'L')
			{
				//백조 존재
				swan = {i,j};
			}
			
			if (lake[i][j] != 'X')
			{
				tmp.push({i,j});
			}
		}
	}

	int answer = 0;
	next_swan.push(swan);
	vector<vector<bool>> isVisited_swan(R, vector<bool>(C, 0));
	vector<vector<bool>> isVisited(R, vector<bool>(C, 0));

	while (true)
	{
		//백조 이동한다.
		bool result = Move(N, R, C, isVisited_swan, lake);
		
		if (result) break;
		answer++;

		Melt(R, C, lake, isVisited);
	}

	cout << answer << '\n';
}

/*
두 마리의 백조
R/C 얼음이 덮여있음.

물공간과 접촉한 빙판이 모두 녹음 (치즈 문제랑 비슷한데?)
물 . 빙판 X 백조 L

- 물이 X를 만날때까지 이동하다가, X를 만나면 .로 표시하고 BFS를 멈춤.
- 백조의 개수를 센다. => 한 백조가 N백조를 만나면 되는 문제. 전부 확인?
*/