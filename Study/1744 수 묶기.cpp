#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> nums(N);
	for (int i = 0; i < N; i++)
		cin >> nums[i];

	sort(nums.begin(), nums.end());

	int idx = nums.size() - 1;
	int sum = 0;
	while (idx>=0&&nums[idx] > 0)
	{
		if (idx == 0)
		{
			sum += nums[idx--];
			continue;
		}
		int mul=nums[idx] * nums[idx - 1];

		if (mul >= nums[idx]+nums[idx - 1])
		{
			sum += mul;
			idx -= 2;
		}
		else
		{
			sum += nums[idx];
			idx--;
		}
	}
	//음수는 0이 가장 큰 값
	idx = 0;
	while (idx < nums.size() && nums[idx] <= 0)
	{
		if (idx == nums.size() - 1)
		{
			sum += nums[idx++];
			continue;
		}
		int mul = nums[idx] * nums[idx + 1];

		if (mul >= nums[idx]+nums[idx + 1])
		{
			sum += mul;
			idx += 2;
		}
		else
		{
			sum += nums[idx];
			idx++;
		}
	}
	cout << sum << '\n';
}