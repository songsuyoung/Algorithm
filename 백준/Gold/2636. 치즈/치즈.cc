#include <bits/stdc++.h>
using namespace std;

void bfs(int N, int M, vector<vector<int>>& arr, pair<int, int> st)
{
	
	vector<vector<bool>> isVisited(N,vector<bool>(M,0));
	int rows[4] = {-1,1,0,0};
	int cols[4] = {0,0,-1,1};

	queue<pair<int,int>> q;

	q.push(st);

	while (!q.empty())
	{
		pair<int,int> cur = q.front();
		q.pop();

		if(isVisited[cur.first][cur.second]) continue;

		isVisited[cur.first][cur.second] = true;

		for (int i = 0; i < 4; i++)
		{
			int nextR = cur.first+ rows[i];
			int nextC = cur.second + cols[i];

			if(nextR<0||nextC<0||nextR>=N||nextC>=M||isVisited[nextR][nextC]) continue;

			if (arr[nextR][nextC] == 1)
			{
				arr[nextR][nextC] = 2;
			}
			else if(arr[nextR][nextC] == 0)
			{
				q.push({nextR,nextC});
			}
		}
	}
}
bool CanLoop(vector<vector<int>>& arr, int N, int M,int &MaxValue)
{
	int cnt=0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1)
			{
				cnt++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1)
			{
				MaxValue = cnt;
				return true;
			}
		}
	}

	return false;
}
void MeltTheCheese(int N, int M, vector<vector<int>>& arr)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 2)
			{
				arr[i][j]=0; //치즈를 녹임.
			}
		}
	}
}
int main()
{
	int N,M;
	
	pair<int,int> answer(0,0);

	cin>>N>>M;

	vector<vector<int>> arr(N,vector<int>(M)); //겉면을 만들어줌.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin>>arr[i][j];
		}
	}

	while (true)
	{
		//끝났는지 확인.
		bool bIsLoop = CanLoop(arr, N, M, answer.second);
		if (bIsLoop == false)
		{
			break;
		}

		//BFS로 구멍 탐색
		bfs(N, M, arr, {0,0}); //겉면으로 탐색에 들어감 -> 이유 : 겉면은 항상 줄어들기 때문
		//0->1로 변하는 순간을 0으로 초기화

		answer.first++;

		MeltTheCheese(N, M, arr);

	}

	cout<<answer.first<<'\n'<<answer.second<<'\n';
}

/*
치즈가 놓여져 있음. 하나이상의 구멍이 있을 수 있음.
공기와 접촉된 칸은 한시간이 지나면 녹아 없어진다.

치즈가 아닌 곳에 사방면 치즈이면 녹임. => 상하 좌우

1. 구멍인 공간을 표시
	=> 공기 기준 => BFS 0은 갈 수 있는 곳 1은 체크 방식 
2. 체크된 공기 0으로 초기화

위 1,2 번 반복
*/