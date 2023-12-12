#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int arr[101][101] = {};
	
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin>>arr[i][j];
		}
	}
	int adjacent[101][101] = {};
	for (int i = 0; i < N; i++)
	{
		priority_queue<int, vector<int>, greater<int>> q;
		bool isVisited[101] = {};
		q.push(i);
		while (!q.empty())
		{
			int node = q.top();
			q.pop();

			if (isVisited[node]) continue;
			isVisited[node] = true;
			for (int j = 0; j < N; j++)
			{
				if (arr[node][j] != 1) continue;

				q.push(j);
				adjacent[i][j] = 1;

			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << adjacent[i][j] << ' ';
		}
		cout << '\n';
	}

}