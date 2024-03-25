#include <iostream>
#include <vector>
using namespace std;

int dp[2][3][2] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<short> arr(3, 0);

	short dpIdx = 0;

	int maxVal = -1, minVal = INT_MAX;

	for (int i = 0; i < N; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			cin >> arr[j];

			if (i == 0)
			{
				dp[dpIdx][j][0] = arr[j];
				dp[dpIdx][j][1] = arr[j];
			}
		}

		if (i == 0)
		{
			continue;
		}

		for (short j = 0; j < 3; j++)
		{
			maxVal = -1;
			minVal = INT_MAX;

			if ((j - 1) >= 0)
			{
				minVal = min(minVal, dp[dpIdx % 2][j - 1][0] + arr[j]);
				maxVal = max(maxVal, dp[dpIdx % 2][j - 1][1] + arr[j]);
			}

			minVal = min(minVal, dp[dpIdx % 2][j][0] + arr[j]);
			maxVal = max(maxVal, dp[dpIdx % 2][j][1] + arr[j]);

			if ((j + 1) < 3)
			{
				minVal = min(minVal, dp[dpIdx % 2][j + 1][0] + arr[j]);
				maxVal = max(maxVal, dp[dpIdx % 2][j + 1][1] + arr[j]);
			}

			dp[(dpIdx + 1) % 2][j][0] = minVal;
			dp[(dpIdx + 1) % 2][j][1] = maxVal;

		}

		dpIdx = (dpIdx + 1) % 2;

	}

	maxVal = -1;
	minVal = INT_MAX;

	for (short i = 0; i < 3; i++)
	{
		minVal = min(minVal, dp[dpIdx][i][0]);
		maxVal = max(maxVal, dp[dpIdx][i][1]);
	}

	cout << maxVal << ' ' << minVal << '\n';

}