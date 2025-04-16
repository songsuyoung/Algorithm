#include <bits/stdc++.h>
using namespace std;

int BFS(int N, int M, vector<string>& map, vector<vector<bool>>& isVisited, pair<int, int> cur)
{

	queue<pair<int, pair<int,int>>> q;

	q.push({0, cur});

	int rows[] = {-1,1,0,0};
	int cols[] = {0,0,-1,1};

	int cnt = 0;
	while (!q.empty())
	{
		cnt = q.front().first;
		cur = q.front().second;

		q.pop();
		if(isVisited[cur.first][cur.second]) continue;
		
		isVisited[cur.first][cur.second] = true;

		for (int i = 0; i < 4; i++)
		{
			int nextR = cur.first + rows[i];
			int nextC = cur.second + cols[i];

			if(nextR<0||nextC<0||nextR>=N||nextC>=M||isVisited[nextR][nextC]||map[nextR][nextC]=='W') continue;

			q.push({cnt+1,{nextR,nextC}});
		}
	}

	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin>>N>>M;

	vector<string> map(N);

	// 50x50 => 2500 BFS(O^2)*2500 => 1 250 000
	vector<pair<int,int>> island;
	for (int i = 0; i < N; i++)
	{
		cin>>map[i];

		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 'L')
			{
				island.push_back({i,j});
			}
		}
	}

	//각 섬에서 갈 수 있는 최단 거리의 끝 점 찾기
	int maxtime = 0;
	for (int i = 0; i < island.size(); i++)
	{
		vector<vector<bool>> isVisisted(N, vector<bool>(M, false));
		maxtime = max(maxtime, BFS(N,M, map, isVisisted, island[i]));
	}

	cout<<maxtime<<'\n';
}
/*
직사각형 모양이며 여러 칸으로 나누어져 있음.
상하좌우로 이웃한 육지만 이동 가능 (한칸 이동 1시간)
보물은 서로 간에 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는 육지 두 곳에 묻어 있음. (A -> B A->C 전부 다 확인해봐야한다.)

각 섬의 BFS 돌려서 가장 Max 가지는 곳이 보물 섬/
*/