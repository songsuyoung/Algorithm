/*
한 정점에서 다른 정점으로 가는 최단 경로에서 가중치가 있고, 음수가 없다면 다익스트라를 생각한다.
하지만, 모든 정점에서 가는 경로를 찾을 때에는 플로이드 워샬을 생각해야한다.
*/

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
using ll = long long;

struct Compare
{
	bool operator()(pair<int, ll>& a, pair<int, ll>& b)
	{
		return a.second > b.second;
	}
};
void dijkstra(int source, int dest, vector<vector<pair<int, int>>>& vertices)
{
	vector<int> distance(vertices.size(), INT_MAX); //weight 가중치가 10
	
	priority_queue<pair<int, ll>, vector<pair<int, ll>>, Compare> q;

	q.push(make_pair(source, 0));
	distance[source] = 0;
	while (!q.empty())
	{
		pair<int, ll> cur = q.top();
		q.pop();

		if (cur.second > distance[cur.first]) continue;

		for (int i = 0; i < vertices[cur.first].size(); i++)
		{
			int next = vertices[cur.first][i].first;
			ll nextDist = cur.second + vertices[cur.first][i].second;

			if (nextDist < distance[next])
			{
				distance[next] = nextDist;
				q.push(make_pair(next, nextDist));
			}
		}
	}

	for (int i = 1; i < distance.size(); i++)
	{
		if (distance[i] == INT_MAX)
			cout << "INF" << '\n';
		else
			cout << distance[i] << '\n';
	}

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int V, E;
	cin >> V >> E;

	int K;
	cin >> K;

	vector<vector<pair<int, int>>> vertices(V+1);
	for (int i = 0; i < E; i++)
	{
		int n1, n2, w;
		cin >> n1 >> n2 >> w;
		vertices[n1].push_back(make_pair(n2, w));
	}

	dijkstra(K,V,vertices);
}