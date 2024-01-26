#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
	int N, E;
	cin >> N >> E;

	vector<vector<ll>> edges(N + 1, vector<ll>(N + 1, INT_MAX));

	for (int i = 0; i < E; i++)
	{
		int node1, node2, cost;
		cin >> node1 >> node2 >> cost;
		
		if(edges[node1][node2] > cost)
			edges[node1][node2] = cost;
	}

	for (int i = 1; i <=N; i++)
	{
		edges[i][i] = 0;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				//단방향이기 때문에 두 방향으로 계산을 해야함.
				edges[j][k] = min(edges[j][k], edges[j][i] + edges[i][k]);
			}
		}
	}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (edges[i][j] == INT_MAX)
				cout << 0 << ' ';
			else
				cout << edges[i][j] << ' ';
		}
		cout << '\n';
	}
}