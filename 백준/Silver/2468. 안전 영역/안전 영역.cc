#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<bool>>& isVisisted, vector<vector<int>>& arr, int depth, pair<int, int> start)
{
	queue<pair<int,int>> q;

	int rows[4] = {-1,1,0,0};
	int cols[4] = {0,0,-1,1};

	q.push(start);

	while (!q.empty())
	{
		pair<int,int> cur =q.front();

		q.pop();

		if(isVisisted[cur.first][cur.second]) continue;

		isVisisted[cur.first][cur.second] = true;

		for (int i = 0; i < 4; i++)
		{
			int nextR = cur.first + rows[i];
			int nextC = cur.second + cols[i];

			if(nextR<0||nextC<0||nextR>=arr.size()||nextC>=arr.size()||isVisisted[nextR][nextC]||arr[nextR][nextC]<=depth) continue;

			q.push({nextR,nextC});
		}
	}
}

void print(vector<vector<bool>>& isVisisted)
{
	for (int i = 0; i < isVisisted.size(); i++)
	{
		for (int j = 0; j < isVisisted.size(); j++)
		{
			cout<<isVisisted[i][j]<<' ';
		}
		cout<<'\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	cin>>N;

	vector<vector<int>> arr(N, vector<int>(N));

	int depth = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin>>arr[i][j];

			depth = max(depth, arr[i][j]);
		}
	}

	int maxVal = 0;
	for (int i = 0; i <= depth; i++)
	{
		vector<vector<bool>> isVisited(N, vector<bool>(N, false));

		int cnt=0;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if(isVisited[j][k] || arr[j][k] <= i) continue;

				bfs(isVisited, arr, i, {j,k});
				cnt++;

			}
		}
		maxVal = max(maxVal, cnt);
	}

	cout<< maxVal <<'\n';
	return 0;
}

/*
어떤 지역의 높이 정보를 파악
그 지역에 많은 비가 내렸을 때 물에 잠기지 않는 안전한 영역이 최대로 몇 개가 만들어지는 지를 조사

장마철에 내리는 비의 양에 다라 일정한 높이 이하의 모든 지역은 물에 잠긴다고 가정.

예)

6 8 2 6 2
3 2 3 4 6
6 7 3 3 2
7 2 5 3 6
8 9 5 2 7

만약, 비가 내려서 높이 4이하인 지역은 전부 잠겼다 => 잠김 표시 -1

6 8 -1 6 -1
-1 -1 -1 -1 6
6 7 -1 -1 -1
7 -1 5 -1 6
8 9 5 -1 7

물에 잠기지 않은 안전한 영역이라면, 물에 잠기지 않는 지점들이 위 아래 오른쪽 혹은 왼쪽으로 인접해 있는 크기의 최대 영역
즉 하나라도 물에 안잠긴 영역이 있으면 된다.

3이하일 때
6 8 -1 6 -1
-1 -1 -1 4 6
6 7 -1 -1 -1
7 -1 5 -1 6
8 9 5 -1 7

=>5개
2이하일 때
6 8 -1 6 -1
3 -1 3 4 6
6 7 3 3 -1
7 -1 5 3 6
8 9 5 -1 7

1부터 최대 크기 까지 N 비 내리고, 방문 처리를 통해서 BFS를 몇번 도는지를 확인한다.
BFS가 작아지는 시점에서 break를 하고, 언제가 최대인지를 출력한다.
*/