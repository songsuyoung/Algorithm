//16분 걸림 골드 5 1374_priority_queue 사용
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool compare(pair<long long, long long>& roomA, pair<long long, long long>& roomB)
{
	if (roomA.first == roomB.first)
	{
		return roomA.second < roomB.second;
	}
	return roomA.first < roomB.first;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;

	vector<pair<long long, long long>> rooms;

	for (int i = 0; i < N; i++)
	{
		long long id, st, ed;
		cin >> id >> st >> ed;

		rooms.push_back(make_pair(st, ed));
	}

	sort(rooms.begin(), rooms.end(), compare);
	priority_queue<long long,vector<long long>,greater<long long>> pq;

	for (int i = 0; i < rooms.size(); i++)
	{
		if (!pq.empty() && pq.top() <= rooms[i].first)
		{
			pq.pop();
		}
		pq.push(rooms[i].second);
	}

	cout << pq.size() << '\n';
}