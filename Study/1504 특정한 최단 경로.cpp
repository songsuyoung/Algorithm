#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Compare
{
	bool operator()(pair<int,int> &a,pair<int,int> &b)
	{
		return a.second > b.second;
	}
};

int main()
{

	int N, E;
	cin >> N >> E;

	vector<vector<pair<int, int>>> v(N + 1);
	for (int i = 0; i < E; i++)
	{
		int v1, v2, c;
		cin >> v1 >> v2 >> c;
		v[v1].push_back(make_pair(v2, c));
		v[v2].push_back(make_pair(v1, c));
	}

	int v1, v2;
	cin >> v1 >> v2;
	
	vector<int> goDest1 = { 1,v1,v2,N };
	vector<int> goDest2 = { 1,v2,v1,N };

	int dist1 = 0,dist2=0;
	for (int i = 0; i < goDest1.size()-1; i++)
	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, Compare > q;
		q.push(make_pair(goDest1[i], 0));
		vector<int> distance(N + 1, INT_MAX);
		distance[goDest1[i]] = 0;
		vector<bool> isVisited(N + 1, false);

		while (!q.empty())
		{
			pair<int, int> cur = q.top();
			q.pop();

			if (isVisited[cur.first]) continue;
			isVisited[cur.first] = true;
			if (cur.first == goDest1[i + 1]) break;

			for (int i = 0; i < v[cur.first].size(); i++)
			{
				int next = v[cur.first][i].first;
				int nextDis = distance[cur.first] + v[cur.first][i].second;

				if (distance[next] > nextDis)
				{
					distance[next] = nextDis;
					q.push(make_pair(next, nextDis));
				}
			}
		}
		if (isVisited[goDest1[i + 1]]==false) {
			dist1 = INT_MAX;
			break;
		}
		dist1 += distance[goDest1[i + 1]];
	}
	
	//1->v1->v2->N 최단경로

	//1->v2->v1->N 최단 경로
	for (int i = 0; i < goDest2.size() - 1; i++)
	{

		priority_queue<pair<int, int>, vector<pair<int, int>>, Compare > q;

		q.push(make_pair(goDest2[i], 0));
		vector<int> distance(N + 1, INT_MAX);
		distance[goDest2[i]] = 0;
		vector<bool> isVisited(N + 1, false);

		while (!q.empty())
		{
			pair<int, int> cur = q.top();
			q.pop();

			if (isVisited[cur.first]) continue;
			isVisited[cur.first] = true;
			if (cur.first == goDest2[i + 1]) break;

			for (int i = 0; i < v[cur.first].size(); i++)
			{
				int next = v[cur.first][i].first;
				int nextDis = distance[cur.first] + v[cur.first][i].second;

				if (distance[next] > nextDis)
				{
					distance[next] = nextDis;
					q.push(make_pair(next, nextDis));
				}
			}
		}
		if (isVisited[goDest2[i + 1]] == false) {
			dist2 = INT_MAX;
			break;
		}
		dist2 += distance[goDest2[i + 1]];
	}

	int res = min(dist1, dist2);

	if (res == INT_MAX) cout << -1 << '\n';
	else 
		cout << min(dist1, dist2) << '\n';
}