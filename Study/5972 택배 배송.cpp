#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Compare
{
	bool operator()(pair<int, int>& a, pair<int, int>& b)
	{
		return a.second > b.second;
	}
};
long long dijkstra(vector<vector<pair<int, int>>> &roads,int N)
{
	vector<bool> isVisited(N+1,false);
	vector<long long> distance(N + 1, INT_MAX);
	priority_queue<pair<int, int>,vector<pair<int,int>>,Compare> q;
	
	q.push(make_pair(N, 0));
	distance[N] = 0;
	while (!q.empty())
	{
		pair<int, int> cur = q.top();
		q.pop();

		if (isVisited[cur.first]) continue;

		if (cur.first == 1) break;
		isVisited[cur.first] = true;
		for (int i = 0; i < roads[cur.first].size(); i++)
		{
			int next = roads[cur.first][i].first;
			int nextDist = distance[cur.first] + roads[cur.first][i].second;

			if (distance[next] > nextDist)
			{
				distance[next] = nextDist;
				q.push(make_pair(next, nextDist));
			}
		}
	}


	return distance[1];

}
int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<pair<int, int>>> roads(N+1);
	for (int i = 0; i < M; i++)
	{
		int A_i, B_i, C_i;
		cin >> A_i >> B_i >> C_i;

		//양방향
		roads[A_i].push_back(make_pair(B_i, C_i));
		roads[B_i].push_back(make_pair(A_i, C_i));
	}

	cout<<dijkstra(roads,N);
}