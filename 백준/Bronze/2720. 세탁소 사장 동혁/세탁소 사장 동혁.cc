#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> coins = { 25,10, 5, 1 };

	int TC;
	cin >> TC;

	for (int tc = 0; tc < TC; tc++)
	{
		int coin;
		cin >> coin;

		for (int i = 0; i < coins.size(); i++)
		{
			int cnt = coin / coins[i];
			cout << cnt << ' ';

			coin = coin - coins[i] * cnt;
		}
		cout << '\n';
	}
}

/*
0.25 개수, 0.10의 개수, 0.05 개수, 0.01 개수


*/
