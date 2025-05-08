#include <bits/stdc++.h>
using namespace std;

int BFS(int N, int K)
{
	queue<int> q;
	vector<int> isVisited(100'005, 987654321);

	q.push(N);
	isVisited[N] = 0;
	while (!q.empty())
	{
		int cur = q.front();

		q.pop();

		if (cur == K)
		{
			return isVisited[K];
		}

		for (int next : {cur + 1, cur - 1, cur * 2})
		{
			if (next < 0 || next>100'000)
			{
				continue;
			}

			if (isVisited[cur] + 1 < isVisited[next])
			{
				q.push(next);
				isVisited[next] = isVisited[cur] + 1;
			}
		}
	}

	return -1;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N, K;
	cin>>N>>K;

	cout << BFS(N, K) << '\n';

}