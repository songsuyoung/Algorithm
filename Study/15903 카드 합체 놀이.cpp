#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<ll, vector<ll>,greater<ll>> pq;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int card;
		cin >> card;
		pq.push(card);
	}

	for (int i = 0; i < m; i++)
	{

		ll card1 = pq.top();
		pq.pop();
		ll card2 = pq.top();
		pq.pop();

		ll card3=card1 + card2;

		pq.push(card3);
		pq.push(card3);
	}

	ll sum = 0;
	while (!pq.empty())
	{
		sum += pq.top();
		pq.pop();
	}

	cout << sum << '\n';
}