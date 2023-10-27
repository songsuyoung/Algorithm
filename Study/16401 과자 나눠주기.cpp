#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int isDividing(int len, vector<int>& snack)
{
	int cnt = 0;
	for (int i = 0; i < snack.size(); i++)
	{
		if ((snack[i] - len) >= 0)
		{
			cnt += (snack[i]/ len);
		}
	}
	return cnt;

}
int main() {


	int M, N;
	vector<int> snack;
	
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		snack.push_back(tmp);
	}

	sort(snack.begin(), snack.end());

	int left = 1;
	int right = snack[N - 1];
	int result = 0;

	while (left <= right)
	{
		long long mid = (left + right) / 2;

		if (isDividing(mid, snack)>=M)
		{
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << result << '\n';
}