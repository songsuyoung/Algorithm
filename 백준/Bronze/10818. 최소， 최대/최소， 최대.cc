#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int minVal = INT_MAX, maxVal = INT_MIN;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;

		minVal = min(minVal, tmp);
		maxVal = max(maxVal, tmp);
	}

	cout << minVal << ' ' << maxVal << '\n';
}

