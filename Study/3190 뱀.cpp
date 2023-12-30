#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

struct Snake
{
	deque<pair<int, int>> pos; //몸의 좌표를 저장, 길어질 수있음..
	int dir=1; //초반 동쪽으로 이동.
	int cnt = 0;
};

int bfs(int N,vector<vector<int>> &board, Snake& snake,vector<pair<int,int>> commands)
{
	int rows[4] = { -1,0,1,0 };
	int cols[4] = { 0,1,0,-1 };

	int idx = 0;
	while (true)
	{
		int nextR = snake.pos.front().first + rows[snake.dir];
		int nextC = snake.pos.front().second + cols[snake.dir];
		//한칸 씩 이동
		//사과 위치 
		snake.cnt += 1;

		if (nextR <= 0 || nextC <= 0 || nextR > N || nextC > N) return snake.cnt;
		for (int j = 0; j < snake.pos.size(); j++)
		{
			if (snake.pos[j].first == nextR && snake.pos[j].second == nextC)
				return snake.cnt;
		}
		snake.pos.push_front(make_pair(nextR, nextC));

		if (board[nextR][nextC] != 1)
		{
			//이전 위치 몸 줄이기
			snake.pos.pop_back();
		}
		if (board[nextR][nextC] == 1)
		{
			board[nextR][nextC] = 0;
		}

		if (idx<commands.size()&&snake.cnt == commands[idx].first)
		{
			if (commands[idx].second == 'D')
			{
				snake.dir = (snake.dir + 1) % 4;
			}
			
			if (commands[idx].second == 'L')
			{
				snake.dir = (4 + (snake.dir - 1)) % 4;
			}
			idx += 1;
		}
		//위치 변경
	}
	
	return snake.cnt;
}


int main()
{
	int N;
	cin >> N;
	int A;
	cin >> A;

	vector<vector<int>> board(N+1, vector<int>(N+1, 0));
	Snake snake;
	snake.pos.push_back(make_pair(1, 1));
	
	for (int i = 0; i < A; i++)
	{
		int r, c;
		cin >> r >> c;

		board[r][c] = 1; //애플 위치 
	}

	int C;
	cin >> C;
	vector<pair<int, int>> commands;
	for (int i = 0; i < C; i++)
	{
		int go;
		char dir;
		cin >> go >> dir;

		commands.push_back(make_pair(go, dir));
	}
	cout <<bfs(N, board, snake, commands)<< '\n';
}