#include <bits/stdc++.h>
using namespace std;

bool Jump(int R, int C, vector<string>& board, pair<int, int> junan)
{
	int rows[] = { -1,1,0,0 };
	int cols[] = { 0,0,-1,1 };

	vector<vector<bool>> isVisited(305, vector<bool>(305, false));
	queue<pair<int, int>> q;

	q.push(junan);

	vector<string> tmp = board;

	while (!q.empty())
	{
		pair<int,int> cur = q.front();

		q.pop();

		if(isVisited[cur.first][cur.second]) continue;

		if (board[cur.first][cur.second] == '#')
		{
			return true;
		}

		isVisited[cur.first][cur.second] = true;
		for (int i = 0; i < 4; i++)
		{
			int nextR = rows[i] + cur.first;
			int nextC = cols[i] + cur.second;

			if(nextR<0||nextC<0||nextR>=R||nextC>=C||isVisited[nextR][nextC]) continue; //퍼짐이 멈춘다.

			//0일경우에는 퍼져나간다.
			if (board[nextR][nextC] != '1')
			{
				q.push({nextR,nextC});
			}
			else
			{
				//1일경우에는 1->0으로 바꾸고 멈춘다.
				tmp[nextR][nextC] = '0';
			}
		}
	}

	board = tmp; //덮어쓴다.

	return false;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N,M;
	cin>>N>>M;

	vector<string> board(N);

	pair<int,int> junan;
	pair<int,int> target;

	cin>>junan.first>>junan.second;
	cin>>target.first>>target.second;

	//1씩 감소시켜야한다.
	junan.first -= 1;
	junan.second -= 1;
	target.first -= 1;
	target.second -= 1;

	for (int i = 0; i < N; i++)
	{
		cin>>board[i];
	}

	int answer = 0;

	while(true)
	{
		
		//초코바를 못찾으면 점프해서 쓰러트린다.
		bool res = Jump(N, M, board, junan);

		answer++;

		if (res)
		{
			break;
		}

	}

	cout<<answer<<'\n';
}

/*
주난이가 화가 남. 초코바가 사라짐.

상하좌우로 4방향 친구들을 모두 쓰러트릴때까지 계속 퍼져 나감.


예) * 주난 초코바 #

한번의 점프로 한 겹 친구들이 쓰러짐.

0을 만날때까지 친구들을 쓰러트림

1. 친구를 쓰러트린다. 0일 경우에 1을 만날때까지 상하좌우 방문 => BFS
2. 초코바를 만날 수 있는지 확인 => 경로 찾기 BFS
*/