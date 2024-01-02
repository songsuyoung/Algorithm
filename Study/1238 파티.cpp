#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Compare
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.second > b.second;
	}
};
int dijkstra(int N,vector<vector<pair<int,int>>> &roads, int start, int end)
{

	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	vector<bool> isVisited(N + 1, false);
	vector<int> distance(N + 1, INT_MAX);

	pq.push(make_pair(start, 0));
	distance[start] = 0;

	while (!pq.empty())
	{
		pair<int, int> cur = pq.top();
		pq.pop();

		if (cur.first == end) return cur.second;

		if (isVisited[cur.first]) continue;
		isVisited[cur.first] = true;

		for (int i = 0; i < roads[cur.first].size(); i++)
		{
			int next = roads[cur.first][i].first;
			int nextDist = roads[cur.first][i].second + cur.second;

			if (distance[next] > nextDist)
			{
				distance[next] = nextDist;
				pq.push(make_pair(next, nextDist));
			}
		}
	}
	return 0;
}
int main()
{
	int N, M, X;
	cin >> N >> M >> X;

	vector<vector<pair<int,int>>> roads(N + 1);
	for (int i = 0; i < M; i++)
	{
		int n1, n2, dist;
		cin >> n1 >> n2 >> dist;

		//단방향
		roads[n1].push_back(make_pair(n2,dist));
	}

	int maxDist = 0;

	for (int i = 1; i <= N; i++)
	{
		int distance = dijkstra(N,roads,i, X) + dijkstra(N,roads,X, i);
		
		if (maxDist < distance)
		{
			maxDist = distance;
		}
	}

	cout << maxDist << '\n';
}