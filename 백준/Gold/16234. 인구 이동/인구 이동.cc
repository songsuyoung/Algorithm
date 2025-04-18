#include <bits/stdc++.h>
using namespace std;

struct country
{
	int person;
	int row;
	int col;
};
vector<country> BFS(int N, int L, int R, vector<vector<int>>& countries, vector<vector<bool>>& isVisited, pair<int,int> st)
{
	int rows[4] = {-1,1,0,0};
	int cols[4] = {0,0,-1,1};

	queue<pair<int,int>> q;

	q.push(st);

	vector<country> federation;

	while (!q.empty())
	{
		pair<int,int> cur = q.front();

		q.pop();

		if(isVisited[cur.first][cur.second]) continue;

		isVisited[cur.first][cur.second]=true;
		federation.push_back({countries[cur.first][cur.second],cur.first,cur.second});

		for (int i = 0; i < 4; i++)
		{
			int nextR = cur.first + rows[i];
			int nextC = cur.second + cols[i];

			if(nextR<0||nextC<0||nextR>=N||nextC>=N||isVisited[nextR][nextC]) continue;

			int distance = abs(countries[cur.first][cur.second] - countries[nextR][nextC]);

			if (L <= distance && R >= distance)
			{
				q.push({nextR, nextC});
			}
		}
	}
	
	return federation;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, L, R;

	cin>>N>>L>>R;

	vector<vector<int>> countries(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin>>countries[i][j];
		}
	}

	int answer = 0;
	while(true)
	{
		vector<vector<country>> federations;
		vector<vector<bool>> isVisited(N, vector<bool>(N, 0));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (isVisited[i][j]) continue;

				vector<country> federation = BFS(N, L, R, countries, isVisited, { i,j });

				if (federation.size() > 1) //1개 밖에 없으면 본인 자신이기 때문...
				{
					federations.push_back(federation);
				}
			}
		}

		if (federations.empty()) 
		{
			break;
		}
		answer++;
		for (int i = 0; i < federations.size(); i++)
		{
			int average = 0;
			for (int j = 0; j < federations[i].size(); j++)
			{
				average += federations[i][j].person;
			}
			average /= federations[i].size();

			for (int j = 0; j < federations[i].size(); j++)
			{
				countries[federations[i][j].row][federations[i][j].col] = average;
			}
		}
	}

	cout<< answer<<'\n';
}


/*
1x1 칸으로 이루어져 있고, 각 나라의 A[r][c]명이 살 ㅅ고 있음.

1. 인구 차(상하좌우)를 k라고 할 때, L<=k<=R 이면, 국경선을 하루동안 연다.
	2. 인구 이동
	3. (연합의 인구수(국경선이 열려있는 나라들 끼리의 합 A1[r][c] + A2[r][c])/(연합을 이루는 칸의 개수) => 소수점 버림 즉, int

위 반복

예를 들어,

L:20 R:50

50 30
20 40

첫날 

연합
50-30
20

1. 1에 대해서 상하좌우 인구 차 확인 => 만약 OK라면 true/true로 만든다. => BFS로 넘어가자, 안된다면 방문 노노 => 애초에 원본 값을 더함
2. 원본값을 /bool의 개수로 나눔
3. bool 변수에 각 값을 리셋 시켜줌.

*/