#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Compare
{
	bool operator()(pair<int, int>& a, pair<int, int>& b)
	{
		//보석 가치가 큰 순으로 정렬
		return a.second <= b.second;
	}
};

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main()
{
	
	priority_queue<int, vector<int>, less<int>> q;
	vector<pair<int, int>> gem;
	vector<int> bags;

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int mi, vi;
		cin >> mi >> vi;
		gem.push_back(make_pair(mi, vi));
	}

	for (int i = 0; i < K; i++)
	{
		int ci;
		cin >> ci;

		bags.push_back(ci);
	}

	sort(bags.begin(), bags.end());
	sort(gem.begin(), gem.end(), compare);

	int idx = 0;
	long long sum = 0;

	for (int i = 0; i < bags.size(); i++)
	{

		while (idx < gem.size()&&bags[i] >= gem[idx].first)
		{
			q.push(gem[idx].second);
			idx++;
		}

		if (!q.empty())
		{
			sum += q.top();
			q.pop();
		}
	}

	cout << sum << '\n';
}