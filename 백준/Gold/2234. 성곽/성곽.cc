#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int rows[4] = {0,-1,0,1};
int cols[4] = {-1,0,1,0};

int DFS(vector<vector<int>>& wall, vector<vector<bool>>& isVisited, pair<int, int> st)
{
	isVisited[st.first][st.second] = true;
	int answer = 0; //자기자신

	for (int i = 0; i < 4; i++)
	{
		int nextR = rows[i] + st.first;
		int nextC = cols[i] + st.second;

		if(nextR<0||nextC<0||nextR>=wall.size()||nextC>=wall[0].size()||isVisited[nextR][nextC]) continue;

		if (0 == (wall[st.first][st.second] & (1 << i)))
		{
			//cout<<st.first<<' '<<st.second<<' '<<wall[st.first][st.second]<<' '<<i<<'\n';
			//dir으로 이동가능
			answer += DFS(wall, isVisited, {nextR, nextC}) + 1;
		}
	}

	return answer;
}

//벽을 뚫는다.
int break_wall(int N, int M, vector<vector<int>>& wall)
{
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if(0 == (wall[i][j] & (1<<k))) continue; //벽이 아닐때는 그냥 넘어간다.
				//벽을 뚫는 코드

				wall[i][j] &= ~(1<<k); //벽을 뚫는다.

				vector<vector<bool>> isVisited(wall.size(), vector<bool>(wall[0].size(), 0));

				for (int p = 0; p < N; p++)
				{
					for (int q = 0; q < M; q++)
					{
						answer = max(answer, DFS(wall, isVisited, {p,q}));
					}
				}

				wall[i][j] |= (1<<k); //벽을 복구한다.
			}
		}
	}

	return answer + 1;
}
int main()
{

	int N, M;
	cin>>N>>M;

	vector<vector<int>> wall(M, vector<int>(N, 0));
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin>>wall[i][j];
		}
	}

	vector<int> answer(3, 0);

	vector<vector<bool>> isVisited(M, vector<bool>(N, 0));
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if(isVisited[i][j]) continue;

			answer[1] = max(answer[1], DFS(wall, isVisited, {i, j}));

			answer[0]++;
		}
	}
	
	answer[1] += 1;

	//벽을 뚫는 로직

	answer[2] = break_wall(M, N, wall);

	for (int i = 0; i < answer.size(); i++)
	{
		cout<<answer[i]<<'\n';
	}
}

/*
성곽
굵은 선은 벽/ 점선은 통로
1. 이 성에 있는 방의 개수 (BFS나 DFS로 지나갈 수 있는 경로 끝 +1)
2. 가장 넓은 방의 넓이 (한바퀴 돌아서 나온 값)
3. 하나의 벽을 제거하고 얻을 수 있는 가장 넓은 방의 크기 (벽일 때 벽제거 하는 알고리즘)


서쪽의 벽 1, 북쪽의 벽 2, 동쪽의 벽 4, 남쪽에 벽 8

1+2+4+8 => 최대 33 (모두 꽉막힘?)
1 2 8 -> 서쪽 북쪽 남쪽 => 동쪽으로 이동 

모든 방을 가긴 해야하는데, bool 변수로 방문 여부 확인하고,

0 == (N & (1<<1)) => 서쪽 이동 가능

0 == (N & (1<<2)) => 북쪽 이동 가능

0 == (N & (1<<4)) => 동쪽 이동 가능

0 == (N & (1<<8)) => 북쪽 이동 가능


//벽을 하나 뚫어보고, BFS => BFS 로직 (가장 넓은 방의 넓이)
//벽을 하나 뚫어보고, BFS 

벽 뚫는 로직

answer
for(int i=0; i<N; i++)
{
	for(int j=0; j<M; j++)
	{
		for(int k=1; k<=8; k<<=1)
		{
			if(arr[i][j] == (N&k))
			{
				answer = max(answer, BFS())
			}
		}
	}
}
=> answer값 가져오기

*/