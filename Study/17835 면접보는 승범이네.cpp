/*
다익스트라 알고리즘을 풀 때 목적지를 시작점으로 생각하고, 역리스트를 구상한다.
역리스트를 구상하고, 가야할 목적지를 queue에 삽입한 후 가까운 거리만 선택한다면
최선의 거리를 찾을 수 있다.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Compare
{
	bool operator()(pair<long long, long long>& a,pair<long long, long long>& b)
	{
		return a.second > b.second;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<pair<long long, long long>>> cities(N+1);

	for (int i = 0; i < M; i++)
	{
		//n1->n2 가는 것,
		//출발지 K목적지에 도달하기 위해서, n2->n1 으로 함
		long long n1, n2, w;
		cin >> n1 >> n2 >> w;
		cities[n2].push_back(make_pair(n1,w));
	}

	priority_queue < pair<long long, long long>, vector<pair<long long, long long>>, Compare> q;
	vector<long long> distance(N + 1, LLONG_MAX);
	vector<bool> isVisited(N + 1, false);

	for (int i = 0; i < K; i++)
	{
		long long n1;
		cin >> n1;
		q.push(make_pair(n1, 0));
		distance[n1] = 0;
	}

	while (!q.empty())
	{
		long long idx = q.top().first;
		long long dist = q.top().second;
		q.pop();

		if (isVisited[idx]) continue;

		isVisited[idx] = true;

		for (int j = 0; j < cities[idx].size(); j++)
		{
			long long next = cities[idx][j].first;
			long long nextDist = dist + cities[idx][j].second;

			if (distance[next] > nextDist)
			{
				distance[next] = nextDist;
				q.push(make_pair(next, nextDist));
			}
		}
	}
	
	pair<long long, long long> res=make_pair(0,0);
	for (int i = 1; i <= N; i++) {
		if (res.second < distance[i])
		{
			res.second = distance[i];
			res.first = i;
		}
	}
	
	cout << res.first<<'\n'<<res.second << '\n';
}