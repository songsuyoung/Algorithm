#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

void bfs(int N,int arr[][101],bool isVisited[][101],int min,pair<int,int> start)
{
	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };

	queue<pair<int,int>> q;
	
	q.push(start);
	while (!q.empty())
	{
		pair<int, int> pos = q.front();
		q.pop();
		if (isVisited[pos.first][pos.second]) continue;

		isVisited[pos.first][pos.second] = true;
		for (int i = 0; i < 4; i++)
		{
			int nextR = pos.first + rows[i];
			int nextC = pos.second + cols[i];

			if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= N || isVisited[nextR][nextC] || arr[nextR][nextC] <= min) continue;
			
			q.push(make_pair(nextR, nextC));		
		}
	}
}
int main()
{
	int N;
	cin >> N;

	int arr[101][101] = {};
	int maxHeight = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] > maxHeight)
				maxHeight = arr[i][j];
		}
	}

	int maxCnt = 0;
	for(int minHeight=0;minHeight<=maxHeight;minHeight++)
	{
		int cnt = 0;
		bool isVisited[101][101] = {};
		
		//최소값 찾는다.
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (isVisited[i][j]||arr[i][j]<=minHeight) continue;
				bfs(N, arr, isVisited, minHeight,make_pair(i,j));
				cnt++;
			}
		}
		if (cnt >= maxCnt)
			maxCnt = cnt;
	}

	cout << maxCnt << '\n';
}