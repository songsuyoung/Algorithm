#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> isVisitedForFire(1005, vector<int>(1005, 0));

int BFS(int R, int C, vector<string>& board, queue<pair<int, int>> jihun, queue<pair<int, int>> fire)
{
	int rows[4] = {-1,1,0,0};
	int cols[4] = {0,0,-1,1};
	
	while (!fire.empty())
	{
		pair<int,int> cur = fire.front();
		fire.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextR = cur.first + rows[i];
			int nextC = cur.second + cols[i];

			if(nextR<0||nextC<0||nextR>=R||nextC>=C||isVisitedForFire[nextR][nextC]||board[nextR][nextC] == '#') continue;
			
			isVisitedForFire[nextR][nextC] = isVisitedForFire[cur.first][cur.second] + 1;

			fire.push({nextR, nextC});
		}
	}

	vector<vector<int>> isVisitedForJihun(R + 1, vector<int>(C + 1, 0));

	isVisitedForJihun[jihun.front().first][jihun.front().second] = 1;

	while (!jihun.empty())
	{
		pair<int, int> cur = jihun.front();
		jihun.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextR = cur.first + rows[i];
			int nextC = cur.second + cols[i];

			if (nextR<0 || nextC<0 || nextR>=R || nextC>=C)
			{
				return isVisitedForJihun[cur.first][cur.second];
			}

			if (isVisitedForJihun[nextR][nextC] || board[nextR][nextC] != '.') continue;

			if(isVisitedForFire[nextR][nextC] && isVisitedForJihun[cur.first][cur.second] + 1 >= isVisitedForFire[nextR][nextC]) continue;

			isVisitedForJihun[nextR][nextC] = isVisitedForJihun[cur.first][cur.second] + 1;

			jihun.push({ nextR,nextC });
		}
	}

	return -1;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int R,C;
	cin>>R>>C;

	vector<string> board(R);

	queue<pair<int,int>> jihun;
	queue<pair<int,int>> fire;

	for (int i = 0; i < R; i++)
	{
		cin>>board[i];

		for (int j = 0; j < C; j++)
		{
			if (board[i][j] == 'J')
			{
				jihun.push({ i,j });
			}

			if (board[i][j] == 'F')
			{
				fire.push({ i,j });

				isVisitedForFire[i][j] = 1;
			}
		}
	}

	int answer = BFS(R, C, board, jihun, fire);

	if (answer == -1)
	{
		cout<<"IMPOSSIBLE\n";
	}
	else
	{
		cout<<answer<<'\n';
	}
}


/*
지훈이가 이동 
불이 같이 이동

지훈이가 이동할 수 있는 경로 queue 넣고,
불이 이동할 수 있는 경로 queue 넣음.

queue를 모두 뺌
*/