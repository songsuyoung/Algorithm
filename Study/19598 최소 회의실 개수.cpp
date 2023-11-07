#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<pair<int, int>> times;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int st, en;
		cin >> st >> en;
		times.push_back(make_pair(st, en));
	}

	sort(times.begin(), times.end());

	int cnt = 1;

	priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> q;

	q.push(times[0]);
	pair<int, int> preTime=q.top();
	for (int i = 1; i < N; i++)
	{
		if (q.top().second<= times[i].first)
		{
			q.pop();
			q.push(times[i]);
			continue;
		}
		q.push(times[i]);
		cnt++;
	}

	cout << cnt << '\n';
}