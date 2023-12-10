#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

struct Compare {

	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.second > b.second;
	}
};
int main()
{
	int N, M;
	cin >> N >> M;
	
	vector<vector<pair<int, int>>> bus(N+1);

	for (int i = 0; i < M; i++)
	{
		int n1, n2, w;
		cin >> n1 >> n2 >> w;
		bus[n1].push_back(make_pair(n2, w));
	}

	int A, B;
	cin >> A >> B;

	vector<int> distance(N + 1, INT_MAX);
	distance[A] = 0;
	vector<bool> isVisited(N + 1, false);

	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
	q.push(make_pair(A, distance[A]));
	while (!q.empty())
	{
		int cur = q.top().first;
		int dist = q.top().second;

		q.pop();
		if (isVisited[cur]) continue;
		if (cur == B) {
			cout << dist << '\n';
			break;
		}
		isVisited[cur] = true;

		for (int i = 0; i < bus[cur].size(); i++)
		{
			int next = bus[cur][i].first;
			int nextDist = dist + bus[cur][i].second;

			if (distance[next] > nextDist)
			{
				distance[next] = nextDist;
				q.push(make_pair(next, nextDist));
			}
		}
	}
}