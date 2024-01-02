//bfs로 푼 이유 가장 가까운 거리에 있는 노드 중 가까운 값 리턴을 위해서
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(int N,vector<vector<int>> &trees,int start,int end)
{

	queue<pair<int, int>> q;
	vector<bool> isVisited(N + 1, false);
	q.push(make_pair(start, 0));

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		if (cur.first == end) return cur.second;
		if (isVisited[cur.first]) continue;
		isVisited[cur.first] = true;

		for (int i = 0; i < trees[cur.first].size(); i++)
		{
			if (trees[cur.first][i] == 0) continue;
			q.push(make_pair(i, cur.second + trees[cur.first][i]));
		}
	}
	return 0;
}
int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> trees(N+1,vector<int>(N+1,0));
	for (int i = 0; i < N - 1; i++)
	{
		int n1, n2, dis;
		cin >> n1 >> n2 >> dis;

		trees[n1][n2] = dis;
		trees[n2][n1] = dis;
	}
	for (int i = 0; i < M; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;

		cout << bfs(N,trees, n1, n2) << '\n';
	}
}