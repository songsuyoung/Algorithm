#include <bits/stdc++.h>
using namespace std;

int bfs(int N, int M,const vector<string>& maze)
{

	vector<vector<bool>> isVisited(N, vector<bool>(M, false));

	queue<pair<pair<int, int>,int>> q; //위치 저장을 위함.

	//시작 1,1 -> 인덱스 0부터 시작하기 때문에 0,0 으로 보정
	q.push({ { 0,0 },0 });

	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };
	

	while (!q.empty())
	{
		pair<int, int> cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (isVisited[cur.first][cur.second])
		{
			continue;
		}

		if (cur.first == N - 1 && cur.second == M - 1) return cnt+1;
		
		isVisited[cur.first][cur.second] = true;

		for (int i = 0; i < 4; i++)
		{
			//다음 위치로 이동
			int nextR = cur.first + rows[i];
			int nextC = cur.second + cols[i];

			if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= M || isVisited[nextR][nextC] || maze[nextR][nextC] == '0') continue;

			q.push({{ nextR,nextC }, cnt + 1});
		}
	}

	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;

	cin >> N >> M;

	vector<string> maze(N);

	for (int i = 0; i < N; i++)
	{
		cin >> maze[i];
	}

	int answer = bfs(N, M, maze);

	cout << answer << '\n';
}
/*
1 이동 가능
0 이동 불가능
지나야하는 최소 칸 수=>BFS
서로 인접한 칸만 이동 가능 row, col -1,1,0,0, 0,0,-1,1 만 이동 가능.
칸을 세어야하기 때문에 while문 도는 동안에 ++ 한 후 ret
갔던 칸 또 안가도록 방문처리 필수
*/