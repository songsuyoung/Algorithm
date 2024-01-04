/*
	해당 문제 : 플로이드 워샬
	why? 운동을 한 후에는 다시 시작점으로 돌아오는 것이 좋기 때문에, 
	우리는 사이클을 찾기를 원한다.
	 
	=> 모든 경로의 distacne 를 알아야지 (왕복의 최솟값을 알 수 있음 !)
*/

#include <iostream>
#include <vector>
#include <climits>
using ll = long long;
using namespace std;

int main()
{
	int V, E;
	cin >> V >> E;

	//거리가 10,000이하면,,, 다 더했을 때 10,000이 나올 수 있음...
	//400*100 000 =>4000 000 000
	vector < vector < ll >> distance(V + 1, vector<ll>(V + 1, INT_MAX));
	for (int i = 0; i < E; i++)
	{
		int n1, n2;
		ll dist;
		cin >> n1 >> n2 >> dist;

		distance[n1][n2] = dist; //일반 통행
	}

	for (int i = 1; i <= V; i++)
	{
		distance[i][i] = 0; //자기 자신으로 가는 통행로는 0
	}

	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			for (int k = 1; k <= V; k++)
			{
				distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
			}
		}
	}
	ll minVal = INT_MAX;
	for (int i = 1; i <= V; i++)
	{
		for (int j = i + 1; j <= V; j++)
		{
			if (distance[i][j] == INT_MAX || distance[i][j] == INT_MAX)
				continue;

			minVal = min(minVal,distance[i][j] + distance[j][i]);
		}
	}

	if (minVal == INT_MAX) cout << -1 << '\n';
	else
		cout << minVal << '\n';
}