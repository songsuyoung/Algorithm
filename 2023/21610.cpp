#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//dfs 를 돌기 위해서 queue를 저장한다.
queue<pair<int, int>> moveAndrain(int N,vector<vector<int>> &arr, vector<pair<int, int>> & cloud,pair<int,int> command, vector<vector<bool>> &isRain)
{
	//command 1부터 시작하기 때문에 0번 idx에는 임의로 0 삽입
	int rows[9] = {0,0,-1,-1,-1,0,1,1,1};
	int cols[9] = {0,-1,-1,0,1,1,1,0,-1};

	queue<pair<int, int>> q;
	//vector에 저장된 n개의 구름이 di방향으로 si만큼 이동
	for (int i = 0; i < cloud.size(); i++)
	{
		//1-4 = -3
		//(현재 row + di*si) % (N+1)
		//(현재 col + di*si) % (N+1)
		//if row <= 0 : 
		//		N-abs(nextR)%N
		//if row >  N :
		//      nextR%N
		int nextStR = (cloud[i].first + (rows[command.first] * command.second));
		int nextStC = (cloud[i].second + (cols[command.first] * command.second));

		if (nextStR > N)
		{
			nextStR = nextStR % N;
		}
		if (nextStC > N)
		{
			nextStC = nextStC % N;
		}

		if (nextStR <= 0)
		{
			nextStR = N - abs(nextStR) % N;
		}
		if (nextStC <= 0)
		{
			nextStC = N - abs(nextStC) % N;
		}

		//각 구름에서 비가 내려서 구름이 있는 칸의 바구니에 비가 내림
		arr[nextStR][nextStC] += 1;
		isRain[nextStR][nextStC] = true;
		q.push(make_pair(nextStR, nextStC));
		//cout << cloud[i].first <<' '<<cloud[i].second<<' '<< nextStR << ' ' << nextStC << '\n';
	}

	return	q;
}

void increase(int N,vector<vector<int>> &arr,queue<pair<int,int>> &q)
{
	//command 사용하지 않기때문에 8로 경계선 잡음
	int rows[4] = { -1,-1,1,1 };
	int cols[4] = { -1,1,1,-1};
	
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		int cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			int nextR = cur.first + rows[i];
			int nextC = cur.second + cols[i];

			if (nextR <= 0 || nextC <= 0 || nextR > N || nextC > N || arr[nextR][nextC] == 0) continue;
			cnt++;
		}
		arr[cur.first][cur.second] += cnt;
	}

}

void createCloud(int N,vector<vector<int>> &arr,vector<vector<bool>> &isRain,vector<pair<int,int>> &cloud)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] >= 2 && isRain[i][j] == false)
			{
				isRain[i][j] = true;
				arr[i][j] -= 2;
				cloud.push_back(make_pair(i, j));
			}
		}
	}
}

void print(int N, vector<vector<int>>& arr)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

}
int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> arr(N+1, vector<int>(N+1, 0));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}
	//   N-1,1(s) N-1,2
	//   N,1       N,2(e)
	//
	vector<pair<int,int>> c={make_pair(N - 1,1),make_pair(N,2),make_pair(N,1),make_pair(N-1,2) };
	
	for (int i = 0; i < M; i++)
	{
		vector<vector<bool>> isRain(N + 1, vector<bool>(N + 1, 0));
		int di, si;
		cin >> di >> si;
		//di방향으로 si만큼 이동
		//1,2 모든 구름이 di방향으로 si칸 만큼 이동 + 비내림
		queue<pair<int,int>> q=moveAndrain(N,arr,c,make_pair(di,si), isRain);
		//3 구름이 모두 사라짐 
		c.clear();
		//4 물이 증가한 칸(r,c)에 물복사버그 마법을 수행, 대각선 방향 거리 1인칸 물있는 만큼 양 증가
		increase(N,arr,q);
		//5 구름이 있던 칸을 제외한 나머지 칸 중 물의 양이 2 이상인 곳...물이 2씩 줄어들고 구름이 생긴다.
		createCloud(N,arr,isRain,c);
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			answer += arr[i][j];
		}
	}

	cout << answer << '\n';

}