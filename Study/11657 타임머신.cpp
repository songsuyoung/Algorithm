#include <bits/stdc++.h>
using namespace std;
//음수 간선을 가지고, 최단 경로를 찾음 => 벨만 포드 알고리즘?


int main()
{
	int N, M;

	cin >> N >> M;

	vector<vector<pair<int,int>>> v(N + 1);
	vector<long long> distance(N + 1, 1e15);
	
	for (int i = 0; i < M; i++)
	{
		int n1, n2, cost;
		cin >> n1 >> n2 >> cost;
		
		v[n1].push_back(make_pair(n2, cost)); //단방향 그래프 
	}
	distance[1] = 0;
	//출발 노드 1 N-1번 순환이 가능, 건널 수 있는 edge 개수

	if (!v[1].empty())
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++) //노드에 대해 가는 길
			{
				for (int k = 0; k < v[j].size(); k++)
				{
					if (distance[v[j][k].first] > distance[j] + v[j][k].second)
					{
						if (i == N) //시간을 무한히 사용가능...
						{
							cout << "-1";
							exit(0);
						}
						distance[v[j][k].first] = distance[j] + v[j][k].second;
					}
				}
			}
		}

	}

	for(int i=2;i<=N;i++)
	{
		if (distance[i] == 1e15)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << distance[i] << '\n';
		}
	}
}