#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void print(int A[][101], int N)
{
	for(int i=0;i<N;i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool bfs(int N,int L,int R, int A[][101], bool isVisited[][101],pair<int,int> s)
{
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	q.push(s);

	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };
	int sum = 0;
	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();

		if (isVisited[p.first][p.second]) continue;

		isVisited[p.first][p.second] = true;
		v.push_back(p);
		sum += A[p.first][p.second];
		for (int i = 0; i < 4; i++)
		{
			int nextR = p.first + rows[i];
			int nextC = p.second + cols[i];

			if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= N) continue;
			
			int test = abs(A[p.first][p.second] - A[nextR][nextC]);

			if (test >= L && test <= R)
			{
				q.push(make_pair(nextR, nextC));
			}
		}
	}

	int cnt = sum / v.size();
	for (int i = 0; i < v.size(); i++)
	{
		A[v[i].first][v[i].second] = cnt;
	}
	if (v.size() != 1) return true;
	return false;
}
int main()
{
	int N, L, R;
	cin >> N >> L >> R;

	int A[101][101] = {};

	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}
	int day = 0;


	while (true)
	{
		bool isVisited[101][101] = {};
		bool isSuccess = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (isVisited[i][j]) continue;
				isSuccess |= bfs(N, L, R, A, isVisited, make_pair(i, j));
			}
		}
		if (isSuccess == false) break;
		day++;
	}
	cout << day << '\n';
}