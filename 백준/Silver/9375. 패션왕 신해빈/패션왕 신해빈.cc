#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;

	cin >> TC;

	for (int i = 0; i < TC; i++)
	{
		int N;
		cin >> N;

		unordered_map<string, int> garbs;

		for (int j = 0; j < N; j++)
		{
			string name, type;

			cin >> name >> type;

			garbs[type]++;
		}

		int total = 1;
		for (const auto& garb : garbs)
		{
			total *= (garb.second + 1);
		}
		total -= 1;

		cout << total << '\n';
	}


}
