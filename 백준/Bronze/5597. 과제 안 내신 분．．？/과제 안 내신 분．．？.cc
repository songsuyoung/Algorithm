#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<bool> isVisited(31, 0);
	for (int i = 0; i < 28; i++)
	{
		int idx;
		cin >> idx;

		isVisited[idx] = true;
	}

	for (int i = 1; i <= 30; i++)
	{
		if (isVisited[i] == false)
		{
			cout << i << '\n';
		}
	}
}

