#include <bits/stdc++.h>
using namespace std;

void print(int N, int M, vector<vector<int>>& board)
{
	//출력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout<<board[i][j]<<' ';
		}
		cout<<'\n';
	}
}
int bfs(int N, int M, vector<vector<int>>& board, queue<pair<int, int>> virus)
{
	vector<vector<int>> temp = board;
	vector<vector<bool>> isVisited(N,vector<bool>(M,0));

	int rows[4] = {-1,1,0,0};
	int cols[4] = {0,0,-1,1};

	while (!virus.empty())
	{
		pair<int,int> cur = virus.front();

		virus.pop();

		if (isVisited[cur.first][cur.second]) continue;

		isVisited[cur.first][cur.second] = true;
		temp[cur.first][cur.second] = 2;

		for (int i = 0; i < 4; i++)
		{
			int nextR = rows[i] + cur.first;
			int nextC = cols[i] + cur.second;
			
			if(nextR<0||nextC<0||nextR>=N||nextC>=M||isVisited[nextR][nextC]|| temp[nextR][nextC] != 0) continue;

			virus.push({nextR,nextC});
		}
	}

	//개수 확인

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (temp[i][j] == 0)
			{
				answer++;
			}
		}
	}

	return answer;
}
int recursive(int N, int M, vector<vector<int>>& board, queue<pair<int,int>>& virus, int selected, int r, int c)
{
	if (selected <= 0)
	{
		//print(N, M, board);
		return bfs(N,M,board,virus);
	}

	int answer = 0;
	for (int i = r; i < N; i++)
	{
		for (int j = c; j < M; j++)
		{
			if(board[i][j] != 0) continue;
			
			//벽 설치
			board[i][j] = 1;
			answer = max(answer, recursive(N,M,board,virus,selected-1,r,c));
			//벽 해제
			board[i][j] = 0;
		}
	}

	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N,M;

	cin>>N>>M;

	vector<vector<int>> board(N, vector<int>(M,0));

	//바이러스 위치를 중심으로 BFS를 돌리기 때문에, BFS의 값을 저장
	queue<pair<int,int>> virus;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin>>board[i][j];

			if (board[i][j] == 2)
			{
				virus.push({i,j});
			}
		}
	}

	//완전 탐색 진행 (3개의 벽을 선택)
	int answer = recursive(N,M, board, virus, 3,0,0);

	cout<<answer<<'\n';
}

/*
바이러스 확산을 막기 위해서 연구소에 벽을 세우려고 한다.
이 바이러스는 상하좌우 이동 => 새로 세울 수 있는 벽의 개수는 3개이며 꼭 3개를 세워야함.
=> 벽을 세우고, BFS나 DFS로 안전영역의 크기를 확인한다.
=> 현재 세울 수 있는 벽의 개수는 3개이기 때문에, 3개의 벽을 먼저 세운다.
	* 처음에 바이러스를 중심이라고 생각했지만, 이는 아닌듯 하다.
	* 전부다 선택해보는 완전 탐색으로 진행해 본다.
	* 3개의 row/col 선택하고, 1을 찍은 뒤 (DFS 선택)
	* BFS로 안전 영역의 크기 확인 (Max값 리턴)
*/