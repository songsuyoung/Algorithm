#include <bits/stdc++.h>
using namespace std;

// N을 만나는지 확인용 인구 차
pair<int, int> BFS(vector<int>& cost, vector<vector<int>>& city, vector<int>& arr, int idx, int team)
{
	vector<bool> isVisited(11, false);

	queue<int> q;
	q.push(idx);

	int sum = 0;
	int cnt = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if(isVisited[cur]) continue;

		cnt++;
		sum += cost[cur];
		isVisited[cur] = true;

		for (int i = 0; i < city[cur].size(); i++)
		{
			int next = city[cur][i];

			if (isVisited[next] || arr[next] != team) continue;
			q.push(next);
		}
	}

	return { cnt, sum };
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin>>N;

	vector<int> cost(11, 0);

	for (int i = 1; i <= N; i++)
	{
		cin>>cost[i];
	}

	vector<vector<int>> city(N+1);

	for (int i = 1; i <= N; i++)
	{
		int cnt;
		cin>>cnt;
		for (int j = 0; j < cnt; j++)
		{
			int node;
			cin>>node;

			city[i].push_back(node);
			city[node].push_back(i);
		}
	}

	int answer = 987654321;
	//하나씩 선택해보는 것.
	for (int i = 1; i < (1 << N)-1; i++)
	{
		//색칠을 먼저한다.
		vector<int> arr(11, 0);

		//시작 위치 지정
		int idx1 = -1, idx2 = -1;
		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{
				//색칠
				arr[j+1] = true;
				idx1 = j+1;
			}
			else
			{
				idx2 = j+1;
			}
		}

		//BFS 를 돌린다. i기준으로 
		pair<int, int> p1 = BFS(cost, city, arr, idx1, 1);
		pair<int, int> p2 = BFS(cost, city, arr, idx2, 0);

		if (p1.first + p2.first == N)
		{
			//다 연결되어있음.
			answer = min(answer, abs(p1.second - p2.second));
		}
	}

	if (answer == 987654321)
	{
		answer = -1;
	}

	cout<<answer<<'\n';
}
